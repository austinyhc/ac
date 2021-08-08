cmake_minimum_required (VERSION 3.5)

project (ac
    DESCRIPTION "A bunch of utilities for C++"
    VERSION 0.0.1
    LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 14)
include_directories (include)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.0.0-preview3)

FetchContent_MakeAvailable(Catch2)

FetchContent_Declare(Eigen
    GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
    GIT_TAG        3.4.0
    GIT_SHALLOW    TRUE
    GIT_PROGRESS   TRUE)
set(EIGEN_BUILD_DOC OFF)
set(BUILD_TESTING OFF)
set(EIGEN_BUILD_PKGCONFIG OFF)
FetchContent_MakeAvailable(Eigen)

#function (ac_test name)
#    add_executable (test_${name} tests/${name}.cpp)
#    add_test (${name} test_${name})
#endfunction()
#ac_test (01-TestCase)

add_executable (tests
    tests/00-apply.cpp
    tests/01-utility.cpp
    tests/02-waveform.cpp)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE Eigen3::Eigen)
