
cmake_minimum_required(VERSION 3.18.4)
add_subdirectory(cmake/cmake_functions)
myname(${CMAKE_CURRENT_LIST_DIR} name)
project(${name})

# CMAKE_XCODE_GENERATE_TOP_LEVEL_PROJECT_ONLY

macro(find_package NAME)
    if(NOT "${NAME}" MATCHES "^boost_.*$" AND NOT "${NAME}" STREQUAL BCM)
        _find_package(${ARGV})
    else()
        set(${ARGV0}_FOUND ON CACHE BOOL "")
    endif()
endmacro()

include(cmake/bcm/share/bcm/cmake/BCMConfig.cmake)



file(GLOB_RECURSE LIBS libs/*CMakeLists.txt)
foreach(lib ${LIBS})
    file(READ ${lib} CONTENT)
    if("${CONTENT}" MATCHES "project\\(")
        get_filename_component(LIB_DIR ${lib} DIRECTORY)
        get_filename_component(LIB_NAME ${LIB_DIR} NAME)
        if(NOT "${LIB_NAME}" IN_LIST EXCLUDE_LIBS)
            add_subdirectory(${LIB_DIR})
        endif()
    endif()
endforeach()



# add_subdirectory(ph)



############################ PH ##################################

option(USE_NLOHMANN "use nlohmann_json library" ON)
option(USE_QT "use qt library" OFF)
option(USE_VULKAN "use vulkan graphics library" OFF)
option(USE_GLFW "use glfw library" OFF)
option(USE_GLM "use glm library" OFF)

find_package(BCM)
include(BCMDeploy)
include(BCMSetupVersion)
bcm_setup_version(VERSION 1.64.0)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/ph/*.hpp src/pch.pch)

add_library(ph SHARED
    ${SOURCES}
    ${HEADERS}
)
set_property(TARGET ${PROJECT_NAME} PROPERTY EXPORT_NAME ${PROJECT_NAME})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_include_directories(ph PRIVATE include)
target_link_libraries(${PROJECT_NAME} 
    PUBLIC 
    ph::networking
    ph::time
    ph::authentication
    ph::utility
)
link(${PROJECT_NAME})

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.pch)


bcm_deploy(TARGETS ${PROJECT_NAME} INCLUDE include NAMESPACE ph::)





################ TEST ##################

file(GLOB test_SOURCES test/src/*.cpp)
file(GLOB test_HEADERS test/include/test/*.hpp test/src/pch.pch)

add_executable("${PROJECT_NAME}_test"
  ${test_SOURCES}
  ${test_HEADERS}
)

target_compile_features("${PROJECT_NAME}_test" PRIVATE cxx_std_17)
target_link_libraries("${PROJECT_NAME}_test" PRIVATE ${PROJECT_NAME})
target_include_directories("${PROJECT_NAME}_test" PRIVATE test/include ${PROJECT_NAME})


link("${PROJECT_NAME}_test")

target_precompile_headers("${PROJECT_NAME}_test" PRIVATE test/src/pch.pch)