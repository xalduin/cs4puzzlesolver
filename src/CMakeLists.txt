add_executable (clock clock.cpp clockconfig.cpp)
add_executable (water water.cpp waterconfig.cpp)

set (CMAKE_CXX_COMPILER clang++)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")

find_package (Boost REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})
