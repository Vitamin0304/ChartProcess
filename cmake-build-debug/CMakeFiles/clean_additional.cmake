# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ChartProcess_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ChartProcess_autogen.dir\\ParseCache.txt"
  "ChartProcess_autogen"
  )
endif()
