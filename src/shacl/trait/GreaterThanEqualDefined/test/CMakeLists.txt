add_executable(shacl.trait.GreaterThanEqualDefined.test
  GreaterThanEqualDefined.test.cpp)

target_link_libraries(shacl.trait.GreaterThanEqualDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.GreaterThanEqualDefined.test
  COMMAND shacl.trait.GreaterThanEqualDefined.test)
