/*
C++ �ڶ������⺯����ί�й��캯��
��ʼ���б�ʽ��ֵ

{} ��ֵ������������խ����ֹ���Ƚ���

*/

#include<iostream>


class Student {		// �����������������ϵĹ��캯�����вΣ��޲�  
public:
	std::string name;
	int age;

	/*
	
	
	/// ��ʼ���б�ʽ��ֵ+Ĭ��ֵ��һ��Ĺ��캯��д��
	//1. �޲ι��캯��
	Student() {
		std::cout << "..�޲ι��캯��...\n";
		// ��ʼĬ��ֵ
		name = "unknown";
		age = 0;
	}

	//2. �вι��캯����1������
	Student(std::string name) : name(name), age(18) {	// ��ʼ���б�ֵ��age��ʼ��Ĭ��ֵ
		std::cout << "..�вι��캯����1����...\n";
	}

	//3. �вι��캯����2������
	Student(std::string name, int age) : name(name), age(age) {
		std::cout << "..�вι��캯����2������...\n";
	}
	
	
	*/


	///ί�й��캯����д��
	Student() : Student("unknown", 18) {							// ����޲εĹ��캯��ί��һ�������εĹ��캯����һ�����޲�ί���в�
		std::cout << "..�޲ι��캯����ί��д��...\n";
	}

	Student(std::string name) : Student(name, 18) {					// ���1���εĹ��캯��ί��һ�������εĹ��캯��
		std::cout << "..�вι��캯����1���Σ�ί��д��...\n";
	}

	//ί�й��캯������һ���б��ʼ���ķ�ʽд
	Student(std::string name, int age) : name(name), age(age) {		// ���������������ί�й��캯��
		std::cout << "..�вι��캯����2���Σ�ί��д��...\n";
	}

};


int main() {

	std::cout << "..in special_function_02...\n";


	// �޲�
	Student stu_a;

	// 1����
	Student stu_b("jacob");

	// ������
	Student stu_c("raptor", 19);
	return 0;
}