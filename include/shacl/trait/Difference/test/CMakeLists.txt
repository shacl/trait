add_executable(shacl.trait.Difference.test Difference.test.cpp)

target_link_libraries(shacl.trait.Difference.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Difference.test
  COMMAND shacl.trait.Difference.test)
