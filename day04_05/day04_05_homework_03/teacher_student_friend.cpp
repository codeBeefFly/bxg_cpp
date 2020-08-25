/*

��ϰ��ҵ��

��ʦ�ذ�ѧ������ѧ��Ϊ�Լ������ѣ����ǳ��е��£�
��ʦ���Լ��ĳ���������ѧ����Ͼʱ���� cooking �� 
��ʹ����Ԫ�ĸ����Ƹ���Ϊ��

*/


#include <iostream>

class Teacher {

private:

	std::string kitchen;


public:

	Teacher() {
		std::cout << "..�޲ι��캯��...\n";
	}

	Teacher(std::string kitchen) : kitchen{ kitchen } {
		std::cout << "..�вι��캯��...\n";
	}

	//void cooking() {
	//	std::cout << "..cooking in the [" << kitchen << "]\n";
	//}

	friend class Student;

};


class Student {

public:

	void cooking(Teacher t) {	// ����ʹ����Ԫ���еı���
		std::cout << "..cooking in the [" << t.kitchen << "]\n";
	}

};


int main() {

	std::cout << "..teacher_student_friend...\n";

	Teacher t("teacher's kitchen");

	Student s;
	s.cooking(t);

	return 0;
}


/*

..teacher_student_friend...
..�вι��캯��...
..cooking in the [teacher's kitchen]

*/