#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does { Does operator-(const Does&) const { return {}; } };
struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  OneWay<j-i> // subtraction is a non-associative operator, hence ordering matters.
              // this property is useful to check order of evaluation in testing below
  operator-(const OneWay<j>&) const {
    return {};
  }
};

SCENARIO("Difference"){
  GIVEN("one argument"){
    THEN("the difference type is always defined"){
      constexpr auto correctTypes =
        std::is_same<shacl::trait::Difference_t<Does>, Does>::value
        and std::is_same<shacl::trait::Difference_t<Doesnt>, Doesnt>::value;
      REQUIRE(correctTypes);
    }
  }
  GIVEN("a pair of parameters"){
    GIVEN("subtraction is defined over the pair of type"){
      THEN("difference provides an alias to the resulting type"){
        {
          constexpr auto correctType =
            std::is_same<shacl::trait::Difference_t<Does, Does>, Does>::value;
          REQUIRE(correctType);
        }{
          constexpr auto correctType =
            std::is_same<shacl::trait::Difference_t<OneWay<2>, OneWay<3>>,
                         OneWay<1>>::value;
          REQUIRE(correctType);
        }
      }
    }
    GIVEN("subtraction is NOT defined over the pair of type"){
      THEN("difference does not provide a nested type alias"){
        {
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Difference<Doesnt, Doesnt>>;
          REQUIRE(not hasNestTypeAlias);
        }{
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Difference<OneWay<3>, OneWay<2>>>;
          REQUIRE(not hasNestTypeAlias);
        }
      }
    }
  }
  GIVEN("a more than 2 parameters"){
    GIVEN("subtraction is defined over a sequence of type"){
      THEN("difference provides an alias to the resulting type"){
        {
          constexpr auto correctType =
            std::is_same<shacl::trait::Difference_t
                         <Does, Does, Does>, Does>::value;
          REQUIRE(correctType);
        }{
          constexpr auto correctType =
            std::is_same<shacl::trait::Difference_t
                         <OneWay<2>, OneWay<3>, OneWay<4>>,
                         OneWay<3>>::value;
          REQUIRE(correctType);
        }
      }
    }
    GIVEN("subtraction is NOT defined over a sequence of types"){
      THEN("difference does not provide a nested type alias"){
        {
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Difference<int, int, Doesnt>>;
          REQUIRE(not hasNestTypeAlias);
        }{
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Difference<OneWay<2>, OneWay<5>, OneWay<2>>>;
          REQUIRE(not hasNestTypeAlias);
        }{
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Difference<OneWay<5>, OneWay<2>, OneWay<4>>>;
          REQUIRE(not hasNestTypeAlias);
        }
      }
    }
  }
}
