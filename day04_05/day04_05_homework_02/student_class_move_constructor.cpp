/*

����һ��ѧ���࣬���ڷ���  (int * ����) �� �ȴ���������ʵ�� ��Ȼ��ͨ���ƶ�����ķ�ʽ�������ġ�

1. ��������
2. move������ʽ��

*/


#include <iostream>

class Student {

public:
	std::string name;
	int* score = nullptr;


	// �޲ι���
	Student() : Student("unknown", 0) {
		std::cout << "..log::�޲ι���...\n";
	}

	// һ�ι���
	Student(std::string name) : Student(name, 0) {
		std::cout << "..log::һ�ι���...\n";
	}

	// ���ι���
	Student(std::string name, int score) : name{ name }, score{ new int{score} } {
		std::cout << "..log::���ι���...\n";
	}

	// �������죬��ֵ��ֵ
	Student(const Student& stu) {
		std::cout << "..log::��������...\n";

		//name = stu.name;
		//score = stu.score;		// ��ַ����ַ

		name = stu.name;
		score = new int(*stu.score);
	}

	// �ƶ����죬��ֵ��ֵ
	Student(Student&& stu) {
		std::cout << "..log::�ƶ�����...\n";

		name = stu.name;
		score = stu.score;
		score = nullptr;
	}

	// ����
	~Student() {
		std::cout << "..log::��������...\n";
		delete score;
		score = nullptr;
	}

};


int main() {
	
	std::cout << "..in student_class_move_constructor...\n";

	Student stu_a("zhangsan", 10);
	Student stu_b = std::move(stu_a);		// �ƶ�������ԭ�����ٻ�ȡ��ǰ��ָ��ֵ�ᱨ��

	std::cout << "stu_a.name:: " << stu_a.name << ", *stu_a.score:: " << *stu_a.score << "\n";
	std::cout << "stu_b.name:: " << stu_b.name << ", *stu_b.score:: " << *stu_b.score << "\n";	// ���ܻ�ȡԭ�����ָ��ֵ


	return 0;
}


/*

..in student_class_move_constructor...
..log::���ι���...
..log::�ƶ�����...
stu_a.name:: zhangsan, *stu_a.score:: 10
stu_b.name:: zhangsan, *stu_b.score::
D:\W_workPlace\bxg_cpp\day04_05\build\Debug\day04_05_homework_student_class_move_constructor.exe (process 7268) exited with code -1073741819.
Press any key to close this window . . .


*/