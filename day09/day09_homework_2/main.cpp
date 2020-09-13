/*

����

����ҵ

student_teacher


*/



#include <iostream>
#include <vector>
#include "Student.h"
#include "Teacher.h"

int main() {

	std::cout << "..in day09_homework_student_teacher_ex...\n";

	// ��ʦ��������ʹ�� shared_ptr
	std::vector<std::shared_ptr<Teacher>> teacher_vector{
		std::make_shared<Teacher>("teacher_a", "math"),
		std::make_shared<Teacher>("teacher_b", "english"),
		std::make_shared<Teacher>("teacher_c", "chinese"),
	};


	// ѧ����������ʹ�� shared_ptr
	std::vector<std::shared_ptr<Student>> student_vector{
		std::make_shared<Student>("student_a", "10086", Gender::MALE),
		std::make_shared<Student>("student_b", "10087", Gender::FEMAL),
		std::make_shared<Student>("student_c", "10088", Gender::MALE),
	};

	// ѧ��������ʦ����ʦ����ѧ��
	for (int i = 0; i < student_vector.size(); i++) {
		// ���±��ó� �����е� stu + teach �Ĺ���ָ��
		std::shared_ptr<Teacher> sp_teacher = teacher_vector[i];
		std::shared_ptr<Student> sp_student = student_vector[i];

		sp_student->setTeacher(sp_teacher);
		sp_teacher->setStudent(sp_student);
	}


	// ��ӡѧ��+��ʦ
	for (std::shared_ptr<Student>& sp_student : student_vector) {
		sp_student->work();
	}


	return 0;
}