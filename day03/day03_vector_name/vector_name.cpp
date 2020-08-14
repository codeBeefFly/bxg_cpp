/*

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
	std::cout << "..in vector_name..." << std::endl;


	// 创建一个 std::vector<student> 类型指针 
	std::vector<student> * student_vector;
	createContainer(&student_vector);	// 将指针的地址传递给函数


	student stu_a;
	stu_a.name = "a";

	student stu_b;
	stu_b.name = "b";

	student stu_c;
	stu_c.name = "c";

	
	// 通过解引用得到 std::vector<student> 类型对象
	(*student_vector).push_back(stu_a);
	(*student_vector).push_back(stu_b);
	(*student_vector).push_back(stu_c);


	//打印
	for (student s : *student_vector) {
		std::cout << "..student name :: " << s.name << "\n";
	}



	// 手动释放堆内存空间
	delete student_vector;


	return 0;
}


void createContainer(std::vector<student>** student_vector) {

	*student_vector = new std::vector<student>;		// 在堆中开辟一个 std::vector<student> 类型的空间

}