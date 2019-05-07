add_executable(shacl.trait.EqualityResult.test EqualityResult.test.cpp)

target_link_libraries(shacl.trait.EqualityResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.EqualityResult.test
  COMMAND shacl.trait.EqualityResult.test)
