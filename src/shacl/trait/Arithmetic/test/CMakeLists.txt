add_executable(shacl.trait.Arithmetic.test Arithmetic.test.cpp)

target_link_libraries(shacl.trait.Arithmetic.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Arithmetic.test
  COMMAND shacl.trait.Arithmetic.test)
