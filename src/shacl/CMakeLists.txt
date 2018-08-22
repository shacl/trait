target_sources(trait INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/trait.hpp>
  $<INSTALL_INTERFACE:include/shacl/trait.hpp>)

add_subdirectory(trait)
