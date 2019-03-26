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

install(TARGETS hello_world_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dmitriy.kotov93@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)