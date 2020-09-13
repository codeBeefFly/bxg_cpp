/*

需求：

抄作业

student_teacher


*/



#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"

int main() {

	std::cout << "..in day09_homework_student_teacher_ex...\n";

	// 教师的容器，使用 shared_ptr
	std::vector<std::shared_ptr<Teacher>> teacher_vector{
		std::make_shared<Teacher>("teacher_a", "math"),
		std::make_shared<Teacher>("teacher_b", "english"),
		std::make_shared<Teacher>("teacher_c", "chinese"),
	};


	// 学生的容器，使用 shared_ptr
	std::vector<std::shared_ptr<Student>> student_vector{
		std::make_shared<Student>("student_a", "10086", Gender::MALE),
		std::make_shared<Student>("student_b", "10087", Gender::FEMAL),
		std::make_shared<Student>("student_c", "10088", Gender::MALE),
	};

	// 学生关联教师，教师关联学生
	for (int i = 0; i < student_vector.size(); i++) {
		// 用下标拿出 容器中的 stu + teach 的共享指针
		std::shared_ptr<Teacher> sp_teacher = teacher_vector[i];
		std::shared_ptr<Student> sp_student = student_vector[i];

		sp_student->setTeacher(sp_teacher);
		sp_teacher->setStudent(sp_student);
	}


	// 打印学生+教师
	for (std::shared_ptr<Student>& sp_student : student_vector) {
		sp_student->work();
	}


	return 0;
}