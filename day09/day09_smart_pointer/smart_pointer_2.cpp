/*

����

����ָ������һ�㶼�Ƕ��ڴ�ָ��

*/


#include <iostream>
#include <memory>


class Student {

public:

	std::string name;
	
	Student() {
		std::cout << "..log Student �޲ι��캯��...\n";
	}
	Student(std::string name) : name{ name } {
		std::cout << "..log Student �вι��캯��...\n";
	}
	~Student() {
		std::cout << "..log Student ��������...\n";
	}

};


int main() {

	std::cout << "..in smart_pointer_2...\n";

	{
		// ����һ��Ψһָ��
		std::unique_ptr<int> u_ptr_int;

		// ����һ��һ����ʽ��int ָ��
		int* ptr_int = new int(3);

		// ����ָ��
		/*
		
		�滻���������

		1) ����ָ�� *this ����������ָ�� current_ptr �����������ж����Դ�˳��
			1. ���浱ǰָ��ĸ��� old_ptr = current_ptr
			2. �Բ�����д��ǰָ�� current_ptr = ptr
			3. ����ָ��ǿգ���ɾ����ǰ����Ķ��� if(old_ptr != nullptr) get_deleter()(old_ptr) ��
		
		*/
		u_ptr_int.reset(ptr_int);

		std::cout << ".. u_ptr_int.get() = " << *u_ptr_int.get() << "\n";	// get() ���� ptr��.. u_ptr_int.get() = 3


	}


	{
		// �ڶ��ڴ洴��һ�� Student ���Ͷ��󲢳�ʼ��
		Student* student_1 = new Student("jacob");
		Student* student_2 = new Student("raptor");

		// ����һ��Ψһָ�벢�ӹ����studentָ��
		std::unique_ptr<Student> u_ptr_student_1(student_1);	// �������� Ψһָ���Զ��ͷű������ָ��

		// ��reset ����
		/*
		
		reset() �����������в���������û�в���
		�в����ᣬ�ͷ���ǰ��ָ��ָ��Ŀռ䣬Ȼ��ת�����ڵ�ָ��
		û�в������ͷ���ǰ��ָ�룬��ɿ�ָ��


		//����ʹ��reset��ʽ�ͷ��ڴ档
		p3.reset();

		//���°��µ�ָ��
		p3.reset(new int(6));	// p3 ��Ψһָ�룬���°�ָ���Ψһָ��ͻ�����ӹ����ָ��
		

		*/
		std::unique_ptr<Student> u_ptr_student_2;	
		u_ptr_student_2.reset(student_2);


		std::cout << ".. *u_ptr_student_1->name::\t" << u_ptr_student_1->name << "\n";
		std::cout << ".. *u_ptr_student_2->name::\t" << u_ptr_student_2->name << "\n";

	}

	return 0;
}


/*


output:

..in smart_pointer_2...
.. u_ptr_int.get() = 3
..log Student �вι��캯��...
..log Student �вι��캯��...
.. *u_ptr_student_1->name::     jacob
.. *u_ptr_student_2->name::     raptor
..log Student ��������...
..log Student ��������...


*/