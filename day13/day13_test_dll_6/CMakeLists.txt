cmake_minimum_required(VERSION 3.14)

project(TestDll)

set(CMAKE_CXX_STANDARD 14)

#导入动态依赖库，需要导入两部分内容：1. 头文件，2.源文件（已经被打包好了.so,.dll）
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(
	test_dll
	main.cpp
)

# 让程序关联动态库
message(STATUS "PROJECT_SOURCE_DIR -- " ${PROJECT_SOURCE_DIR})
target_link_libraries(	#如果不链接静/动态库，会报错: LNK2019，unresolved external symbol
	test_dll
	${PROJECT_SOURCE_DIR}/lib/stu
)

