add_executable(shacl.trait.Compound.test
  Compound.test.cpp
  get.test.cpp)

target_link_libraries(shacl.trait.Compound.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.Compound.test COMMAND shacl.trait.Compound.test)
