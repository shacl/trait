add_executable(shacl.trait.Sum.test Sum.test.cpp)

target_link_libraries(shacl.trait.Sum.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Sum.test
  COMMAND shacl.trait.Sum.test)
