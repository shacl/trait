list(APPEND CTEST_CUSTOM_COVERAGE_EXCLUDE
  ".*catch.*"
  ".*test.*"
  ".*c[+][+]")

list(APPEND CTEST_EXTRA_COVERAGE_GLOB ".*shacl/trait.*hpp")
