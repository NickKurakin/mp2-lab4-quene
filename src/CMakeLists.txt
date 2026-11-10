add_library(src
    code.cpp
    Calc.cpp
    header.h
)

target_include_directories(src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})