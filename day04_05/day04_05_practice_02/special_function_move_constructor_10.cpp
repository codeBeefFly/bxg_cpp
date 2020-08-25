/*

��ָ����ʹ���ƶ����캯��

*/

#include <iostream>


class Student {

public:
	std::string* item;

	
	// ����
	Student() : Student("ipad3") {
		std::cout << "..�޲ι��캯��...\n";
	}


	// �вι���
	Student(std::string name) : item{ new std::string("ipad3") }{
		std::cout << "..���ι��캯��...\n";
	}


	// �������캯����ǳ��������ֵƥ�䵽��������
	Student(const Student& stu) {
		std::cout << "..�������캯��...\n";
		item = stu.item;
	}


	// �ƶ����캯������ֵƥ�䵽�ƶ�����
	Student(Student&& stu) {
		std::cout << "..�ƶ����캯��...\n";
		item = stu.item;
		stu.item = nullptr;			// ������������������Ȩ
	}


};


Student createStu() {
	std::cout << "..��������...\n";
	Student stu;
	stu.item = new std::string("ipad3");
	return stu;
}


int main() {

	std::cout << "..in special_function_move_constructor_10...\n";

	{
		Student stu = createStu();
		std::cout << "*stu.item = " << *stu.item << "\n";
	}

	{
		Student stu = createStu();
		Student stu_b = stu;

		std::cout << "*stu_b.item = " << *stu_b.item << "\n";
		std::cout << "*stu.item = " << *stu.item << "\n";
	}

	{
		Student stu = createStu();
		Student stu_b = std::move(stu);

		std::cout << "*stu_b.item = " << *stu_b.item << "\n";
		std::cout << "*stu.item = " << *stu.item << "\n";
	}

	return 0;
}


/*

output:

..in special_function_move_constructor_10...
..��������...
..���ι��캯��...
..�޲ι��캯��...
..�ƶ����캯��...
*stu.item = ipad3
..��������...
..���ι��캯��...
..�޲ι��캯��...
..�ƶ����캯��...
..�������캯��...
*stu_b.item = ipad3
*stu.item = ipad3
..��������...
..���ι��캯��...
..�޲ι��캯��...
..�ƶ����캯��...
..�ƶ����캯��...
*stu_b.item = ipad3
*stu.item =

*/
