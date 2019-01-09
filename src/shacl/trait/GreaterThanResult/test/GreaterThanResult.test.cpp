#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<int>
struct Result{};

struct Other{};

struct GreaterThanComparable {
  Result<0> operator>(const GreaterThanComparable&) { return {}; }
  Result<1> operator>(const Other&) { return {}; }
};

SCENARIO("GreaterThanResult"){
  GIVEN("a greater than comparable type"){
    THEN("the GreaterThanResult trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::GreaterThanResult<GreaterThanComparable>::type,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::GreaterThanResult<GreaterThanComparable, Other>::type,
               Result<1>>::value);
    }

    THEN("the GreaterThanResult_t alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::GreaterThanResult_t<GreaterThanComparable>,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::GreaterThanResult_t<GreaterThanComparable, Other>,
               Result<1>>::value);
    }
  }

  GIVEN("a type not subject to greater than comparison"){
    THEN("the GreaterThanResult trait will NOT have a nested type alias"){
      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::GreaterThanResult<Other>>);

      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::GreaterThanResult
                     <Other, GreaterThanComparable>>);
    }
  }
}
