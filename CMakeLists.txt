cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME stack)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)