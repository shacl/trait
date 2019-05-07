#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

struct Foo {};

SCENARIO("Identity"){
  GIVEN("a type, T"){
    using T = Foo;

    THEN("Identity parameterized on T has a nested typedef referring to T"){
      REQUIRE(shacl::trait::HasType_v<shacl::trait::Identity<T>>);
      REQUIRE(std::is_same<T, typename shacl::trait::Identity<T>::type>::value);
    }

    THEN("Identity_t parameterized on T is an alias to T"){
      REQUIRE(std::is_same<T, shacl::trait::Identity_t<T>>::value);
    }
  }
}
