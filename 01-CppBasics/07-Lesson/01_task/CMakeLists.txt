cmake_minimum_required(VERSION 3.5)

### c++11 standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(arrayManipulation)


add_library(mylib SHARED
            apps/mylib.cpp)

add_library(mylib::library ALIAS mylib)

target_include_directories(mylib
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(main 
                apps/main.cpp)

target_link_libraries(main
    PRIVATE 
        mylib::library
)