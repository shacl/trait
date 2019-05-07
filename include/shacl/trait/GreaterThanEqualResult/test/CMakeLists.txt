add_executable(shacl.trait.GreaterThanEqualResult.test
  GreaterThanEqualResult.test.cpp)

target_link_libraries(shacl.trait.GreaterThanEqualResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.GreaterThanEqualResult.test
  COMMAND shacl.trait.GreaterThanEqualResult.test)
