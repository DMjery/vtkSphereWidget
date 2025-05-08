# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/VTKSphereWidgetTests_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/VTKSphereWidgetTests_autogen.dir/ParseCache.txt"
  "CMakeFiles/VTKSphereWidget_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/VTKSphereWidget_autogen.dir/ParseCache.txt"
  "VTKSphereWidgetTests_autogen"
  "VTKSphereWidget_autogen"
  )
endif()
