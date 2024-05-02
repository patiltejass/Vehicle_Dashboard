# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Vehicle_Dashboard_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Vehicle_Dashboard_autogen.dir\\ParseCache.txt"
  "Database\\CMakeFiles\\Database_autogen.dir\\AutogenUsed.txt"
  "Database\\CMakeFiles\\Database_autogen.dir\\ParseCache.txt"
  "Database\\Database_autogen"
  "Service\\CMakeFiles\\Service_autogen.dir\\AutogenUsed.txt"
  "Service\\CMakeFiles\\Service_autogen.dir\\ParseCache.txt"
  "Service\\Service_autogen"
  "Vehicle_Dashboard_autogen"
  )
endif()
