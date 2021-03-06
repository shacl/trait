#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Doesnt {};

SCENARIO("Homogeneous Scalable"){
  GIVEN("a type with a defined comparison operators"){
    constexpr bool isScalable = shacl::trait::Scalable_v<int>;
    REQUIRE(isScalable);
  }
  GIVEN("a type without a defined comparison operators"){
    constexpr bool isScalable = shacl::trait::Scalable_v<Doesnt>;
    REQUIRE(not isScalable);
  }
}

SCENARIO("Heterogeneous Comparison"){
  GIVEN("a pair of types with a defined less than operator"){
    constexpr bool isScalable =
      shacl::trait::Scalable_v<int, long>;
    REQUIRE(isScalable);
  }
  GIVEN("a pair of types without a defined less than operator"){
    constexpr bool isScalable =
      shacl::trait::Scalable_v<int, Doesnt>;
    REQUIRE(not isScalable);
  }
}
