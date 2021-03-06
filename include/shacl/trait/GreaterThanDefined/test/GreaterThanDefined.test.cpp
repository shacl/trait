#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  bool operator>(const Does&) const {
    return false;
  }
};

struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  bool operator>(const OneWay<j>&) const {
    return true;
  }
};

SCENARIO("Homogeneous > operator"){
  GIVEN("a type with a defined greater than operator"){
    constexpr bool hasGreaterThan = shacl::trait::GreaterThanDefined_v<Does>;
    REQUIRE(hasGreaterThan);
  }
  GIVEN("a type without a defined greater than operator"){
    constexpr bool hasGreaterThan = shacl::trait::GreaterThanDefined_v<Doesnt>;
    REQUIRE(not hasGreaterThan);
  }
}

SCENARIO("Heterogeneous > operator"){
  GIVEN("a pair of types with a defined greater than operator"){
    constexpr bool hasGreaterThan =
      shacl::trait::GreaterThanDefined_v<OneWay<1>,OneWay<2>>;
    REQUIRE(hasGreaterThan);
  }
  GIVEN("a pair of types without a defined greater than operator"){
    constexpr bool hasGreaterThan =
      shacl::trait::GreaterThanDefined_v<OneWay<3>,OneWay<2>>;
    REQUIRE(not hasGreaterThan);
  }
}
