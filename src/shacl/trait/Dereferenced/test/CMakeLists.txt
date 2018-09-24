add_executable(shacl.trait.Dereferenced.test Dereferenced.test.cpp)

target_link_libraries(shacl.trait.Dereferenced.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Dereferenced.test
  COMMAND shacl.trait.Dereferenced.test)
