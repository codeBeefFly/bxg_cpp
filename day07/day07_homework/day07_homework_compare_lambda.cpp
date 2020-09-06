/*

需求：

 * 现在要比较两个学生的大小，可以按照名字多少排序比较、也可以按照年龄比较、也可以按照身高比较。
定义一个全局函数compare , 接收三个参数，参数一和参数二 为要比较的学生对象，参数三为lambda表达式

如果姓名一样，则比较年龄，
如果年龄一样，则表示两者相等，
否则打印两人的大小。


比较函数：

int compare(Student stu_1, Student stu_2, bool (*fun)(std::string name_1, std::string name_2))

使用 lambda
[](){};	返回函数指针

[](){}(); 返回值


// 重写

*/




#include <iostream>


class Student {

public:
	std::string name;
	int age;

	Student() = default;
	Student(std::string name, int age) : name{ name }, age{ age }{}

};


int compare(Student stu_1, Student stu_2, int (*compare_student)(Student stu_1, Student stu_2));


int main() {

	std::cout << "..in day07_homework_compare_lambda...\n";

	Student stu_1("jacob", 10);
	Student stu_2("raptor", 20);

	int result = compare(
		stu_1, stu_2,
		[](Student stu_1, Student stu_2) {
			if (stu_1.name > stu_2.name) {
				return 1;
			}
			else if (stu_1.name == stu_2.name) {
				if (stu_1.age > stu_2.age) {
					return 1;
				}
				else if (stu_1.age == stu_2.age) {
					return 0;
				}
				else {
					return -1;
				}
			}
			else {
				return -1;
			}
		}
	);

	if (result > 0) {
		std::cout << "..stu1 bigger...\n";
	}
	else if (result == 0) {
		std::cout << "..both equal...\n";
	}
	else {
		std::cout << "..stu2 bigger...\n";
	}


	return 0;
}


int compare(Student stu_1, Student stu_2, int (*compare_student)(Student stu_1, Student stu_2)) {
	return compare_student(stu_1, stu_2);
}


/*

..in day07_homework_compare_lambda...
..stu2 bigger...


*/
