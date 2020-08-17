cmake_minimum_required(VERSION 3.15)
project(day03_homework)

set(CMAKE_CXX_STANDARD 14)

# 第三天练习
add_executable(day03_int_array_score day03_practice/int_array_score.cpp)
add_executable(day03_pointer_vector day03_practice/day03_pointer_vector/vector_pointer.cpp)
add_executable(day03_double_pointer day03_double_pointer/double_pointer.cpp)
add_executable(day03_vector_name day03_vector_name/vector_name.cpp)
add_executable(day03_function_basic day03_pointer_function/function_basic.cpp)
add_executable(day03_function_pointer day03_pointer_function/function_pointer.cpp)
add_executable(day03_function_pointer_argument day03_pointer_function/function_pointer_argument.cpp)
add_executable(day03_function_pointer_argument_2 day03_pointer_function/function_pointer_argument_2.cpp)


# 第三天打卡作业
# add_executable()
add_executable(
	day03_homework_01 
	day03_homework/day03_homework.cpp
	day03_homework/stu.cpp)
	
	
add_executable(
	day03_homework_calculator
	day03_homework_02/calculator.cpp
)


add_executable(
	day03_homework_calculator_02
	day03_homework_02/calculator_02.cpp
)

add_executable(
	day03_homework_student_score
	day03_homework_02/student_score.cpp
)
	
# typedef 练习
add_executable(day03_typedef_00 day03_typedef/typedef_00.cpp)
add_executable(day03_typedef_01 day03_typedef/typedef_01.cpp)