add_executable(shacl.trait.SwapDefined.test SwapDefined.test.cpp)

target_link_libraries(shacl.trait.SwapDefined.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.SwapDefined.test
  COMMAND shacl.trait.SwapDefined.test)
