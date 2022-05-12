
cmake_minimum_required(VERSION 3.17)
project(adjust C)

include(FetchContent)

FetchContent_Declare(Sodium
        GIT_REPOSITORY https://github.com/robinlinden/libsodium-cmake.git
        )
set(SODIUM_DISABLE_TESTS ON)
FetchContent_MakeAvailable(Sodium)

include_directories(include)

set(CMAKE_C_STANDARD 11)

set(LIBRARY_OUTPUT_PATH "build")

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} sodium)
# target_compile_definitions(${PROJECT_NAME} PRIVATE PRINT_HEX=0)

enable_testing()

if (ANDROID)
    configure_file(acmp.sh acmp.sh COPYONLY)
    add_test(NAME test COMMAND ./acmp.sh 33cafdba8da1ef3c61d51852bec4a2ae48461d5511e10fbb77abc000b04cb6c0 ${PROJECT_NAME} TEXT_1)
    add_test(NAME test_longer COMMAND ./acmp.sh dedbb94291606189d99656c86abb64c25c49dfaf1a357a97943fcc745329fb83 ${PROJECT_NAME} "A bit bigger test text...")
    add_test(NAME test_empty COMMAND ./acmp.sh 0e5751c026e543b2e8ab2eb06099daa1d1e5df47778f7787faab45cdf12fe3a8 ${PROJECT_NAME} "")
else()
    configure_file(cmp.sh cmp.sh COPYONLY)
    add_test(NAME test COMMAND ./cmp.sh 33cafdba8da1ef3c61d51852bec4a2ae48461d5511e10fbb77abc000b04cb6c0 ${PROJECT_NAME} TEXT_1)
    add_test(NAME test_longer COMMAND ./cmp.sh dedbb94291606189d99656c86abb64c25c49dfaf1a357a97943fcc745329fb83 ${PROJECT_NAME} "A bit bigger test text...")
    add_test(NAME test_empty COMMAND ./cmp.sh 0e5751c026e543b2e8ab2eb06099daa1d1e5df47778f7787faab45cdf12fe3a8 ${PROJECT_NAME} "")
endif()