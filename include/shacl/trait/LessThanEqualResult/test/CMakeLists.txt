add_executable(shacl.trait.LessThanEqualResult.test
  LessThanEqualResult.test.cpp)

target_link_libraries(shacl.trait.LessThanEqualResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.LessThanEqualResult.test
  COMMAND shacl.trait.LessThanEqualResult.test)
