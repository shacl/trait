#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

#include <string>

struct Fn {
  void operator()(int) const {}
  virtual void call(int) const {}
  int field;
  virtual ~Fn() = default;
};

struct Child : Fn {
  void call(int) const override {}
};

struct Gn {
  void call(int) const {}
};

void fn(int){}

SCENARIO("InvokeDefined"){
  GIVEN("a free function"){
    GIVEN("a compatible argument"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(fn), int>;
      REQUIRE(invocable);
    }
    GIVEN("an incompatible argument"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(fn), std::string>;
      REQUIRE(not invocable);
    }
  }
  GIVEN("a callable struct"){
    GIVEN("a compatible argument"){
      constexpr bool invocable = shacl::trait::InvokeDefined_v<Fn&, int>;
      REQUIRE(invocable);
    }
    GIVEN("an incompatible argument"){
      constexpr bool invocable = shacl::trait::InvokeDefined_v<Fn&, std::string>;
      REQUIRE(not invocable);
    }
  }
  GIVEN("a member function pointer"){
    auto call = &Fn::call;
    GIVEN("a class reference"){
      GIVEN("a compatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Fn&, int>;
        REQUIRE(invocable);
      }
      GIVEN("an incompatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Fn&, std::string>;
        REQUIRE(not invocable);
      }
    }
    GIVEN("a class pointer"){
      GIVEN("a compatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Fn*, int>;
        REQUIRE(invocable);
      }
      GIVEN("an incompatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Fn*, std::string>;
        REQUIRE(not invocable);
      }
    }
    GIVEN("a class reference_wrapper"){
      GIVEN("a compatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v
          <decltype(call), std::reference_wrapper<Fn>, int>;
        REQUIRE(invocable);
      }
      GIVEN("an incompatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v
          <decltype(call), std::reference_wrapper<Fn>, std::string>;
        REQUIRE(not invocable);
      }
    }
    GIVEN("a child class reference"){
      GIVEN("a compatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Child&, int>;
        REQUIRE(invocable);
      }
      GIVEN("an incompatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Child&, std::string>;
        REQUIRE(not invocable);
      }
    }
    GIVEN("a child class pointer"){
      GIVEN("a compatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Child*, int>;
        REQUIRE(invocable);
      }
      GIVEN("an incompatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v<decltype(call), Child*, std::string>;
        REQUIRE(not invocable);
      }
    }
    GIVEN("a child class reference_wrapper"){
      GIVEN("a compatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v
          <decltype(call), std::reference_wrapper<Child>, int>;
        REQUIRE(invocable);
      }
      GIVEN("an incompatible argument"){
        constexpr bool invocable =
          shacl::trait::InvokeDefined_v
          <decltype(call), std::reference_wrapper<Child>, std::string>;
        REQUIRE(not invocable);
      }
    }
    GIVEN("an unrelated class reference"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(call), Gn&, int>;
      REQUIRE(not invocable);
    }
    GIVEN("an unrelated class pointer"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(call), Gn*, int>;
      REQUIRE(not invocable);
    }
    GIVEN("an unrelated class reference_wrapper"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v
        <decltype(call), std::reference_wrapper<Gn>, int>;
      REQUIRE(not invocable);
    }
  }
  GIVEN("a member object pointer"){
    auto field = &Fn::field;
    GIVEN("a class reference"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(field), Fn&>;
      REQUIRE(invocable);
    }
    GIVEN("a class pointer"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(field), Fn*>;
      REQUIRE(invocable);
    }
    GIVEN("a class reference_wrapper"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v
        <decltype(field), std::reference_wrapper<Fn>>;
      REQUIRE(invocable);
    }
    GIVEN("a child class reference"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(field), Child&>;
      REQUIRE(invocable);
    }
    GIVEN("a child class pointer"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(field), Child*>;
      REQUIRE(invocable);
    }
    GIVEN("a child class reference_wrapper"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v
        <decltype(field), std::reference_wrapper<Child>>;
      REQUIRE(invocable);
    }
    GIVEN("an unrelated class reference"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(field), Gn&>;
      REQUIRE(not invocable);
    }
    GIVEN("an unrelated class pointer"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v<decltype(field), Gn*>;
      REQUIRE(not invocable);
    }
    GIVEN("an unrelated class reference_wrapper"){
      constexpr bool invocable =
        shacl::trait::InvokeDefined_v
        <decltype(field), std::reference_wrapper<Gn>>;
      REQUIRE(not invocable);
    }
  }
}
