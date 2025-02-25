cmake_minimum_required(VERSION 3.17.2)
myname(${CMAKE_CURRENT_LIST_DIR} name)
project("ph_${name}")

find_package(BCM)
include(BCMDeploy)
include(BCMSetupVersion)
bcm_setup_version(VERSION 1.64.0)

option(USE_NLOHMANN "use nlohmann_json library" OFF)
option(USE_QT "use qt library" OFF)
option(USE_VULKAN "use vulkan graphics library" ON)
option(USE_GLFW "use glfw library" ON)
option(USE_GLM "use glm library" ON)
find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

file(GLOB SOURCES src/*.hpp src/*.cpp)
file(GLOB HEADERS include/ph/${name}/*.hpp src/pch.pch)

add_library(${PROJECT_NAME}
  SHARED
  ${HEADERS}
  ${SOURCES}
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} 
  PUBLIC 
  ph::time
  #Vulkan::Vulkan
  ${Vulkan_LIBRARIES}
  glfw
)

target_include_directories(${PROJECT_NAME} 
  PRIVATE 
  include
  ph::time
  #Vulkan::Vulkan
  ${Vulkan_INCLUDE_DIR}
  glfw
  glm
)









# link(${PROJECT_NAME})


target_precompile_headers(${PROJECT_NAME} PUBLIC src/pch.pch)




set_property(TARGET ${PROJECT_NAME} PROPERTY EXPORT_NAME ${name})
bcm_deploy(TARGETS ${PROJECT_NAME} INCLUDE include NAMESPACE ph::)




################ TEST ##################

file(GLOB test_SOURCES test/src/*.cpp)
file(GLOB test_HEADERS test/include/test/*.hpp test/src/pch.pch)

add_executable("${PROJECT_NAME}_test"
  ${test_SOURCES}
  ${test_HEADERS}
)

target_compile_features("${PROJECT_NAME}_test" PRIVATE cxx_std_20)
target_link_libraries("${PROJECT_NAME}_test" PRIVATE ${PROJECT_NAME})
target_include_directories("${PROJECT_NAME}_test" PRIVATE test/include ${PROJECT_NAME})


link("${PROJECT_NAME}_test")

target_precompile_headers("${PROJECT_NAME}_test" PRIVATE test/src/pch.pch)