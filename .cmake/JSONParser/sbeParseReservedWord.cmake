macro(_sbeParseReservedWord prefix)
  set(json_reservedWord "")
  set(json_end no)
  while(${json_index} LESS ${json_jsonLen} AND NOT json_end)
    string(SUBSTRING "${json_string}" ${json_index} 1 json_char)
    
    if("," STREQUAL "${json_char}" OR "}" STREQUAL "${json_char}" OR "]" STREQUAL "${json_char}")
      set(json_end yes)
    else()
      set(json_reservedWord "${json_reservedWord}${json_char}")
      math(EXPR json_index "${json_index} + 1")
    endif()
  endwhile()

  list(APPEND ${json_AllVariables} ${prefix})
  string(STRIP  "${json_reservedWord}" json_reservedWord)
  set(${prefix} ${json_reservedWord})
endmacro()