#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<int>
struct Result{};

struct Other{};

struct LessThanComparable {
  Result<0> operator<(const LessThanComparable&) { return {}; }
  Result<1> operator<(const Other&) { return {}; }
};

SCENARIO("LessThanResult"){
  GIVEN("a less than comparable type"){
    THEN("the LessThanResult trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::LessThanResult<LessThanComparable>::type,
              Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::LessThanResult<LessThanComparable, Other>::type,
              Result<1>>::value);
    }

    THEN("the LessThanResult_t alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::LessThanResult_t<LessThanComparable>,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::LessThanResult_t<LessThanComparable, Other>,
               Result<1>>::value);
    }
  }

  GIVEN("a type not subject to less than comparison"){
    THEN("the LessThanResult trait will NOT have a nested type alias"){
      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::LessThanResult<Other>>);

      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::LessThanResult
                     <Other, LessThanComparable>>);
    }
  }
}
