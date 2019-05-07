#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "shacl/trait.hpp"

SCENARIO("IsInteger"){
  using namespace shacl::trait;
  GIVEN("an int"){
    REQUIRE( IsInteger_v<int> );
  }

  GIVEN("an unsigned int"){
    REQUIRE( IsInteger_v<unsigned int> );
  }

  GIVEN("an const volatile int"){
    REQUIRE( IsInteger_v<const volatile int> );
  }

  GIVEN("a short"){
    REQUIRE( IsInteger_v<short> );
  }
  
  GIVEN("a long"){
    REQUIRE( IsInteger_v<long> );
  }
  
  GIVEN("a long long"){
    REQUIRE( IsInteger_v<long long> );
  }
  
  GIVEN("an int32_t"){
    REQUIRE( IsInteger_v<int32_t> );
  }
  
  GIVEN("an int64_t"){
    REQUIRE( IsInteger_v<int64_t> );
  }

  GIVEN("a bool") {
    REQUIRE_FALSE( IsInteger_v<bool> );
  }
  
  GIVEN("a char") {
    REQUIRE_FALSE( IsInteger_v<char> );
  }
  
  GIVEN("a unsigned char") {
    REQUIRE_FALSE( IsInteger_v<unsigned char> );
  }
  
  GIVEN("a char16_t") {
    REQUIRE_FALSE( IsInteger_v<char16_t> );
  }
  
  GIVEN("a char32_t") {
    REQUIRE_FALSE( IsInteger_v<char32_t> );
  }
  
  GIVEN("a wchar_t") {
    REQUIRE_FALSE( IsInteger_v<wchar_t> );
  }
}
