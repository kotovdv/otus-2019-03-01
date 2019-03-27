project(hello_wolrd_test)

add_library(hello_world_test_lib ../lib/app_version.cpp)
add_executable(test test.cpp)

add_definitions(-DPROJECT_VERSION_MAJOR="9")
add_definitions(-DPROJECT_VERSION_MINOR="5")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set_target_properties(test PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
        )
set_target_properties(test
        PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(test hello_world_test_lib)
target_link_libraries(test ${Boost_LIBRARIES})

enable_testing()

add_test(${PROJECT_NAME}_executable test)