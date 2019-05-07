add_executable(shacl.trait.EqualityComparable.test EqualityComparable.test.cpp)

target_link_libraries(shacl.trait.EqualityComparable.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.EqualityComparable.test
  COMMAND shacl.trait.EqualityComparable.test)
