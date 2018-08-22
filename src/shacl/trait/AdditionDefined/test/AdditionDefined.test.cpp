#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  bool operator+(const Does&) const {
    return false;
  }
};

struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  bool operator+(const OneWay<j>&) const {
    return true;
  }
};

SCENARIO("Homogeneous + operator"){
  GIVEN("a type with a defined addition operator"){
    constexpr bool hasAddition = shacl::trait::AdditionDefined_v<Does>;
    REQUIRE(hasAddition);
  }
  GIVEN("a type without a defined addition operator"){
    constexpr bool hasAddition = shacl::trait::AdditionDefined_v<Doesnt>;
    REQUIRE(not hasAddition);
  }
}

SCENARIO("Heterogeneous + operator"){
  GIVEN("a pair of types with a defined addition operator"){
    constexpr bool hasAddition =
      shacl::trait::AdditionDefined_v<OneWay<1>,OneWay<2>>;
    REQUIRE(hasAddition);
  }
  GIVEN("a pair of types without a defined addition operator"){
    constexpr bool hasAddition =
      shacl::trait::AdditionDefined_v<OneWay<3>,OneWay<2>>;
    REQUIRE(not hasAddition);
  }
}
