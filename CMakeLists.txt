
cmake_minimum_required(VERSION 3.18.4)
# add_subdirectory(cmake/cmake_functions)
project(cplusplus)

# CMAKE_XCODE_GENERATE_TOP_LEVEL_PROJECT_ONLY









add_subdirectory(libs)
add_subdirectory(apps)

# add_subdirectory(apps/xcards)

# file(GLOB_RECURSE LIBS apps/*CMakeLists.txt)
# foreach(lib ${LIBS})
#     file(READ ${lib} CONTENT)
#     if("${CONTENT}" MATCHES "project\\(")
#         get_filename_component(LIB_DIR ${lib} DIRECTORY)
#         get_filename_component(LIB_NAME ${LIB_DIR} NAME)
#         if(NOT "${LIB_NAME}" IN_LIST EXCLUDE_LIBS)
#             add_subdirectory(${LIB_DIR})
#         endif()
#     endif()
# endforeach()



















