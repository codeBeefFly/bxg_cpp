/*

����


ȫ�֣�

initStudent	 ����ѧ��vector����ƥ����ʦ
initTeacher

updateStudent ͨ��ѧ�Ÿ���ƥ�����ʦ�γ�
printStudent  ����ѧ��vector, ʹ��������������ѧ��vector


Class Student	������ѧ�ţ���ʦ����
Class Teacher	���������䣬�γ�


*/


#include <iostream>
#include <vector>
#include "Teacher.h"
#include "Student.h"



void init_teacher_student(std::vector<Teacher*>& teacher_vector, std::vector<Student*>& student_vector);
void initTeacher(std::vector<Teacher*>& teacher_vector);
void initStudent(std::vector<Student*>& student_vector, std::vector<Teacher*>& teacher_vector);

void updateStudent(std::vector<Student*> student_vector);
void printStudent(std::vector<Student*>& student_vector, void (*print)(std::vector<Student*>& student_vector));

//std::istream& istream(std::istream& in, Teacher& teacher);
//std::ostream& ostream(std::ostream& out, Teacher& teacher);
//
//std::istream& istream(std::istream& in, Student& student, Teacher& teacher);	// TODO
//std::istream& istream(std::istream& in, Student& student);
//std::ostream& ostream(std::ostream& out, Student& student);

int main() {

	std::cout << "..in teacher_student_vector...\n";


	// ��������
	std::vector<Student*> student_vector;
	std::vector<Teacher*> teacher_vector;


	// ��ʼ����ʦ��ѧ��
	init_teacher_student(teacher_vector, student_vector);


	// ��ӡѧ��
	printStudent(
		student_vector,
		[](std::vector<Student*>& student_vector) {
			for (Student* stu : student_vector) {
				// ���ѧ����Ϣ
				std::cout << *stu;
			}
		}
	);


	// ����ѧ��
	updateStudent(student_vector);


	// ��ӡѧ��
	printStudent(
		student_vector,
		[](std::vector<Student*>& student_vector) {
			for (Student* stu : student_vector) {
				// ���ѧ����Ϣ
				std::cout << *stu;
			}
		}
	);


	return 0;
}


void printStudent(std::vector<Student*>& student_vector, void (*print)(std::vector<Student*>& student_vector)) {
	print(student_vector);
}


void init_teacher_student(std::vector<Teacher*>& teacher_vector, std::vector<Student*>& student_vector) {
	initTeacher(teacher_vector);
	initStudent(student_vector, teacher_vector);
}


void initTeacher(std::vector<Teacher*>& teacher_vector){
	// ������ʦ
	for (int i = 0; i < 3; i++) {
		Teacher* teacher = new Teacher;
		std::cout << "..������ʦ����Ϣ�����������䡢�γ̣�::\t";
		std::cin >> *teacher;

		teacher_vector.push_back(teacher);
	}

}


void initStudent(std::vector<Student*>& student_vector, std::vector<Teacher*>& teacher_vector) {
	// ����ѧ��
	for (int i = 0; i < 3; i++) {
		Student* student = new Student;
		std::cout << "..����ѧ������Ϣ��������id��::\t";
		std::cin >> *student;

		// ���±�ƥ����ʦ
		student->teacher = teacher_vector[i];

		student_vector.push_back(student);
	}
}


void updateStudent(std::vector<Student*> student_vector) {
	std::cout << "..������Ҫ�޸ĵ�ѧ�� [ѧ��] �Լ� �� [ѧ��]::\t";
	std::string tmp_id, tmp_subject;
	std::cin >> tmp_id >> tmp_subject;

	for (Student* stu : student_vector) {
		// TODO
		if (stu->id == tmp_id) {
			stu->teacher->subject = tmp_subject;
		}
	}
}



/*

output:


..in teacher_student_vector...
..log::Teacher �вι���...
..������ʦ����Ϣ�����������䡢�γ̣�::  a 1 aa
..log::Teacher �вι���...
..������ʦ����Ϣ�����������䡢�γ̣�::  b 1 bb
..log::Teacher �вι���...
..������ʦ����Ϣ�����������䡢�γ̣�::  c 1 cc
..log::Teacher �вι���...
..log::Student ���캯��...
..����ѧ������Ϣ��������id��::  jacob 111
..log::Teacher �вι���...
..log::Student ���캯��...
..����ѧ������Ϣ��������id��::  raptor 222
..log::Teacher �вι���...
..log::Student ���캯��...
..����ѧ������Ϣ��������id��::  king 333
jacob, 111, aa
raptor, 222, bb
king, 333, cc
..������Ҫ�޸ĵ�ѧ�� [ѧ��] �Լ� �� [ѧ��]::    111 dd
jacob, 111, dd
raptor, 222, bb
king, 333, cc


*/