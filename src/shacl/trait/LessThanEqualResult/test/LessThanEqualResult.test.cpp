#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<int>
struct Result{};

struct Other{};

struct LessThanEqualComparable {
  Result<0> operator<=(const LessThanEqualComparable&) { return {}; }
  Result<1> operator<=(const Other&) { return {}; }
};

SCENARIO("LessThanEqualResult"){
  GIVEN("a less than equal comparable type"){
    THEN("the LessThanEqualResult trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::LessThanEqualResult<LessThanEqualComparable>::type,
              Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::LessThanEqualResult<LessThanEqualComparable, Other>::type,
              Result<1>>::value);
    }

    THEN("the LessThanEqualResult_t alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::LessThanEqualResult_t<LessThanEqualComparable>,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::LessThanEqualResult_t<LessThanEqualComparable, Other>,
               Result<1>>::value);
    }
  }

  GIVEN("a type not subject to less than equal comparison"){
    THEN("the LessThanEqualResult trait will NOT have a nested type alias"){
      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::LessThanEqualResult<Other>>);

      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::LessThanEqualResult
                     <Other, LessThanEqualComparable>>);
    }
  }
}
