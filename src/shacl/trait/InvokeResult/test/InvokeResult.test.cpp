#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Arg {};
struct Result {};
struct Call { Result operator()(Arg){ return {}; } };

SCENARIO("InvokeResult"){
  GIVEN("a valid invocation"){
    constexpr bool correctResult =
      std::is_same
      <Result, shacl::trait::InvokeResult_t<Call, Arg>>::value;
    REQUIRE(correctResult);
  }

  GIVEN("an invalid invocation"){
    constexpr bool hasType =
      shacl::trait::HasType_v<shacl::trait::InvokeResult<const Call&, Arg>>;
    REQUIRE(not hasType);
  }
}
