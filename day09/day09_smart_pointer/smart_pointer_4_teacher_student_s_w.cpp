/*

����

1. ����һ�� Teacher ��
	1. ˽������Student ���� ����ָ��
	2. �����������죬������setStudent

2. ����һ�� Student ��
	1. ˽������Teacher ���� ����ָ��
	2. �����������죬������setTeacher


Ϊ�˱���`shared_ptr`�Ļ����������⣬��Ҫ����һ����ָ��weak_ptr`��
��ָ��һ����`shared_ptr`����Ķ������Ӱ����ָ������������ڣ�
Ҳ���ǽ�һ��`weak_ptr`�󶨵�һ��`shared_ptr`����ı�`shared_ptr`�����ü�����
�����Ƿ���`weak_ptr`ָ��һ�����һ��ָ������`shared_ptr`�����٣�
����ͻᱻ�ͷš�������Ƕȿ���`weak_ptr`������`shared_ptr`��һ�����ֶ���������ָ�롣

week_ptr ��������shared_ptr�ļ��������ҿ��Խ���shared_ptr


*/



#include <iostream>
#include <memory>


class Teacher;
class Student;


class Teacher {

private:
	
	std::shared_ptr<Student> s_ptr_student;

public:
	
	Teacher() {
		std::cout << "..log::Teacher ����...\n";
	}
	~Teacher() {
		std::cout << "..log::Teacher ����...\n";
	}

	void setStudent(std::shared_ptr<Student> s_ptr_student) {
		this->s_ptr_student = s_ptr_student;
	}


};


class Student {

private:

	std::weak_ptr<Teacher> s_ptr_teacher;	// ֻ��Ҫ�ڳ�Ա������ weak_ptr �����Ķ��� shared_ptr

public:

	Student() {
		std::cout << "..log::Student ����...\n";
	}
	~Student() {
		std::cout << "..log::Student ����...\n";
	}

	void setTeacher(std::shared_ptr<Teacher> s_ptr_Teacher) {
		this->s_ptr_teacher = s_ptr_Teacher;
	}


};


int main() {

	std::cout << "..in smart_pointer_4_teacher_student_s_w...\n";

	// ��ͨ��ʽ���� Teacher Student �����ڶѿռ�
	Teacher* teacher = new Teacher;
	Student* student = new Student;

	// ʹ�ù���ָ�������ָͨ��
	std::shared_ptr<Teacher> s_ptr_teacher(teacher);	// Student ������ weak_ptr<Teacher>
	std::shared_ptr<Student> s_ptr_student(student);

	// ��ʦѧ������
	teacher->setStudent(s_ptr_student);
	student->setTeacher(s_ptr_teacher);


	return 0;

}



/*

output

..in smart_pointer_4_teacher_student_s_w...
..log::Teacher ����...
..log::Student ����...
..log::Teacher ����...
..log::Student ����...

*/