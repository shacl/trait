add_executable(shacl.trait.SwapNoThrow.test SwapNoThrow.test.cpp)

target_link_libraries(shacl.trait.SwapNoThrow.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.SwapNoThrow.test
  COMMAND shacl.trait.SwapNoThrow.test)
