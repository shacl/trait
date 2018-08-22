#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  bool operator>=(const Does&) const {
    return false;
  }
};

struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  bool operator>=(const OneWay<j>&) const {
    return true;
  }
};

SCENARIO("Homogeneous >= operator"){
  GIVEN("a type with a defined greater than equal operator"){
    constexpr bool hasGreaterThanEqual = shacl::trait::GreaterThanEqualDefined_v<Does>;
    REQUIRE(hasGreaterThanEqual);
  }
  GIVEN("a type without a defined greater than equal operator"){
    constexpr bool hasGreaterThanEqual = shacl::trait::GreaterThanEqualDefined_v<Doesnt>;
    REQUIRE(not hasGreaterThanEqual);
  }
}

SCENARIO("Heterogeneous >= operator"){
  GIVEN("a pair of types with a defined greater than equal operator"){
    constexpr bool hasGreaterThanEqual =
      shacl::trait::GreaterThanEqualDefined_v<OneWay<1>,OneWay<2>>;
    REQUIRE(hasGreaterThanEqual);
  }
  GIVEN("a pair of types without a defined greater than equal operator"){
    constexpr bool hasGreaterThanEqual =
      shacl::trait::GreaterThanEqualDefined_v<OneWay<3>,OneWay<2>>;
    REQUIRE(not hasGreaterThanEqual);
  }
}
