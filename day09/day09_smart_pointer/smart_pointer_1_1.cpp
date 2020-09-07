/*

需求：

 * 唯一指针
 *  unique_ptr;
 *     特点：
 *          1. 禁止拷贝，但是允许移动
 *          2. unique_ptr 实际上是一个类，但是说它是智能指针，只是因为它帮我们管理了原来的原始指针
 *              为了不脱离指针的用法，所以它的内部重载 * 和 ->  符号。

 创建一个 Student 类


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

	// 使用唯一指针有参构造函数声明并初始化一个int类型
	std::unique_ptr<int> u_ptr_int(new int(30));

	// 尝试拷贝指针
	//std::unique_ptr<int> u_ptr_int_copy = u_ptr_int;	// 报错

	// 尝试移动指针
	std::unique_ptr<int> u_ptr_int_move = std::move(u_ptr_int);	// 成功 u_ptr_int 的数据移动到 u_ptr_int_move, u_ptr_int 指针空间析构

	// 取值
	//int* p_up = u_ptr_int.get();		// up_ptr 移动了，里面的数据给了 u_ptr_int_move
	//std::cout << ".. *p_up = " << *p_up << "\n";	// read access violation, p_up was nullptr

	int* p_up = u_ptr_int_move.get();
	std::cout << ".. *p_up = " << *p_up << "\n";	// .. *p_up = 30，解引用，可以取值


	// 使用唯一指针有参构造函数声明并初始化一个 Student 类型
	std::unique_ptr<Student> u_ptr_student(new Student("jacob"));

	std::cout << ".. 学生姓名::\t" << u_ptr_student->name << "\n";	// .. 学生姓名::   jacob

	return 0;

}

