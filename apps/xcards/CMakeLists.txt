cmake_minimum_required(VERSION 3.16.0)
myname(${CMAKE_CURRENT_LIST_DIR} name)
project(${name})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

option(USE_NLOHMANN "use nlohmann_json library" ON)
option(USE_QT "use qt library" ON)
option(USE_VULKAN "use vulkan graphics library" OFF)
option(USE_GLFW "use glfw library" OFF)
option(USE_GLM "use glm library" OFF)



# file(GLOB SOURCES src/*.cpp src/pch.pch src/qml.qrc)
# file(GLOB HEADERS include/xcards/*.hpp)




# add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# find_package(ph REQUIRED)


# target_link_libraries(${PROJECT_NAME}
#   PRIVATE 
#     ph::networking
#   )


# target_include_directories(${PROJECT_NAME} 
#     PRIVATE 
#     # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
#     # $<INSTALL_INTERFACE:include>
#     ph::networking
#     include
# )


# target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.pch)
