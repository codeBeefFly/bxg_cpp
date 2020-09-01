cmake_minimum_required(VERSION 3.15)

project(day07_lambda_opOverload_inherit)

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
	day07_operator_overload_out
	day07_practice_01/operator_overload_out.cpp
)
add_executable(
	day07_operator_overload_in
	day07_practice_01/operator_overload_in.cpp
)
add_executable(
	day07_operator_overload_copy_move
	day07_practice_01/operator_overload_copy_move.cpp
)
add_executable(
	day07_operator_overload_copy_move_01
	day07_practice_01/operator_overload_copy_move_01.cpp
)
add_executable(
	day07_operator_overload_bracket
	day07_practice_01/operator_overload_bracket.cpp
)


# practice_inherit
add_executable(
	day07_inherit_simple
	day07_practice_02_inherit/inherit_simple.cpp
)
add_executable(
	day07_inherit_simple_plus
	day07_practice_02_inherit/inherit_simple_plus.cpp
)
add_executable(
	day07_inherit_constructor_deconstructor
	day07_practice_02_inherit/inherit_constructor_deconstructor.cpp
)
add_executable(
	day07_inherit_combined
	day07_practice_02_inherit/inherit_combined.cpp
)


# homework