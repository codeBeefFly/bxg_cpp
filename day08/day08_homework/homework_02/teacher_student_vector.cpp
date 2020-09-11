/*

需求


全局：

initStudent	 接收学生vector，并匹配老师
initTeacher

updateStudent 通过学号更改匹配的老师课程
printStudent  接收学生vector, 使用匿名函数操作学生vector


Class Student	姓名，学号，老师对象
Class Teacher	姓名，年龄，课程


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


	// 创建容器
	std::vector<Student*> student_vector;
	std::vector<Teacher*> teacher_vector;


	// 初始化老师，学生
	init_teacher_student(teacher_vector, student_vector);


	// 打印学生
	printStudent(
		student_vector,
		[](std::vector<Student*>& student_vector) {
			for (Student* stu : student_vector) {
				// 输出学生信息
				std::cout << *stu;
			}
		}
	);


	// 更新学生
	updateStudent(student_vector);


	// 打印学生
	printStudent(
		student_vector,
		[](std::vector<Student*>& student_vector) {
			for (Student* stu : student_vector) {
				// 输出学生信息
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
	// 三个老师
	for (int i = 0; i < 3; i++) {
		Teacher* teacher = new Teacher;
		std::cout << "..输入老师的信息（姓名、年龄、课程）::\t";
		std::cin >> *teacher;

		teacher_vector.push_back(teacher);
	}

}


void initStudent(std::vector<Student*>& student_vector, std::vector<Teacher*>& teacher_vector) {
	// 三个学生
	for (int i = 0; i < 3; i++) {
		Student* student = new Student;
		std::cout << "..输入学生的信息（姓名、id）::\t";
		std::cin >> *student;

		// 按下标匹配老师
		student->teacher = teacher_vector[i];

		student_vector.push_back(student);
	}
}


void updateStudent(std::vector<Student*> student_vector) {
	std::cout << "..输入需要修改的学生 [学号] 以及 新 [学科]::\t";
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
..log::Teacher 有参构造...
..输入老师的信息（姓名、年龄、课程）::  a 1 aa
..log::Teacher 有参构造...
..输入老师的信息（姓名、年龄、课程）::  b 1 bb
..log::Teacher 有参构造...
..输入老师的信息（姓名、年龄、课程）::  c 1 cc
..log::Teacher 有参构造...
..log::Student 构造函数...
..输入学生的信息（姓名、id）::  jacob 111
..log::Teacher 有参构造...
..log::Student 构造函数...
..输入学生的信息（姓名、id）::  raptor 222
..log::Teacher 有参构造...
..log::Student 构造函数...
..输入学生的信息（姓名、id）::  king 333
jacob, 111, aa
raptor, 222, bb
king, 333, cc
..输入需要修改的学生 [学号] 以及 新 [学科]::    111 dd
jacob, 111, dd
raptor, 222, bb
king, 333, cc


*/