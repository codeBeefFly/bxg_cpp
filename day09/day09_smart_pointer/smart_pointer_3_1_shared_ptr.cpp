/*

����

��֤ shared_ptr ���÷�����

1. ����һ�� Student �࣬��Ա name���й�������

2. �� main ���ó��淽ʽ����һ�� Student ��ָ�룬�ڶ��ڴ��У���ʹ���вι����ʼ�������

3. ʹ�� shared_ptr �����װ Student �����

4. ʹ�� shared_ptr �����װ shared_ptr ����

5. shared_ptr ���Կ����������ƶ�

5. ʹ�� shared_ptr �ƶ�һ�� shared_ptr

6. ʹ��һ�� shared_ptr ȡֵ�����ַ�ʽ get()��

7. �ͷţ��ͷţ��ͷ�ָ��

*/


#include <iostream>
#include <memory>


class Student {


public:

	std::string name;

	Student() = default;
	Student(std::string name) : name{ name } {
		std::cout << "..log::�вι��캯��...\n";
	}
	~Student() {
		std::cout << "..log::��������...\n";
	}

};


int main() {

	std::cout << "..in smart_pointer_3_1_shared_ptr...\n";

	// һ����ʽ�ڶ��д�������
	Student* student = new Student("jacob");

	// ����һ������ָ�룬������ѧ���������вι���ķ�ʽ
	std::shared_ptr<Student> s_ptr_stu_1(student);
	
	std::cout << "..s_ptr_stu_1 ����::\t" << s_ptr_stu_1.use_count() << "\n";

	// ����һ������ָ�룬����������ָ��
	std::shared_ptr<Student> s_ptr_stu_2 = s_ptr_stu_1;

	std::cout << "..s_ptr_stu_1 ����::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << "..s_ptr_stu_2 ����::\t" << s_ptr_stu_2.use_count() << "\n";


	// ����һ������ָ�룬���ƶ�����ָ��
	std::shared_ptr<Student> s_ptr_stu_3 = std::move(s_ptr_stu_2);

	std::cout << "..s_ptr_stu_1 ����::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << "..s_ptr_stu_2 ����::\t" << s_ptr_stu_2.use_count() << "\n";
	std::cout << "..s_ptr_stu_3 ����::\t" << s_ptr_stu_3.use_count() << "\n";


	// ȡֵ�����ַ�ʽ
	// ����ָ�� s_ptr_stu_3
	std::cout << "..ѧ������::\t" << s_ptr_stu_3.get()->name << "\n";
	std::cout << "..ѧ������::\t" << (*s_ptr_stu_3).name << "\n";
	std::cout << "..ѧ������::\t" << s_ptr_stu_3->name << "\n";

	//// ����ָ�� s_ptr_stu_2��������ָ��
	//std::cout << "..ѧ������::\t" << s_ptr_stu_2.get()->name << "\n";	
	//std::cout << "..ѧ������::\t" << (*s_ptr_stu_2).name << "\n";
	//std::cout << "..ѧ������::\t" << s_ptr_stu_2->name << "\n";


	// ����ָ�� s_ptr_stu_1
	std::cout << "..ѧ������::\t" << s_ptr_stu_1.get()->name << "\n";
	std::cout << "..ѧ������::\t" << (*s_ptr_stu_1).name << "\n";
	std::cout << "..ѧ������::\t" << s_ptr_stu_1->name << "\n";


	// �ͷ�����ָ��
	s_ptr_stu_1.reset();	// ���°�ָ�뵽��ָ��
	std::cout << ".. s_ptr_stu_1 ����::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << ".. s_ptr_stu_2 ����::\t" << s_ptr_stu_2.use_count() << "\n";
	std::cout << ".. s_ptr_stu_3 ����::\t" << s_ptr_stu_3.use_count() << "\n";

	s_ptr_stu_3.reset();	// ���°�ָ�뵽��ָ��
	std::cout << ".. s_ptr_stu_1 ����::\t" << s_ptr_stu_1.use_count() << "\n";
	std::cout << ".. s_ptr_stu_2 ����::\t" << s_ptr_stu_2.use_count() << "\n";
	std::cout << ".. s_ptr_stu_3 ����::\t" << s_ptr_stu_3.use_count() << "\n";


	return 0;
}


/*


output:

..in smart_pointer_3_1_shared_ptr...
..log::�вι��캯��...
..s_ptr_stu_1 ����::    1
..s_ptr_stu_1 ����::    2
..s_ptr_stu_2 ����::    2
..s_ptr_stu_1 ����::    2
..s_ptr_stu_2 ����::    0
..s_ptr_stu_3 ����::    2
..ѧ������::    jacob
..ѧ������::    jacob
..ѧ������::    jacob
..ѧ������::    jacob
..ѧ������::    jacob
..ѧ������::    jacob
.. s_ptr_stu_1 ����::   0
.. s_ptr_stu_2 ����::   0
.. s_ptr_stu_3 ����::   1
..log::��������...
.. s_ptr_stu_1 ����::   0
.. s_ptr_stu_2 ����::   0
.. s_ptr_stu_3 ����::   0


*/