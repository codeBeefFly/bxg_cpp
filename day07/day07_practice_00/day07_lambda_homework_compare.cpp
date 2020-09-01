/*

 * lambda表达式 的使用场景
 * 现在要比较两个学生的大小，可以按照名字多少排序比较、也可以按照年龄比较、也可以按照身高比较。
 * 定义一个全局函数compare , 接收三个参数，参数一和参数二 为要比较的学生对象，
 * 参数三为比较逻辑的函数 函数指针（此应该使用lambda表达式来写，根据lambda表达式的返回值来决定谁大谁小。）


 只比较年龄

*/


#include <iostream>
#include <vector>


class Student {

public:

	std::string name;
	int age;

	Student() : Student("unknown", 0) {};

	Student(std::string name, int age) : name{ name }, age{ age }{};

};


// 常规调用写法
int compare_student_01(Student stu_a, Student stu_b);

// 函数指针写法，函数指针是 lambda 函数
int compare_student_02(Student stu_a, Student stu_b, bool (*compare)(std::string stu_name_a, std::string stu_name_b));

// 函数指针写法，将上面的函数按步骤写出，返回值如果是 bool 那么就要返回 true，false
int compare_student_03(Student stu_a, Student stu_b, bool (*compare)(std::string stu_name_a, std::string stu_name_b));




int main() {

	std::cout << "..in day07_lambda_homework_compare...\n";

	Student stu_a("jacob_lee", 10);
	Student stu_b("raptor", 20);

	// 调用常规写法
	int normal_result = compare_student_01(stu_a, stu_b);
	std::cout << "..normal_result = " << normal_result << "\n";
	std::cout << "..normal_result std::boolalpha = " << std::boolalpha << normal_result << "\n";

	// lambda 函数指针写法
	int compare_result_01 = compare_student_02(stu_a, stu_b, [](std::string name_a, std::string name_b) {
		if (name_a == name_b) {
			return true;
		}
		else if (name_a > name_b) {
			return false;
		}
		else if (name_a < name_b) {
			return false;
		}
	});
	std::cout << "..compare_result_01 = " << compare_result_01 << "\n";


	// lambda 函数指针写法，将上面的写法按步骤写出
	// step1: 接收 lambda 函数，是一个 bool 类型的函数指针
	auto compare = [](std::string name_a, std::string name_b) {
		if (name_a == name_b) {
			return true;
		}
		else if (name_a > name_b) {
			return false;
		}
		else if (name_a < name_b) {
			return false;
		}
	};

	// step2: 调用带函数指针的函数，传递函数指针的时候不需要给这个函数指针传递参数
	//compare_student_03(Student stu_a, Student stu_b, compare(stu_a.name, stu_b.name));	// 怎么能这样写呢，主函数体中调用函数，只用给这个函数传实参就行了，给类型干嘛
	int compare_result_02 = compare_student_03(stu_a, stu_b, compare);
	std::cout << "..compare_result_02 = " << compare_result_02 << "\n";


	return 0;
}


int compare_student_01(Student stu_a, Student stu_b) {
	if (stu_a.name == stu_b.name) {
		return 1;
	}
	else if (stu_a.name > stu_b.name) {
		return 0;
	}
	else if (stu_a.name < stu_b.name) {
		return -1;
	}
}


int compare_student_02(Student stu_a, Student stu_b, bool (*compare)(std::string stu_name_a, std::string stu_name_b)) {
	return compare(stu_a.name, stu_b.name);
}


// 创建比较函数，函数指针函数接收类对象string类型成员，并返回这个函数指针
int compare_student_03(Student stu_a, Student stu_b, bool (*compare)(std::string stu_name_a, std::string stu_name_b)) {
	return compare(stu_a.name, stu_b.name);
}


/*

..in day07_lambda_homework_compare...
..normal_result = -1
..normal_result std::boolalpha = -1
..compare_result_01 = 0
..compare_result_02 = 0

*/