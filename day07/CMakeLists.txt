cmake_minimum_required(VERSION 3.15)

project(day07_lambda_opOverload)

set(CMAKE_CXX_STANDARD 14)

# practice_lambda
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
	day07_lambda_practice_03_get_it
	day07_practice_00/day07_lambda_get_it.cpp)
add_executable(
	day07_lambda_practice_03_capture_list
	day07_practice_00/day07_lambda_capture_list.cpp)
add_executable(
	day07_lambda_practice_03_calc_score_vector
	day07_practice_00/day07_lambda_calc_score_vector.cpp)
add_executable(
	day07_lambda_practice_03_lambda_homework_compare
	day07_practice_00/day07_lambda_homework_compare.cpp)


# practice_operator_overload	
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
add_executable(
	day07_operator_overload_bracket.cpp
	day07_practice_01/operator_overload_bracket.cpp
)


# homework