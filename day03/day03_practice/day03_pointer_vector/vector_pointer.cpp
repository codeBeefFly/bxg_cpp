/*
需求

二级指针的练习

有一个vector指针， 用于存储3个学生张三、李四、王五， 
该vector的指针创建工作交由createContainer 函数来创建，
并且该函数没有返回值。通过函数参数的方式，来创建外部vector指针。

*/

#include <iostream>
#include <vector>


struct student {
	std::string name;
};


void createContainer(std::vector<student> ** student_vector);


int main() {
	std::cout << "..in vector_pointer...\n";

	std::vector<student> * student_vector;

	createContainer(&student_vector);
	
	student stu_a;
	stu_a.name = "jacob";

	student stu_b;
	stu_b.name = "raptor";

	student stu_c;
	stu_c.name = "king";


	(*student_vector).push_back(stu_a);
	(*student_vector).push_back(stu_b);
	(*student_vector).push_back(stu_c);


	// 打印
	for (student s : (*student_vector)) {
		std::cout << "..student name :: " << s.name << "\t";
	}


	return 0;
}


void createContainer(std::vector<student> ** student_vector) {

	*student_vector = new std::vector<student>;

}