cmake_minimum_required (VERSION 2.6)
project (PuzzleSolver)

add_executable (clock clock.cpp clockconfig.cpp)
add_executable (water water.cpp waterconfig.cpp)
add_executable (lights lights.cpp lightconfig.cpp)
add_executable (magic magic.cpp magicconfig.cpp)

set (CMAKE_CXX_COMPILER clang++)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -Wall")
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CSS_FLAGS_DEBUG} -g")

find_package (Boost REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
