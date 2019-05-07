add_executable(shacl.trait.Disjunction.test Disjunction.test.cpp)
target_link_libraries(shacl.trait.Disjunction.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.Disjunction.test COMMAND shacl.trait.Disjunction.test)
