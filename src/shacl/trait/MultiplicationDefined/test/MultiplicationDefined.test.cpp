#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  bool operator*(const Does&) const {
    return false;
  }
};

struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  bool operator*(const OneWay<j>&) const {
    return true;
  }
};

SCENARIO("Homogeneous * operator"){
  GIVEN("a type with a defined multiplication operator"){
    constexpr bool hasMultiplication = shacl::trait::MultiplicationDefined_v<Does>;
    REQUIRE(hasMultiplication);
  }
  GIVEN("a type without a defined multiplication operator"){
    constexpr bool hasMultiplication = shacl::trait::MultiplicationDefined_v<Doesnt>;
    REQUIRE(not hasMultiplication);
  }
}

SCENARIO("Heterogeneous * operator"){
  GIVEN("a pair of types with a defined multiplication operator"){
    constexpr bool hasMultiplication =
      shacl::trait::MultiplicationDefined_v<OneWay<1>,OneWay<2>>;
    REQUIRE(hasMultiplication);
  }
  GIVEN("a pair of types without a defined multiplication operator"){
    constexpr bool hasMultiplication =
      shacl::trait::MultiplicationDefined_v<OneWay<3>,OneWay<2>>;
    REQUIRE(not hasMultiplication);
  }
}
