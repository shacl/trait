#include "shacl/trait.hpp"
#include "catch2/catch.hpp"

#include <vector>

struct Array {
  std::array<int, 2> data;
  Array(std::array<int,2> data) : data(data){}

  int operator()(std::size_t index) const { return this->data[index]; }
};

SCENARIO("get"){
  GIVEN("a tuple"){
    using T = std::tuple<int, float>;

    THEN("compound::get provides a mechanism to extract elements"){
      T data{0, 1.0f};
      REQUIRE(0 == shacl::trait::compound::get<0>(data));
      REQUIRE(1.0f == shacl::trait::compound::get<1>(data));
    }

    THEN("compound::get is compile-time checkable"){
      REQUIRE(shacl::trait::InvokeDefined_v
              <shacl::trait::compound::get_fn<0>, T>);

      REQUIRE_FALSE(shacl::trait::InvokeDefined_v
                    <shacl::trait::compound::get_fn<2>, T>);
    }
  }

  GIVEN("an array"){
    using T = std::array<int, 2>;

    THEN("compound::get provides a mechanism to extract elements"){
      T data{{0, 1}};
      REQUIRE(0 == shacl::trait::compound::get<0>(data));
      REQUIRE(1 == shacl::trait::compound::get<1>(data));
    }

    THEN("compound::get is compile-time checkable"){
      REQUIRE(shacl::trait::InvokeDefined_v
              <shacl::trait::compound::get_fn<0>, T>);

      REQUIRE_FALSE(shacl::trait::InvokeDefined_v
                    <shacl::trait::compound::get_fn<2>, T>);
    }
  }

  GIVEN("a vector"){
    using T = std::vector<double>;

    THEN("compound::get provides a mechanism to extract elements"){
      T data{0.0, 1.0};
      REQUIRE(0 == shacl::trait::compound::get<0>(data));
      REQUIRE(1 == shacl::trait::compound::get<1>(data));
    }

    THEN("compound::get is NOT compile-time checkable"){
      REQUIRE(shacl::trait::InvokeDefined_v
              <shacl::trait::compound::get_fn<0>, T>);
      REQUIRE(shacl::trait::InvokeDefined_v
              <shacl::trait::compound::get_fn<2>, T>);
    }
  }

  GIVEN("a eigen-like array"){
    using T = Array;

    THEN("compound::get provides a mechanism to extract elements"){
      T data{{{0, 1}}};
      REQUIRE(0 == shacl::trait::compound::get<0>(data));
      REQUIRE(1 == shacl::trait::compound::get<1>(data));
    }

    THEN("compound::get is NOT compile-time checkable"){
      REQUIRE(shacl::trait::InvokeDefined_v
              <shacl::trait::compound::get_fn<0>, T>);
      REQUIRE(shacl::trait::InvokeDefined_v
              <shacl::trait::compound::get_fn<2>, T>);
    }
  }
}
