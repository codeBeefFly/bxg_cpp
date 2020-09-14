cmake_minimum_required(VERSION 3.15)

project(day12_threadConcurrency)

# practice concurrency
add_executable(
	day12_concurrency_00_moveBox_simple_ex
	day12_thread_concurrency/day12_concurrency_00_moveBox_ex.cpp	
)
add_executable(
	day12_concurrency_01_moveBox_OOD
	day12_thread_concurrency/day12_concurrency_01_moveBox_OOD.cpp	
)
add_executable(
	day12_concurrency_02_lockguard
	day12_thread_concurrency/day12_concurrency_02_lockguard.cpp	
)
add_executable(
	day12_concurrency_03_unique_lock
	day12_thread_concurrency/day12_concurrency_03_unique_lock.cpp	
)