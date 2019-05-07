add_executable(shacl.trait.InvokeNoThrow.test InvokeNoThrow.test.cpp)

target_link_libraries(shacl.trait.InvokeNoThrow.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.InvokeNoThrow.test
  COMMAND shacl.trait.InvokeNoThrow.test)
