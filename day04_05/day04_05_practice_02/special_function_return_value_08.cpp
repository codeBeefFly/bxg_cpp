/*

c++ �Ͻ����������ڲ��Ĵ����ջ�ڴ�ľֲ��������û���ָ�룬
��Ϊ����һ��ִ����ϣ���ô�ڲ������пռ䶼���ᱻ�ͷţ�
��ʱ����������������ֵ�������ִ���������ʱ����ʱ�����Ĺ����ͱ�ò��ɱ��⡣

*/

#include<iostream>

//ѧ����
class Student {
public:
	std::string name;
	int age;

	Student() : name{ "unknown" }, age{ 0 }{
		std::cout << "..log::�޲ι��캯��...\n";
	};
};

//������ͨ����
Student createStudent_normal() {
	Student stu;
	stu.name = "jacob";
	stu.age = 10;

	return stu;
}

//����ָ����󣬴���д��
Student* createStudent_pointer() {
	Student stu;
	stu.name = "jacob";
	stu.age = 10;

	return &stu;			// C4172 returning address of local variable or temporary : stu 
}


// ����ָ�������ȷд��
Student* createStudent_pointer_right() {
	Student* stu = new Student;
	stu->name = "jacob";
	stu->age = 10;

	return stu;				// stu �洢�����������ڶ��еĵ�ַ�������ַ������
}

//�������ö���
Student& createStudent_reference() {
	Student stu;
	stu.name = "jacob";
	stu.age = 10;

	return stu;				// C4172 returning address of local variable or temporary : stu
}

int main() {
	
	std::cout << "..in special_function_return_value...\n";

	Student stu_a = createStudent_normal();

	Student* stu_b = createStudent_pointer();

	Student* stu_b_right = createStudent_pointer_right();

	Student& stu_c = createStudent_reference();	//��˵����д���Ա�������󿽱�

	return 0;
}

