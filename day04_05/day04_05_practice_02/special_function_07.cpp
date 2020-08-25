/*

触发拷贝构造函数的场景
1. 对象的创建依赖其他对象
2. 函数参数（传递对象）
3. 函数返回值（返回对象）

*/


#include<iostream>


class Student_Trigger {

public:
	std::string name;

	// 构造，无参
	Student_Trigger() {
		std::cout << "..无参构造...\n";
	}

	// 构造，有参
	Student_Trigger(std::string name) : name{ name } {
		std::cout << "..有参构造...\n";
	}

	// 拷贝构造
	Student_Trigger(const Student_Trigger& stu) {
		std::cout << "..拷贝构造...\n";
		
		name = stu.name;	//值 = 值
	}

	// 析构
	~Student_Trigger() {
		std::cout << "..析构...\n";
	}


};


/*

情形二：函数传参

*/
void printStu(Student_Trigger stu) {		// 发生对象的拷贝
	std::cout << "..student name:: " << stu.name << "\n";
}


/*

情形三：函数返回对象

*/
//Student_Trigger createStudent() {
//	Student_Trigger stu;
//	return stu;
//}

// 如果不想发生拷贝的话，写成返回引用的形式
Student_Trigger& createStudent() {
	//Student_Trigger stu;	// 这样写栈空间释放后，如果返回在栈空间创建的对象的引用，会报错，因为对象在执行完此函数后已经析构了
	Student_Trigger* stu = new Student_Trigger;
	return *stu;
}


int main() {

	std::cout << "..in special_function_07...\n";

	//// 情形一
	//Student_Trigger stu_a("jacob");
	//Student_Trigger stu_b = stu_a;

	//// 情形二
	//printStu(stu_b);


	// 情形十三
	Student_Trigger stu_c = createStudent();

	return 0;
}


/*

..in special_function_07...
..有参构造...
..拷贝构造...
..拷贝构造...
..student name:: jacob
..析构...
..无参构造...
..拷贝构造...
..析构...
..析构...
..析构...
..析构... 


..in special_function_07...
..无参构造...
..拷贝构造...
..析构...
..析构...

*/