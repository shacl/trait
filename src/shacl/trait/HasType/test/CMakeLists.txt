add_executable(shacl.trait.hasType.test hasType.test.cpp)

target_link_libraries(shacl.trait.hasType.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.hasType.test
  COMMAND shacl.trait.hasType.test)
