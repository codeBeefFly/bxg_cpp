cmake_minimum_required(VERSION 3.15)

project(day09_smartPointer_macro_enum)

# practice smart pointer
add_executable(
	day09_smart_pointer_0
	day09_smart_pointer/smart_pointer_0.cpp
)
add_executable(
	day09_smart_pointer_1
	day09_smart_pointer/smart_pointer_1.cpp
)
add_executable(
	day09_smart_pointer_1_1
	day09_smart_pointer/smart_pointer_1_1.cpp
)
add_executable(
	day09_smart_pointer_2
	day09_smart_pointer/smart_pointer_2.cpp
)
add_executable(
	day09_smart_pointer_3
	day09_smart_pointer/smart_pointer_3.cpp
)
add_executable(
	day09_smart_pointer_3_1_shared_ptr
	day09_smart_pointer/smart_pointer_3_1_shared_ptr.cpp
)
add_executable(
	day09_smart_pointer_4_teacher_student_ex
	day09_smart_pointer/smart_pointer_4_teacher_student_ex.cpp
)
add_executable(
	day09_smart_pointer_4_teacher_student
	day09_smart_pointer/smart_pointer_4_teacher_student.cpp
)
add_executable(
	day09_smart_pointer_4_teacher_student_s_w
	day09_smart_pointer/smart_pointer_4_teacher_student_s_w.cpp
)

# practice dynamic memory allocation, TODO


# practice macro
add_executable(
	day09_macro_variable
	day09_macro/macro_variable.cpp
)
add_executable(
	day09_macro_condition
	day09_macro/macro_condition.cpp
)

# practice enumerator
add_executable(
	day09_enumerator_class
	day09_enum/day09_enum_class_00.cpp
)
add_executable(
	day09_enumerator_class_01
	day09_enum/day09_enum_class_01.cpp
)
add_executable(
	day09_enumerator_class_02
	day09_enum/day09_enum_class_02.cpp
)
add_executable(
	day09_enumerator_practice
	day09_enum/day09_enum_practice.cpp
)

# practice exception
add_executable(
	day09_exception_00
	day09_exception/day09_exception_00.cpp
)
add_executable(
	day09_exception_01
	day09_exception/day09_exception_01.cpp
)
add_executable(
	day09_exception_02
	day09_exception/day09_exception_02.cpp
)
add_executable(
	day09_exception_03
	day09_exception/day09_exception_03.cpp
)

# homework human teacher student
add_executable(
	day09_homework_student_teacher
	day09_homework/day09_student_teacher_main.cpp
	day09_homework/Teacher.cpp
	day09_homework/Teacher.h
	day09_homework/Student.cpp
	day09_homework/Student.h
	day09_homework/Human.h
)
add_executable(
	day09_homework_student_teacher_ex
	day09_homework_2/main.cpp
	day09_homework_2/Student.cpp
	day09_homework_2/Student.h
	day09_homework_2/Teacher.cpp
	day09_homework_2/Teacher.h
	day09_homework_2/Human.h
)

add_executable(
	day09_homework_student_teacher_ex_2
	day09_homework_3/main.cpp
	day09_homework_3/stu.cpp
	day09_homework_3/stu.h
	day09_homework_3/teacher.cpp
	day09_homework_3/teacher.h
	day09_homework_3/human.h
)