cmake_minimum_required(VERSION 3.9)

project(hello_world)
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

configure_file(version/current_version.h.in ${PROJECT_SOURCE_DIR}/version/current_version.h)

add_library(hello_world_lib version/app_version.cpp)
add_executable(hello_world_cli main.cpp)

set_target_properties(
        hello_world_cli hello_world_lib
        PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(hello_world_cli hello_world_lib)