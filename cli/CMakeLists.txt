project(hello_world_cli)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})

add_definitions(-DPROJECT_VERSION_MAJOR="${PROJECT_VERSION_MAJOR}")
add_definitions(-DPROJECT_VERSION_MINOR="${PROJECT_VERSION_MINOR}")
add_definitions(-DPROJECT_VERSION_PATCH="${PROJECT_VERSION_PATCH}")

add_library(hello_world_cli_lib ../lib/app_version.cpp)
add_executable(helloworld main.cpp)

set_target_properties(helloworld PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )

target_link_libraries(helloworld hello_world_cli_lib)

install(TARGETS helloworld RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dmitriy.kotov93@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)