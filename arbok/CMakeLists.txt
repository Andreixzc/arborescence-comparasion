
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

project(arbok VERSION 1.0.0)

set (CMAKE_CXX_STANDARD 20)

if(CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    add_compile_options(-march=core-avx2)
endif()

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-march=native)
    add_compile_options(-Wall -Wextra -Wshadow -Wfloat-equal -Wconversion -Wno-sign-compare)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        add_compile_options(
                -fsanitize=address,undefined
                -fno-omit-frame-pointer
                -fno-sanitize-recover=all
        )
        add_link_options(
                -fsanitize=address,undefined
                -fno-omit-frame-pointer
        )
    endif()
endif()

#add_compile_options(-g -debug inline-debug-info -DNDEBUG)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})

enable_testing()

add_subdirectory(source)

