cmake_minimum_required(VERSION 3.18.4)
myname(${CMAKE_CURRENT_LIST_DIR} name)
project("ph_${name}")

find_package(BCM)
include(BCMDeploy)
include(BCMSetupVersion)
bcm_setup_version(VERSION 1.64.0)

option(USE_NLOHMANN "use nlohmann_json library" OFF)
option(USE_QT "use qt library" OFF)
option(USE_VULKAN "use vulkan graphics library" OFF)
option(USE_GLFW "use glfw library" OFF)
option(USE_GLM "use glm library" OFF)


file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/ph/${name}/*.hpp src/pch.pch)

add_library(${PROJECT_NAME}
  SHARED
  ${SOURCES}
  ${HEADERS}
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)


target_include_directories(${PROJECT_NAME} PRIVATE include)


link(${PROJECT_NAME})

target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.pch)

set_property(TARGET ${PROJECT_NAME} PROPERTY EXPORT_NAME ${name})
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




######## DOXYGEN ############
# first we can indicate the documentation build as an option and set it to ON by default
option(BUILD_DOC "Build documentation" ON)

# check if Doxygen is installed
find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    #add_custom_target( doc_doxygen ALL
     #   COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      #  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
       # COMMENT "Generating API documentation with Doxygen"
        #VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)





# #INPUT                  = @CMAKE_CURRENT_SOURCE_DIR@/include/ph/metaprogramming/ @CMAKE_CURRENT_SOURCE_