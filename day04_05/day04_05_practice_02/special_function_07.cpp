/*

�����������캯���ĳ���
1. ����Ĵ���������������
2. �������������ݶ���
3. ��������ֵ�����ض���

*/


#include<iostream>


class Student_Trigger {

public:
	std::string name;

	// ���죬�޲�
	Student_Trigger() {
		std::cout << "..�޲ι���...\n";
	}

	// ���죬�в�
	Student_Trigger(std::string name) : name{ name } {
		std::cout << "..�вι���...\n";
	}

	// ��������
	Student_Trigger(const Student_Trigger& stu) {
		std::cout << "..��������...\n";
		
		name = stu.name;	//ֵ = ֵ
	}

	// ����
	~Student_Trigger() {
		std::cout << "..����...\n";
	}


};


/*

���ζ�����������

*/
void printStu(Student_Trigger stu) {		// ��������Ŀ���
	std::cout << "..student name:: " << stu.name << "\n";
}


/*

���������������ض���

*/
//Student_Trigger createStudent() {
//	Student_Trigger stu;
//	return stu;
//}

// ������뷢�������Ļ���д�ɷ������õ���ʽ
Student_Trigger& createStudent() {
	//Student_Trigger stu;	// ����дջ�ռ��ͷź����������ջ�ռ䴴���Ķ�������ã��ᱨ����Ϊ������ִ����˺������Ѿ�������
	Student_Trigger* stu = new Student_Trigger;
	return *stu;
}


int main() {

	std::cout << "..in special_function_07...\n";

	//// ����һ
	//Student_Trigger stu_a("jacob");
	//Student_Trigger stu_b = stu_a;

	//// ���ζ�
	//printStu(stu_b);


	// ����ʮ��
	Student_Trigger stu_c = createStudent();

	return 0;
}


/*

..in special_function_07...
..�вι���...
..��������...
..��������...
..student name:: jacob
..����...
..�޲ι���...
..��������...
..����...
..����...
..����...
..����... 


..in special_function_07...
..�޲ι���...
..��������...
..����...
..����...

*/