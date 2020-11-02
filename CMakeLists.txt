
cmake_minimum_required(VERSION 3.18.4)
# add_subdirectory(cmake/cmake_functions)
project(cplusplus)

# CMAKE_XCODE_GENERATE_TOP_LEVEL_PROJECT_ONLY

add_subdirectory(cmake/cmake_functions)
macro(find_package NAME)
    if(NOT "${NAME}" MATCHES "^boost_.*$" AND NOT "${NAME}" STREQUAL BCM)
        _find_package(${ARGV})
    else()
        set(${ARGV0}_FOUND ON CACHE BOOL "")
    endif()
endmacro()

include(cmake/bcm/share/bcm/cmake/BCMConfig.cmake)







add_subdirectory(libs)
add_subdirectory(apps)














