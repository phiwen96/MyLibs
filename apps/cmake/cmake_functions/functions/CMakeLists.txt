cmake_minimum_required(VERSION 3.18.4)
project(functions)

function(myname folder output)
    # get_filename_component(foldername ${CMAKE_CURRENT_LIST_DIR} NAME)
    get_filename_component(foldername ${folder} NAME)
    string(REPLACE " " "_" foldername ${foldername})
    set(${output} ${foldername} PARENT_SCOPE)
    # message(${foldername})
endfunction()

# message("< ${CMAKE_PROJECT_NAME} / ${PROJECT_NAME}")

function(link_nlohmann target)
    if(${USE_NLOHMANN})
        find_package(nlohmann_json 3.2 REQUIRED)
        if(NOT nlohmann_json_FOUND)
            message(FATAL_ERROR "couldnt find nlohmann_json")
        endif()
        target_link_libraries(${target} PRIVATE nlohmann_json::nlohmann_json)
    endif(${USE_NLOHMANN})
endfunction(link_nlohmann target)

function(link_qt target)
    if(${USE_QT})
        set(CMAKE_AUTOUIC ON)
        set(CMAKE_AUTOMOC ON)
        set(CMAKE_AUTORCC ON)
        find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick QuickControls2 REQUIRED)
        find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick QuickControls2 REQUIRED)
        
        target_compile_definitions(${target}
            PRIVATE 
            $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
        )
        target_link_libraries(${target}
            PRIVATE 
            Qt${QT_VERSION_MAJOR}::Core 
            Qt${QT_VERSION_MAJOR}::Quick 
            Qt${QT_VERSION_MAJOR}::QuickControls2
        )
        target_include_directories(${target}
            PRIVATE 
            Qt${QT_VERSION_MAJOR}::Core 
            Qt${QT_VERSION_MAJOR}::Quick 
            Qt${QT_VERSION_MAJOR}::QuickControls2
        )
    endif(${USE_QT})
endfunction(link_qt target)

function(link_vulkan target)
    if(${USE_VULKAN})
        find_package(Vulkan REQUIRED)
        if(NOT Vulkan_FOUND)
            message(FATAL_ERROR "couldnt find vulkan")
        endif()
        target_link_libraries(${target} PRIVATE Vulkan::Vulkan)
    endif(${USE_VULKAN})
endfunction(link_vulkan target)

function(link_glfw target)
    if(${USE_GLFW})
        find_package(glfw3 REQUIRED)
        if(NOT glfw3_FOUND)
            message(FATAL_ERROR "couldnt find glfw")
        endif()
        target_link_libraries(${target} PRIVATE glfw)
        target_include_directories(${target} PRIVATE glfw)
    endif(${USE_GLFW})
endfunction(link_glfw target)

function(link_glm target)
    if(${USE_GLM})
        find_package(glm REQUIRED)
        if(NOT glm_FOUND)
            message(FATAL_ERROR "couldnt find glm")
        endif()
        target_include_directories(${target} PRIVATE glm)
    endif(${USE_GLM})
endfunction(link_glm target)


function(link target)
    link_nlohmann(${target})
    link_qt(${target})
    link_vulkan(${target})
    link_glfw(${target})
    link_glm(${target})
endfunction(link target)


function(isMainProject name answer)
    if(${CMAKE_PROJECT_NAME} STREQUAL ${name})
        set(${answer} TRUE)
    else()
        set(${answer} FALSE)
        # message("NO")
    endif()
endfunction(isMainProject name answer)




