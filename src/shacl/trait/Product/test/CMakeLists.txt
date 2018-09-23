add_executable(shacl.trait.Product.test Product.test.cpp)

target_link_libraries(shacl.trait.Product.test
  PUBLIC shacl::trait::testing)

add_test(NAME shacl.trait.Product.test
  COMMAND shacl.trait.Product.test)
