cmake_minimum_required(VERSION 3.14)

project(TestDll)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

#include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(stu
	SHARED
		stu.cpp
		stu.h
)

set_target_properties(
	stu
	PROPERTIES
		POSITION_INDEPENDENT_CODE 1
)

# add_library(
	# stu_static
	# static
	# stu.cpp
# )

add_executable(
	test_dll
	main.cpp
	#stu.cpp
)

set_target_properties(
	test_dll
	PROPERTIES
		POSITION_INDEPENDENT_CODE 1
)

# 让程序关联动态库
#message(STATUS "PROJECT_SOURCE_DIR -- " ${PROJECT_SOURCE_DIR})
target_link_libraries(	#如果不链接静态库，会报错: LNK2019，unresolved external symbol
	test_dll
	stu
)

