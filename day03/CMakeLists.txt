cmake_minimum_required(VERSION 3.15)
project(day03_homework)

set(CMAKE_CXX_STANDARD 14)

# 第三天练习
add_executable(day03_int_array_score day03_practice/int_array_score.cpp)
add_executable(day03_pointer_vector day03_practice/day03_pointer_vector/vector_pointer.cpp)


# 第三天打卡作业
# add_executable()
add_executable(
	day03_homework_01 
	day03_homework/day03_homework.cpp
	day03_homework/stu.cpp)