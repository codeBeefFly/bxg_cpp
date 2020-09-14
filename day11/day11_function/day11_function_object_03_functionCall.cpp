/*

����

����һ�� Student �࣬������ run eat ����

����һ��ȫ�ֵĺ��� printStu�����պ�������+�������Ϊ����

��main ��ʹ�ú��� printStu ���� ���е���������

*/



#include <iostream>
#include <functional>


class Student {
public:
	void eat(){
		std::cout << "jacob is eating...\n";
	}

	void run() {
		std::cout << "jacob is runnning...\n";
	}
	void sleep() {
		std::cout << "jacob is sleeping...\n";
	}
};



void printStudent(Student student, std::function<void(Student)> f_student) {
	f_student(student);
}

void printStudent(Student* student, std::function<void(Student*)> f_student) {
	f_student(student);
}

void printStudent(Student& student, std::function<void(Student&)> f_student) {
	f_student(student);
}



int main() {

	std::cout << "..in day11_function_object_03_functionCall...\n";

	// ����ѧ����ĺ�������
	std::function<void(Student)> f_sleep = &Student::sleep;
	std::function<void(Student*)> f_eat = &Student::eat;
	std::function<void(Student&)> f_run = &Student::run;

	// ͨ���ص���������ѧ��������������ȴ���ѧ�������
	Student stu_jacob;
	printStudent(stu_jacob, f_sleep);

	printStudent(&stu_jacob, f_eat);

	printStudent(stu_jacob, f_run);


	return 0;

}


/*

output


..in day11_function_object_03_functionCall...
jacob is sleeping...
jacob is eating...
jacob is runnning...


*/