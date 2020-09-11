/*

����

�޶�ö�������е�ʹ��


ö�ٵ�Ŀ�ģ����ӳ���Ŀɶ��ԡ�
ö���������Ҳ����������ô�֮һ������������״̬����


Gender::MALE, Gender::FEMALE

*/


#include <iostream>


enum class Gender
{				 
	MALE,
	FEMALE,
};



class Student
{
public:

	std::string name;
	Gender gender;

	Student();
	Student(std::string name, Gender gender);
	~Student();


};

Student::Student() : Student("unknown", Gender::MALE)
{

}


Student::Student(std::string name, Gender gender)
	: name{ name }
	, gender{ gender }{

}


Student::~Student()
{

}


int main() {

	std::cout << "..in day09_enum_class_02...\n";

	Student stu_1("jacob", Gender::MALE);
	Student stu_2("anna", Gender::FEMALE);


	// ʹ����Ԫ�����
	std::cout << "..student 1:: name::\t" << stu_1.name
		<< ", gender::\t" << ((int)stu_1.gender == 0 ? "male" : "female")
		<< "\n";

	std::cout << "..student 2:: name::\t" << stu_2.name
		<< ", gender::\t" << ((int)stu_2.gender == 0 ? "male" : "female")
		<< "\n";

	return 0;
}


/*

..in day09_enum_class_02...
..student 1:: name::    jacob, gender:: male
..student 2:: name::    anna, gender::  female

*/