cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

SET(APP TaggedUnion)

if (NOT "${CMAKE_CXX_COMPILER_DI}" STREQUAL "MSVC")
	SET(CMAKE_CXX_FLAGS "-std=c++11")
endif ()

SET(CMAKE_CXX_FLAGS_DEBUG "-DTUT_DEBUG")

add_executable (${APP} UnionTest.cpp)

