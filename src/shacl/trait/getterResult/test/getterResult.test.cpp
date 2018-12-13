#define CATCH_CONFIG_MAIN
#include "shacl/trait.hpp"
#include "catch2/catch.hpp"

SCENARIO("getterResult"){
  GIVEN("a trivially copyable and destructible small type"){
    struct Type {
      std::int64_t data;
    };

    GIVEN("a mutable instance"){
      Type instance{0};

      THEN("getterResult will return a mutable lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, Type&>::value);
      }
    }

    GIVEN("a const instance"){
      const Type instance{0};

      THEN("getterResult will return a copy"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, Type>::value);
      }
    }

    GIVEN("an r-value"){
      THEN("getterResult will return a copy"){
        using Result = decltype(shacl::trait::getterResult(Type{0}));
        REQUIRE(std::is_same<Result, Type>::value);
      }
    }
  }

  GIVEN("a non-trivially copyable small type"){
    struct Type {
      std::int64_t data;
      Type() = default;
      Type(const Type&) : data(1) {}
    };

    GIVEN("a mutable instance"){
      Type instance{};

      THEN("getterResult will return a mutable lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, Type&>::value);
      }
    }

    GIVEN("a const instance"){
      const Type instance{};

      THEN("getterResult will return a const lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, const Type&>::value);
      }
    }

    GIVEN("an r-value"){
      THEN("getterResult will return a copy"){
        using Result = decltype(shacl::trait::getterResult(Type{}));
        REQUIRE(std::is_same<Result, Type>::value);
      }
    }
  }

  GIVEN("a non-trivially destructible small type"){
    struct Type {
      std::int64_t data;
      Type() = default;;
      ~Type() {}
    };

    GIVEN("a mutable instance"){
      Type instance{};

      THEN("getterResult will return a mutable lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, Type&>::value);
      }
    }

    GIVEN("a const instance"){
      const Type instance{};

      THEN("getterResult will return a const lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, const Type&>::value);
      }
    }

    GIVEN("an r-value"){
      THEN("getterResult will return a copy"){
        using Result = decltype(shacl::trait::getterResult(Type{}));
        REQUIRE(std::is_same<Result, Type>::value);
      }
    }
  }

  GIVEN("a 'large' type"){
    struct Type {
      std::int64_t data[2];
    };

    GIVEN("a mutable instance"){
      Type instance{{0, 0}};

      THEN("getterResult will return a mutable lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, Type&>::value);
      }
    }

    GIVEN("a const instance"){
      const Type instance{{0, 0}};

      THEN("getterResult will return a const lvalue reference"){
        using Result = decltype(shacl::trait::getterResult(instance));
        REQUIRE(std::is_same<Result, const Type&>::value);
      }
    }

    GIVEN("an r-value"){
      THEN("getterResult will return a copy"){
        using Result = decltype(shacl::trait::getterResult(Type{{0,0}}));
        REQUIRE(std::is_same<Result, Type>::value);
      }
    }
  }
}
