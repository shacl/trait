add_executable(shacl.trait.Identity.test Identity.test.cpp)
target_link_libraries(shacl.trait.Identity.test PUBLIC shacl::trait::testing)
add_test(NAME shacl.trait.Identity.test COMMAND shacl.trait.Identity.test)
