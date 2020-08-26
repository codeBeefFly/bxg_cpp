cmake_minimum_required(VERSION 3.15)
project(day06_operator_overloading)

set(CMAKE_CXX_STANDARD 14)

# practice
add_executable(
	day06_operator_overloading_00
	day06_practice_00/operator_overloading_00.cpp)

# homework
add_executable(
	day06_operator_overloading_student_money
	day06_homework_00/student_money_operator_overload.cpp)
add_executable(
	day06_operator_overloading_student_marks
	day06_homework_01/student_marks_operator_overload.cpp)