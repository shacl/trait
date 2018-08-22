#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Doesnt {};

SCENARIO("Homogeneous Comparable"){
  GIVEN("a type with a defined comparison operators"){
    constexpr bool isComparable = shacl::trait::Comparable_v<int>;
    REQUIRE(isComparable);
  }
  GIVEN("a type without a defined comparison operators"){
    constexpr bool isComparable = shacl::trait::Comparable_v<Doesnt>;
    REQUIRE(not isComparable);
  }
}

SCENARIO("Heterogeneous Comparison"){
  GIVEN("a pair of types with a defined less than operator"){
    constexpr bool isComparable =
      shacl::trait::Comparable_v<int, long>;
    REQUIRE(isComparable);
  }
  GIVEN("a pair of types without a defined less than operator"){
    constexpr bool isComparable =
      shacl::trait::Comparable_v<int, Doesnt>;
    REQUIRE(not isComparable);
  }
}
