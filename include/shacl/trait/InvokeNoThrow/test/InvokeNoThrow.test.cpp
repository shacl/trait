#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct NoThrow {
  void operator()(int) noexcept {}
};

struct ExplicitThrow {
  void operator()(int) noexcept(false) {}
};

struct ImplicitThrow {
  void operator()(int) {}
};

SCENARIO("InvokeNothrow"){
  GIVEN("a class with a call operator"){
    GIVEN("the call operator is marked noexcept"){
      THEN("the invoke exception safety trait will return true"){
        REQUIRE(shacl::trait::InvokeNoThrow_v<NoThrow, int>);
      }
    }

    GIVEN("the call operator is marked noexcept(false)"){
      THEN("the invoke exception safety trait will return false"){
        REQUIRE_FALSE(shacl::trait::InvokeNoThrow_v<ExplicitThrow, int>);
      }
    }

    GIVEN("the call operator exception safety is unspecified"){
      THEN("the invoke exception safety trait will return false"){
        REQUIRE_FALSE(shacl::trait::InvokeNoThrow_v<ImplicitThrow, int>);
      }
    }
  }
}
