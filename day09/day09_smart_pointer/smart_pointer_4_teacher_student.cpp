/*

����

1. ����һ�� teacher �࣬
	1. ����˽�г�Ա ����ָ�� Student ����
	2. ������Ա
		1. setStu -- ���� shared_ptr
		2. 

*/



#include <iostream>
#include <memory>

class Teacher;
class Student;


class Teacher {

private:
	// ����ѧ�����͹���ָ��
	std::shared_ptr<Student> s_ptr_student;

public:
	Teacher() {
		std::cout << "..log::Teacher ����...\n";
	}
	~Teacher() {
		std::cout << "..log::Teacher ����...\n";
	}

	void setStudent(std::shared_ptr<Student> s_ptr_student) {
		this->s_ptr_student = s_ptr_student;	// ����ָ����Կ���
	}

};



class Student {

private:
	// ����ѧ�����͹���ָ��
	std::shared_ptr<Teacher> s_ptr_teacher;

public:
	Student() {
		std::cout << "..log::Student ����...\n";
	}
	~Student() {
		std::cout << "..log::Student ����...\n";
	}

	void setTeacher(std::shared_ptr<Teacher> s_ptr_teacher) {
		this->s_ptr_teacher = s_ptr_teacher;	// ����ָ����Կ���
	}

};



int main() {

	std::cout << "..in smart_pointer_4_teacher_student...\n";

	// ��ͨ��ʽ���� Teacher Student �����
	Teacher* teacher = new Teacher;
	Student* student = new Student;

	// ʹ�ù���ָ�������ָͨ��
	std::shared_ptr<Teacher> s_ptr_teacher(teacher);
	std::shared_ptr<Student> s_ptr_Student(student);

	// ѧ����ʦ����
	teacher->setStudent(s_ptr_Student);
	student->setTeacher(s_ptr_teacher);



	return 0;

}


/*

output

ֻ�й��� û������

..in smart_pointer_4_teacher_student...
..log::Teacher ����...
..log::Student ����...


*/