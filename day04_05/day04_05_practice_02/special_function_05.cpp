/*
�����⺯��--�������캯�� 02 [vip]
*/

#include<iostream>


class Student {
public:
	std::string name;
	int age;

	Student() : Student("unknown", 0) {		// ����ί�й��캯��
		std::cout << "..�޲ι��캯��...\n";
	}

	Student(std::string name, int age) : name{ name }, age{ age }{
		std::cout << "..�вι��캯��...\n";
	}

	//�������캯������������ֶ������������캯����������Զ������������캯���������ǿ������캯���ı�׼д��
	//�����еĶ������ݣ������� stu ��ֵ�������Ķ������ϣ�����ͨ���������캯������
	Student(const Student& stu) {			// ����� stu �ǵȺ��ұߵ������(����������ã����ֿ����ˣ�����ѭ��),const ��ʾ���ݲ��ܸ�
		std::cout << "..�������캯��...\n";
		std::cout << "����:: " << stu.name << ", ����:: " << stu.age << "\n";

		// ��ʼ�������Ա, �������ĳ�Ա���и�ֵ
		//name = stu.name;		// name ǰ��������һ������ this����ʾ���������	this ָ�롣
		//age = stu.age;

		this->name = stu.name;	// ����д�������ԣ�ʹ�� this д�� ����ͬ����ֵ this->name = name;
		this->age = stu.age;
	}


	Student(const Student& stu) : name{ stu.name }, age{ stu.age }{
		std::cout << "..�������캯����ʹ���б��ʼ�������������Ա��ֵ...\n";
		std::cout << "����:: " << stu.name << ", ����:: " << stu.age << "\n";
	}

	~Student() {
		std::cout << "..��������...\n";
	}
};


int main() {
	std::cout << "..in special_function_04...\n";

	Student stu_a("jacob", 18);
	Student stu_b("raptor", 18);

	Student stu_c = stu_a;					// "=" ���ÿ������캯��
	std::cout << "stu_c��������:: " << stu_c.name << ", ����:: " << stu_c.age << "\n";

	return 0;
}


/*

output:

.in special_function_04...
..�вι��캯��...
..�вι��캯��...
..�������캯��...
stu_c��������:: , ����:: -858993460
..��������...
..��������...
..��������...

*/