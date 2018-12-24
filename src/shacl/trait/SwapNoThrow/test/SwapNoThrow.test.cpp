#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

namespace useStd {
struct ImplicitSafe {};

struct UnsafeCtor {
  UnsafeCtor(UnsafeCtor&&){}
  UnsafeCtor& operator=(UnsafeCtor&&) noexcept { return *this; }
};

struct UnsafeAssignment {
  UnsafeAssignment(UnsafeAssignment&&) noexcept {}
  UnsafeAssignment& operator=(UnsafeAssignment&&){ return *this; }
};
}

namespace useAdl {
struct ExplicitSafe {
  friend void swap(ExplicitSafe& rhs, ExplicitSafe& lhs) noexcept;
};

struct ExplicitUnsafe {
  friend void swap(ExplicitUnsafe& rhs, ExplicitUnsafe& lhs) noexcept(false);
};

struct ImplicitUnsafe {
  friend void swap(ImplicitUnsafe& rhs, ImplicitUnsafe& lhs);
};
}

SCENARIO("SwapNoThrow"){
  GIVEN("a class with a noexcept move ctor and assign"){
    THEN("the swap exception safety trait will return true"){
      REQUIRE(shacl::trait::SwapNoThrow_v<useStd::ImplicitSafe>);
    }

    GIVEN("an array"){
      REQUIRE(shacl::trait::SwapNoThrow_v<useStd::ImplicitSafe[10]>);
    }
  }

  GIVEN("a class with a noexcept(false) ctor"){
    THEN("the swap exception safety trait will return true"){
      REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useStd::UnsafeCtor>);
    }

    GIVEN("an array"){
      THEN("the swap exception safety trait will return true"){
        REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useStd::UnsafeCtor[10]>);
      }
    }
  }

  GIVEN("a class with a noexcept(false) assignment"){
    THEN("the swap exception safety trait will return true"){
      REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useStd::UnsafeAssignment>);
    }

    GIVEN("an array"){
      THEN("the swap exception safety trait will return true"){
        REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useStd::UnsafeAssignment[10]>);
      }
    }
  }

  GIVEN("a class with swap function found by argument dependent lookup"){
    GIVEN("the function is marked noexcept"){
      THEN("the swap exception safety trait will return true"){
        REQUIRE(shacl::trait::SwapNoThrow_v<useAdl::ExplicitSafe>);
      }

      GIVEN("an array"){
        THEN("the swap exception safety trait will return true"){
          REQUIRE(shacl::trait::SwapNoThrow_v<useAdl::ExplicitSafe[10]>);
        }
      }
    }

    GIVEN("the function is marked noexcept(false)"){
      THEN("the swap exception safety trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useAdl::ExplicitUnsafe>);
      }

      GIVEN("an array"){
        THEN("the swap exception safety trait will return false"){
          REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useAdl::ExplicitUnsafe[10]>);
        }
      }
    }

    GIVEN("the function exception safety is unspecified"){
      THEN("the swap exception safety trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useAdl::ImplicitUnsafe>);
      }

      GIVEN("an array"){
        THEN("the swap exception safety trait will return false"){
          REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<useAdl::ImplicitUnsafe[10]>);
        }
      }
    }
  }
}
