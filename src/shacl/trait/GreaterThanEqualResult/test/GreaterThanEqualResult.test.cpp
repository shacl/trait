#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<int>
struct Result{};

struct Other{};

struct GreaterThanEqualComparable {
  Result<0> operator>=(const GreaterThanEqualComparable&) { return {}; }
  Result<1> operator>=(const Other&) { return {}; }
};

SCENARIO("GreaterThanEqualResult"){
  GIVEN("a greater than comparable type"){
    THEN("the GreaterThanEqualResult trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::GreaterThanEqualResult
               <GreaterThanEqualComparable>::type,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::GreaterThanEqualResult
               <GreaterThanEqualComparable, Other>::type,
               Result<1>>::value);
    }

    THEN("the GreaterThanEqualResult_t alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::GreaterThanEqualResult_t
               <GreaterThanEqualComparable>,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::GreaterThanEqualResult_t
               <GreaterThanEqualComparable, Other>,
               Result<1>>::value);
    }
  }

  GIVEN("a type not subject to greater than comparison"){
    THEN("the GreaterThanEqualResult trait will NOT have a nested type alias"){
      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::GreaterThanEqualResult<Other>>);

      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::GreaterThanEqualResult
                     <Other, GreaterThanEqualComparable>>);
    }
  }
}
