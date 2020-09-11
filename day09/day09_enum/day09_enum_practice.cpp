/*

需求：

 * 枚举
 *  练习：
	一个容器<vector>里面有若干个学生 ，现在需要统计一下
	里面的男生有多少个，女生有多少个。 请使用枚举来定义性别。


*/



#include <iostream>
#include <vector>

enum class Gender
{
	MALE,
	FEMALE
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


int cal_total_male(const std::vector<Student>& student_vector);

int main() {

	std::cout << "..in day09_enum_practice...\n";

	std::vector<Student> student_vector{
		{"jacob_1", Gender::MALE},
		{"anna_1", Gender::FEMALE},
		{"jacob_2", Gender::MALE},
		{"anna_2", Gender::FEMALE},
		{"jacob_3", Gender::MALE},
		{"jacob_4", Gender::MALE},
		{"anna_3", Gender::FEMALE},
		{"jacob_5", Gender::MALE},
		{"anna_4", Gender::FEMALE},
	};

	int total_male = cal_total_male(student_vector);

	std::cout << "..total male student::\t" << total_male
		<< ", total female student::\t" << student_vector.size() - total_male
		<< "\n";

	return 0;
}

int cal_total_male(const std::vector<Student>& student_vector) {

	int total_male{ 0 };
	
	for (Student stu : student_vector) {
		if (stu.gender == Gender::MALE) {
			total_male++;
		}
	}


	return total_male;
}


/*

output 

..in day09_enum_practice...
..total male student::  5, total female student::       4

*/