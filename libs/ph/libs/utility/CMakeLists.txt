cmake_minimum_required(VERSION 3.17.2)
myname(${CMAKE_CURRENT_LIST_DIR} name)
project("ph_${name}")

find_package(BCM)
include(BCMDeploy)
include(BCMSetupVersion)
bcm_setup_version(VERSION 1.64.0)

option(USE_NLOHMANN "use nlohmann_json library" ON)
option(USE_QT "use qt library" OFF)
option(USE_VULKAN "use vulkan graphics library" OFF)
option(USE_GLFW "use glfw library" OFF)
option(USE_GLM "use glm library" OFF)

if(USE_NLOHMANN)
  find_package(nlohmann_json 3.2.0 REQUIRED)
  list(APPEND EXTRA_LIBS nlohmann_json::nlohmann_json)
  list(APPEND EXTRA_INCLUDES nlohmann_json::nlohmann_json)
endif()




file(GLOB 
  SOURCES 
  src/*.cpp 
)
file(GLOB 
  HEADERS 
  include/ph/utility/*.hpp
  src/pch.pch
)
add_library(${PROJECT_NAME}
  SHARED
  ${SOURCES}
  ${HEADERS}
)
target_compile_features(${PROJECT_NAME} 
  PRIVATE 
  cxx_std_17
)

find_package(nlohmann_json 3.2.0 REQUIRED)



target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(${PROJECT_NAME} PRIVATE include nlohmann_json::nlohmann_json)
target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.pch)

# link(${PROJECT_NAME})



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