cmake_minimum_required(VERSION 3.16.0)




get_filename_component(foldername ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" foldername ${foldername})
project(${foldername})



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)



file(GLOB SOURCES src/*.cpp src/pch.pch src/qml.qrc)
file(GLOB HEADERS include/xcards/*.hpp)

# find_package(ph REQUIRED)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick QuickControls2 REQUIRED)
find_package(nlohmann_json 3.2.0 REQUIRED)
# find_package(ph REQUIRED)


add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})



target_compile_definitions(${PROJECT_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)






target_link_libraries(${PROJECT_NAME}
  PRIVATE 
    ph::networking
    nlohmann_json::nlohmann_json 
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Quick 
    Qt${QT_VERSION_MAJOR}::QuickControls2
  )


target_include_directories(${PROJECT_NAME} 
    PRIVATE 
    # $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    # $<INSTALL_INTERFACE:include>
    nlohmann_json::nlohmann_json
    ph::networking
    include
)


target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.pch)
