add_executable(shacl.trait.Conjunction.test Conjunction.test.cpp)
target_link_libraries(shacl.trait.Conjunction.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.Conjunction.test COMMAND shacl.trait.Conjunction.test)
