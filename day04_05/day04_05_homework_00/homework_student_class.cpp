/*

定义一个学生类，包含 属性： 姓名、年龄 ， 行为：读书、跑步。

3. 使用初始化列表的方式完成对  姓名和 年龄的赋值工作。
4. 在main.cpp中分别调用跑步和读书的函数，打印内容形如：  18岁的张三在读书...

*/



#include<iostream>

class Student {
private:
	std::string name;
	int age;


public:
	Student() : Student("unknown", 0) {}

	Student(std::string name, int age) : name(name), age(age) {
		std::cout << "..调用构造函数...\n";
	}

	~Student() {
		std::cout << "..调用析构函数...\n";
	}

	void read() {
		std::cout << ".." << age << "的" << name << "在看书...\n";
	}

	void run() {
		std::cout << ".." << age << "的" << name << "在跑步...\n";
	}

};


void createStudent(Student** stu, std::string name, int age) {	// 参数为指向指针的指针
	*stu = new Student("jacob", 18);			// 对指向指针的指针解引用，得到指针中存储的地址中的student类对象
}


int main() {

	Student* stu;								// 创建一个指向 Student 类对象的指针
	createStudent(&stu, "jacob", 18);			// 将这个指针的地址传递
	(*stu).read();								
	(*stu).run();
	delete stu;

	return 0;
}




/*

..调用构造函数...
..18的jacob在看书...
..18的jacob在跑步...
..调用析构函数...


*/