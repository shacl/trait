#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does {
  bool operator==(const Does&) const {
    return false;
  }

  bool operator!=(const Does&) const {
    return false;
  }
};

struct HasEquality {
  bool operator==(const HasEquality&) const {
    return false;
  }
};

struct HasInequality {
  bool operator!=(const HasInequality&) const {
    return false;
  }
};

struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  bool operator==(const OneWay<j>&) const {
    return true;
  }

  template<int j, std::enable_if_t<(i < j), bool> = true>
  bool operator!=(const OneWay<j>&) const {
    return true;
  }
};

template<int i>
struct TwoWay {
  template<int j>
  bool operator==(const TwoWay<j>&) const {
    return true;
  }

  template<int j>
  bool operator!=(const TwoWay<j>&) const {
    return true;
  }
};

SCENARIO("Homogeneous Parameters"){
  GIVEN("a type with a defined equality and inequality operator"){
    constexpr bool equalityComparable =
      shacl::trait::EqualityComparable_v<Does>;
    REQUIRE(equalityComparable);
  }
  GIVEN("a type with a defined equality operator"){
    constexpr bool equalityComparable =
      shacl::trait::EqualityComparable_v<HasEquality>;
    REQUIRE(not equalityComparable);
  }
  GIVEN("a type with a defined inequality operator"){
    constexpr bool equalityComparable =
      shacl::trait::EqualityComparable_v<HasInequality>;
    REQUIRE(not equalityComparable);
  }
  GIVEN("a type without a defined less than operator"){
    constexpr bool equalityComparable =
      shacl::trait::EqualityComparable_v<Doesnt>;
    REQUIRE(not equalityComparable);
  }
}

SCENARIO("Heterogeneous Parameters"){
  GIVEN("a pair of types with a asymmetric equality operator"){
    constexpr bool equalityComparable =
      shacl::trait::EqualityComparable_v<OneWay<1>,OneWay<2>>;
    REQUIRE_FALSE(equalityComparable);
  }
  GIVEN("a pair of types with a symmetric equality operator"){
    constexpr bool equalityComparable =
      shacl::trait::EqualityComparable_v<TwoWay<3>,TwoWay<2>>;
    REQUIRE(equalityComparable);
  }
}
