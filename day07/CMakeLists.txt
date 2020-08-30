cmake_minimum_required(VERSION 3.15)

project(day07_lambda_opOverload)

set(CMAKE_CXX_STANDARD 14)

# practice
add_executable(
	day07_lambda_practice_00
	day07_practice_00/day07_lambda_00.cpp)
add_executable(
	day07_lambda_practice_01
	day07_practice_00/day07_lambda_01.cpp)
add_executable(
	day07_lambda_practice_02
	day07_practice_00/day07_lambda_02.cpp)
	
add_executable(
	day07_operator_overload_out.cpp
	day07_practice_01/operator_overload_out.cpp
)
add_executable(
	day07_operator_overload_in.cpp
	day07_practice_01/operator_overload_in.cpp
)
add_executable(
	day07_operator_overload_copy_move.cpp
	day07_practice_01/operator_overload_copy_move.cpp
)
add_executable(
	day07_operator_overload_copy_move_01.cpp
	day07_practice_01/operator_overload_copy_move_01.cpp
)

# homework