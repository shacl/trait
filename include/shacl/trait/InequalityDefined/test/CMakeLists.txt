add_executable(shacl.trait.InequalityDefined.test InequalityDefined.test.cpp)

target_link_libraries(shacl.trait.InequalityDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.InequalityDefined.test
  COMMAND shacl.trait.InequalityDefined.test)
