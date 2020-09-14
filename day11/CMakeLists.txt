cmake_minimum_required(VERSION 3.15)

project(day11_container_functionObject_thread)

# practice container
add_executable(
	day11_container_00_deque
	day11_container/day11_container_deque.cpp
)
add_executable(
	day11_container_01_forwardList
	day11_container/day11_container_forwardList.cpp
)
add_executable(
	day11_container_02_iterator
	day11_container/day11_container_iterator.cpp
)
add_executable(
	day11_container_03_iterator_2
	day11_container/day11_container_iterator_2.cpp
)
add_executable(
	day11_container_04_pair
	day11_container/day11_container_pair.cpp
)
add_executable(
	day11_container_05_map
	day11_container/day11_container_map.cpp
)
add_executable(
	day11_container_06_map_2
	day11_container/day11_container_map_2.cpp
)
add_executable(
	day11_container_07_set
	day11_container/day11_container_set.cpp
)
add_executable(
	day11_container_07_sort
	day11_container/day11_container_sort.cpp
)


# practice function object
add_executable(
	day11_function_object_00_simple
	day11_function/day11_function_object_00_simple.cpp
)
add_executable(
	day11_function_object_01_global_lambda
	day11_function/day11_function_object_01_global_lambda.cpp
)
add_executable(
	day11_function_object_02_class_member
	day11_function/day11_function_object_02_class_member.cpp
)
add_executable(
	day11_function_object_03_functionCall
	day11_function/day11_function_object_03_functionCall.cpp
)



# practice bind
add_executable(
	day11_bind_00_simple
	day11_function/day11_bind_00_simple.cpp
)
add_executable(
	day11_bind_01_member_function
	day11_function/day11_bind_01_member_function.cpp
)
add_executable(
	day11_bind_02_member_function_placeHolder
	day11_function/day11_bind_02_member_function_placeHolder.cpp
)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# practice thread
add_executable(
	day11_thread_00_simple_thread_bind
	day11_thread/day11_thread_00_simple_thread_bind.cpp
)
add_executable(
	day11_thread_01_detach
	day11_thread/day11_thread_01_detach.cpp
)
add_executable(
	day11_thread_02_thread_id
	day11_thread/day11_thread_02_thread_id.cpp
)
add_executable(
	day11_thread_03_thread_end
	day11_thread/day11_thread_03_thread_end.cpp
)
add_executable(
	day11_thread_04_mutex
	day11_thread/day11_thread_04_mutex.cpp
)