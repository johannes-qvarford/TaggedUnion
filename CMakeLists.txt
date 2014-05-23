cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

SET(APP TaggedUnion)

if (MSVC)
	SET(CMAKE_CXX_FLAGS /EHsc)
else ()
	SET(CMAKE_CXX_FLAGS "-std=c++11")
endif ()

SET(CMAKE_CXX_FLAGS_DEBUG "-DTUT_DEBUG")

add_executable (${APP} UnionTest.cpp)

