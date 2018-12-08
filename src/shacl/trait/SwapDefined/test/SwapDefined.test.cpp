#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Yes {};

struct No {
  No() {}
  ~No() {}
  No(const No&) = delete;
  No(No&&) = delete;
};

struct ADL {
  ADL(int x) : x(x) {}
  ~ADL() {}

  ADL(const ADL&) = delete;
  ADL(ADL&&) = delete;

  friend void swap(ADL& rhs, ADL& lhs) { std::swap(rhs.x, lhs.x); }

private:
    int x;
};

SCENARIO("SwapDefined"){
  GIVEN("a class with a default swap"){
    THEN("the swap-detection trait will return true"){
      REQUIRE(shacl::trait::SwapDefined_v<Yes>);
    }
  }

  GIVEN("a class with deleted move construction and move assignment"){
    THEN("the default swap is not defined"){
      AND_THEN("the swap-detection trait will return false"){
        REQUIRE_FALSE(shacl::trait::SwapDefined_v<No>);
      }
    }

    GIVEN("an explicit definition for swap is available"
          " via argument-dependent lookup"){
      THEN("the swap-detection trait will return true"){
        REQUIRE(shacl::trait::SwapDefined_v<ADL>);
      }
    }
  }
}
