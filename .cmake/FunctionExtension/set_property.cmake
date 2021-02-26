macro(previous_set_property)
  if(NOT previous_set_property_fn)
    set(previous_set_property_fn set_property)
  endif()

  push(previous_set_property_fn)
  set(previous_set_property_fn _${previous_set_property_fn})
  call(${previous_set_property_fn} ${ARGN})
  pop(previous_set_property_fn)
endmacro()
