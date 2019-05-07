#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

template<int>
struct Result{};

struct Other{};

struct InequalityComparable {
  Result<0> operator!=(const InequalityComparable&) { return {}; }
  Result<1> operator!=(const Other&) { return {}; }
};

SCENARIO("InequalityResult"){
  GIVEN("a inequality comparable type"){
    THEN("the InequalityResult trait nested alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::InequalityResult<InequalityComparable>::type,
              Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::InequalityResult<InequalityComparable, Other>::type,
              Result<1>>::value);
    }

    THEN("the InequalityResult_t alias will refer to the correct type"){
      REQUIRE(std::is_same
              <shacl::trait::InequalityResult_t<InequalityComparable>,
               Result<0>>::value);

      REQUIRE(std::is_same
              <shacl::trait::InequalityResult_t<InequalityComparable, Other>,
               Result<1>>::value);
    }
  }

  GIVEN("a type not subject to inequality comparison"){
    THEN("the InequalityResult trait will NOT have a nested type alias"){
      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::InequalityResult<Other>>);

      REQUIRE_FALSE(shacl::trait::HasType_v
                    <shacl::trait::InequalityResult
                     <Other, InequalityComparable>>);
    }
  }
}
