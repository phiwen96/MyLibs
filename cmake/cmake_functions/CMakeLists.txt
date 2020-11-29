cmake_minimum_required(VERSION 3.17.2)
project(cmake_functions)

add_subdirectory(functions)

myname(${CMAKE_CURRENT_LIST_DIR} name)

# message(${name})

# message(${folderName})

# message(${CMAKE_CURRENT_LIST_DIR})

