# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "CMakeFiles/appqml_custom_model_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appqml_custom_model_autogen.dir/ParseCache.txt"
  "appqml_custom_model_autogen"
  )
endif()
