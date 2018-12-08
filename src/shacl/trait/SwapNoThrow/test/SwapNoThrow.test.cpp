#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct ExplicitSafe {
  friend void swap(ExplicitSafe& rhs, ExplicitSafe& lhs) noexcept;
};

struct ImplicitSafe {};

struct ExplicitUnsafe {
  friend void swap(ExplicitUnsafe& rhs, ExplicitUnsafe& lhs) noexcept(false);
};

struct ImplicitUnsafe {
  friend void swap(ImplicitUnsafe& rhs, ImplicitUnsafe& lhs);
};

SCENARIO("SwapNoThrow"){
  GIVEN("a class with a default swap"){
    THEN("the swap exception safety trait will return true"){
      REQUIRE(shacl::trait::SwapNoThrow_v<ImplicitSafe>);
    }
  }

  GIVEN("a class with swap function found by argument dependent lookup"){
    GIVEN("the function is marked noexcept"){
      THEN("the swap exception safety trait will return true"){
        REQUIRE(shacl::trait::SwapNoThrow_v<ExplicitSafe>);
      }
    }

    GIVEN("the function is marked noexcept(false)"){
      THEN("the swap exception safety trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<ExplicitUnsafe>);
      }
    }

    GIVEN("the function exception dafety is unspecified"){
      THEN("the swap exception safety trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapNoThrow_v<ImplicitUnsafe>);
      }
    }
  }
}
