/*

����

 * Ψһָ��
 *  unique_ptr;
 *     �ص㣺
 *          1. ��ֹ���������������ƶ�
 *          2. unique_ptr ʵ������һ���࣬����˵��������ָ�룬ֻ����Ϊ�������ǹ�����ԭ����ԭʼָ��
 *              Ϊ�˲�����ָ����÷������������ڲ����� * �� ->  ���š�

 ����һ�� Student ��


 */



#include <iostream>
#include <memory>


class Student {
	
public:

	std::string name;
	
	Student() = default;
	Student(std::string name) : name{ name } {}
	~Student() {}

};


int main() {

	std::cout << "..in smart_pointer...\n";

	// ʹ��Ψһָ���вι��캯����������ʼ��һ��int����
	std::unique_ptr<int> u_ptr_int(new int(30));

	// ���Կ���ָ��
	//std::unique_ptr<int> u_ptr_int_copy = u_ptr_int;	// ����

	// �����ƶ�ָ��
	std::unique_ptr<int> u_ptr_int_move = std::move(u_ptr_int);	// �ɹ� u_ptr_int �������ƶ��� u_ptr_int_move, u_ptr_int ָ��ռ�����

	// ȡֵ
	//int* p_up = u_ptr_int.get();		// up_ptr �ƶ��ˣ���������ݸ��� u_ptr_int_move
	//std::cout << ".. *p_up = " << *p_up << "\n";	// read access violation, p_up was nullptr

	int* p_up = u_ptr_int_move.get();
	std::cout << ".. *p_up = " << *p_up << "\n";	// .. *p_up = 30�������ã�����ȡֵ


	// ʹ��Ψһָ���вι��캯����������ʼ��һ�� Student ����
	std::unique_ptr<Student> u_ptr_student(new Student("jacob"));

	std::cout << ".. ѧ������::\t" << u_ptr_student->name << "\n";	// .. ѧ������::   jacob

	return 0;

}

