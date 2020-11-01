cmake_minimum_required(VERSION 3.18.4)
project(cmake_functions)

add_subdirectory(functions)

myname(${CMAKE_CURRENT_LIST_DIR} name)

# message(${name})

# message(${folderName})

# message(${CMAKE_CURRENT_LIST_DIR})

