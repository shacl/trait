#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Doesnt {};

SCENARIO("Homogeneous Arithmetic"){
  GIVEN("a type with a defined comparison operators"){
    constexpr bool isArithmetic = shacl::trait::Arithmetic_v<int>;
    REQUIRE(isArithmetic);
  }
  GIVEN("a type without a defined comparison operators"){
    constexpr bool isArithmetic = shacl::trait::Arithmetic_v<Doesnt>;
    REQUIRE(not isArithmetic);
  }
}

SCENARIO("Heterogeneous Comparison"){
  GIVEN("a pair of types with a defined less than operator"){
    constexpr bool isArithmetic =
      shacl::trait::Arithmetic_v<int, long>;
    REQUIRE(isArithmetic);
  }
  GIVEN("a pair of types without a defined less than operator"){
    constexpr bool isArithmetic =
      shacl::trait::Arithmetic_v<int, Doesnt>;
    REQUIRE(not isArithmetic);
  }
}
