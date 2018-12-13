add_executable(shacl.trait.DereferenceResult.test DereferenceResult.test.cpp)

target_link_libraries(shacl.trait.DereferenceResult.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.DereferenceResult.test
  COMMAND shacl.trait.DereferenceResult.test)
