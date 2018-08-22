add_executable(shacl.trait.LessThanEqualDefined.test
  LessThanEqualDefined.test.cpp)

target_link_libraries(shacl.trait.LessThanEqualDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.LessThanEqualDefined.test
  COMMAND shacl.trait.LessThanEqualDefined.test)
