#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Does { Does operator/(const Does&) const { return {}; } };
struct Doesnt {};

template<int i>
struct OneWay {
  template<int j, std::enable_if_t<(i < j), bool> = true>
  OneWay<j-i> // subtraction is a non-monoidal operator, hence ordering matters.
              // this property is useful to check order of evaluation in testing
  operator/(const OneWay<j>&) const {
    return {};
  }
};

SCENARIO("Quotient"){
  GIVEN("one argument"){
    THEN("the quotient type is always defined"){
      constexpr auto correctTypes =
        std::is_same<shacl::trait::Quotient_t<Does>,
                     Does>::value
        and std::is_same<shacl::trait::Quotient_t<Doesnt>,
                         Doesnt>::value;
      REQUIRE(correctTypes);
    }
  }
  GIVEN("a pair of parameters"){
    GIVEN("multiplication is defined over the pair of type"){
      THEN("quotient provides an alias to the resulting type"){
        {
          constexpr auto correctType =
            std::is_same<shacl::trait::Quotient_t<Does, Does>,
                         Does>::value;
          REQUIRE(correctType);
        }{
          constexpr auto correctType =
            std::is_same<shacl::trait::Quotient_t<OneWay<2>, OneWay<3>>,
                         OneWay<1>>::value;
          REQUIRE(correctType);
        }
      }
    }
    GIVEN("multiplication is NOT defined over the pair of type"){
      THEN("quotient does not provide a nested type alias"){
        {
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Quotient<Doesnt, Doesnt>>;
          REQUIRE(not hasNestTypeAlias);
        }{
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Quotient<OneWay<3>, OneWay<2>>>;
          REQUIRE(not hasNestTypeAlias);
        }
      }
    }
  }
  GIVEN("a more than 2 parameters"){
    GIVEN("multiplication is defined over a sequence of type"){
      THEN("quotient provides an alias to the resulting type"){
        {
          constexpr auto correctType =
            std::is_same<shacl::trait::Quotient_t<Does, Does, Does>,
                         Does>::value;
          REQUIRE(correctType);
        }{
          constexpr auto correctType =
            std::is_same<shacl::trait::Quotient_t
                         <OneWay<2>, OneWay<3>, OneWay<4>>,
                         OneWay<3>>::value;
          REQUIRE(correctType);
        }
      }
    }
    GIVEN("multiplication is NOT defined over a sequence of types"){
      THEN("quotient does not provide a nested type alias"){
        {
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v<shacl::trait::Quotient<int, int, Doesnt>>;
          REQUIRE(not hasNestTypeAlias);
        }{
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Quotient<OneWay<2>, OneWay<5>, OneWay<2>>>;
          REQUIRE(not hasNestTypeAlias);
        }{
          constexpr auto hasNestTypeAlias =
            shacl::trait::HasType_v
            <shacl::trait::Quotient<OneWay<5>, OneWay<2>, OneWay<4>>>;
          REQUIRE(not hasNestTypeAlias);
        }
      }
    }
  }
}
