add_executable(shacl.trait.InvokeResult.test InvokeResult.test.cpp)

target_link_libraries(shacl.trait.InvokeResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.InvokeResult.test
  COMMAND shacl.trait.InvokeResult.test)
