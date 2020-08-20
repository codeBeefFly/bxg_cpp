/*
类特殊函数--拷贝构造函数 02 [vip]
*/

#include<iostream>


class Student {
public:
	std::string name;
	int age;

	Student() : Student("unknown", 0) {		// 调用委托构造函数
		std::cout << "..无参构造函数...\n";
	}

	Student(std::string name, int age) : name{ name }, age{ age }{
		std::cout << "..有参构造函数...\n";
	}

	//拷贝构造函数，如果不是手动创建拷贝构造函数，程序会自动创建拷贝构造函数，下面是拷贝构造函数的标准写法
	//把已有的对象数据，这里是 stu 赋值到创建的对象身上，这里通过拷贝构造函数创建
	Student(const Student& stu) {			// 这里的 stu 是等号右边的类对象(如果不是引用，就又拷贝了，无限循环),const 表示数据不能改
		std::cout << "..拷贝构造函数...\n";
		std::cout << "姓名:: " << stu.name << ", 年龄:: " << stu.age << "\n";

		// 开始拷贝类成员, 对类对象的成员进行赋值
		//name = stu.name;		// name 前面隐藏了一个单词 this，表示这个对象本身	this 指针。
		//age = stu.age;

		this->name = stu.name;	// 两种写法都可以，使用 this 写法 可以同名赋值 this->name = name;
		this->age = stu.age;
	}


	Student(const Student& stu) : name{ stu.name }, age{ stu.age }{
		std::cout << "..拷贝构造函数，使用列表初始化给拷贝对象成员赋值...\n";
		std::cout << "姓名:: " << stu.name << ", 年龄:: " << stu.age << "\n";
	}

	~Student() {
		std::cout << "..析构函数...\n";
	}
};


int main() {
	std::cout << "..in special_function_04...\n";

	Student stu_a("jacob", 18);
	Student stu_b("raptor", 18);

	Student stu_c = stu_a;					// "=" 调用拷贝构造函数
	std::cout << "stu_c对象姓名:: " << stu_c.name << ", 年龄:: " << stu_c.age << "\n";

	return 0;
}


/*

output:

.in special_function_04...
..有参构造函数...
..有参构造函数...
..拷贝构造函数...
stu_c对象姓名:: , 年龄:: -858993460
..析构函数...
..析构函数...
..析构函数...

*/