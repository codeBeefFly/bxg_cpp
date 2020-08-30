/*

����

������ֵ���������

�ƶ���ֵ��������أ���Ҫ���ԱΪָ������

�������ָ�����͵����Ա

*/


#include <iostream>
#include <vector>


class Student
{
public:

	std::string* name = nullptr;
	int age;

	Student();
	Student(std::string name, int age);
	~Student();

	//Student& operator=(Student& stu_right);		// ������ֵ���������
	void operator=(const Student& stu_right);		// ������ֵ���������

	//Student& operator=(Student&& stu_right) {};	// �ƶ���ֵ���������
	void operator=(Student&& stu_right0);			// �ƶ���ֵ���������

};


Student::Student() : Student("unknown", 0)
{
	std::cout << "..�޲ι��캯��...\n";
}


Student::Student(std::string name, int age) 
	: name{ new std::string{name} }
	, age{ age } {
	std::cout << "..�вι��캯��...\n";
}


Student::~Student()
{
	std::cout << "..��������...\n";
	delete name;
	name = nullptr;
}


// ������ֵ�����������ڲ���ǰ���� const ,
//Student& Student::operator=(Student& stu_right) {
void Student::operator=(const Student& stu_right) {		// ������ stu1 = stu2; ����ʱ�������������
	std::cout << "..������ֵ�������������...\n";

	// ���Ա������ֵ���룬ǳ��������δ�����֤ok
	//*this->name = *stu_right.name;
	//this->age = stu_right.age;

	// ���Ա����ֵ�ƴ��룬����������г�Ա���ڶ�̬��Աʱ��ָ�룩��ǳ������������⣬ʹ�����
	this->name = new std::string(*stu_right.name);		// ���п��ٿռ䣬���� *stu_right.name ֵ��ʼ��
	this->age = stu_right.age;
}


void Student::operator=(Student&& stu_right) {			// �ƶ���ֵ��������أ�Ҳֻ�������ָ�����
	std::cout << "..�ƶ���ֵ�������������...\n";

	// 1. �ȷ����Լ����ڵĿռ�
	delete this->name;

	// 2. �����ڵĶ���ָ��Դ����Ŀռ�
	this->name = stu_right.name;

	// ע: ����Ҫ new �ռ�


	// 4. ��Դ����Ŀռ�����Ȩ����
	stu_right.name = nullptr;


}




int main() {

	std::cout << "..in operator_overload_copy_move_01...\n";

	Student stu1{ "jacob", 10 };
	//Student stu2{ "raptor", 20 };
	Student stu3{ "king", 30 };

	//std::cout << "..stu1.name::\t" << *stu1.name << ", stu1.age::\t" << stu1.age << ".\n";
	//std::cout << "..stu2.name::\t" << *stu2.name << ", stu2.age::\t" << stu2.age << ".\n";
	//std::cout << "..stu3.name::\t" << *stu3.name << ", stu3.age::\t" << stu3.age << ".\n";

	//stu1 = stu2;

	std::cout << "..stu1.name::\t" << *stu1.name << ", stu1.age::\t" << stu1.age << ".\n";
	//std::cout << "..stu2.name::\t" << *stu2.name << ", stu2.age::\t" << stu2.age << ".\n";
	std::cout << "..stu3.name::\t" << *stu3.name << ", stu3.age::\t" << stu3.age << ".\n";

	stu1 = std::move(stu3);

	std::cout << "..stu1.name::\t" << *stu1.name << ", stu1.age::\t" << stu1.age << ".\n";
	//std::cout << "..stu2.name::\t" << *stu2.name << ", stu2.age::\t" << stu2.age << ".\n";
	std::cout << "..stu3.name::\t" << *stu3.name << ", stu3.age::\t" << stu3.age << ".\n";		// *stu3.name �޷���ʾ����Ϊ�ռ��Ѿ��ͷ�


	return 0;
}																												



/*

output:

..in operator_overload_copy_move_01...
..�вι��캯��...
..�вι��캯��...
..stu1.name::   jacob, stu1.age::       10.
..stu3.name::   king, stu3.age::        30.
..�ƶ���ֵ�������������...
..stu1.name::   king, stu1.age::        10.
..stu3.name::


*/
