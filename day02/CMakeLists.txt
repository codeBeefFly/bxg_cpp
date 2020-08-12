cmake_minimum_required(VERSION 3.15)
project(day02_homework)

set(CMAKE_CXX_STANDARD 14)

# 第一天练习
add_executable(day02_normal_practice normal_practice/normal_practice.cpp)

# 第一天作业
add_executable(day02_homework_01_string day02_homework/day02_homework_01_string.cpp)
add_executable(
	day02_homework_02_calculator 
	day02_homework/day02_homework_02_calculator.cpp
	day02_homework/calc.cpp)	# 需要将源文件加入到 add_executable 中，不用加入头文件
add_executable(day02_homework_03_marks day02_homework/day02_homework_03_marks.cpp)