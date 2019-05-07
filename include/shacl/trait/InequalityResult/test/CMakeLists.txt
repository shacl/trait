add_executable(shacl.trait.InequalityResult.test InequalityResult.test.cpp)

target_link_libraries(shacl.trait.InequalityResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.InequalityResult.test
  COMMAND shacl.trait.InequalityResult.test)
