cmake_minimum_required(VERSION 3.15)
project(day04_05_homework)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-elide-constructors")

# 第四、五天练习
add_executable(
	day04_05_simple_student_class 
	day04_05_practice_00/simple_student_class.cpp)
add_executable(
	day04_05_simple_calculator 
	day04_05_practice_01/simple_calculator_class.cpp
	day04_05_practice_01/Calc.cpp)
add_executable(
	day04_05_special_function_constructor 
	day04_05_practice_02/special_function_00.cpp)
add_executable(
	day04_05_special_function_constructor_initialization_list 
	day04_05_practice_02/special_function_01.cpp)
add_executable(
	day04_05_special_function_delegate_constructor 
	day04_05_practice_02/special_function_02.cpp)
add_executable(
	day04_05_special_function_deconstructor 
	day04_05_practice_02/special_function_03.cpp)
add_executable(
	day04_05_special_function_copy_constructor 
	day04_05_practice_02/special_function_04.cpp)
add_executable(
	day04_05_special_function_copy_constructor_02 
	day04_05_practice_02/special_function_05.cpp)
add_executable(
	day04_05_special_function_deep_shallow_copy 
	day04_05_practice_02/special_function_06.cpp)
add_executable(
	day04_05_special_function_trigger
	day04_05_practice_02/special_function_07.cpp)
	
# 第四、五天作业
add_executable(
	day04_05_homework_student_class 
	day04_05_homework_00/homework_student_class.cpp)
add_executable(
	day04_05_homework_student_class_01 
	day04_05_homework_01/homework_student_class_01.cpp
	day04_05_homework_01/Student.cpp)
add_executable(
	day04_05_homework_student_class_01_correction 
	day04_05_homework_01_correction/homework_student_class_01_correction.cpp
	day04_05_homework_01_correction/Student.cpp)