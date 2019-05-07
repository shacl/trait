add_executable(shacl.trait.InvokeDefined.test InvokeDefined.test.cpp)

target_link_libraries(shacl.trait.InvokeDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.InvokeDefined.test
  COMMAND shacl.trait.InvokeDefined.test)
