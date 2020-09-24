cmake_minimum_required(VERSION 3.14)

project(TestDll)

set(CMAKE_CXX_STANDARD 14)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(
	test_dll
	main.cpp
)

# 让程序关联动态库
message(STATUS "PROJECT_SOURCE_DIR -- " ${PROJECT_SOURCE_DIR})
target_link_libraries(
	test_dll
	${PROJECT_SOURCE_DIR}/lib/stu.lib
	#./lib/stu
)