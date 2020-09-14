/*

可以理解为把函数 、函数的实参以及调用函数的对象打包绑定到一起。
然后用一个变量来接收它，这个变量也就是这些个打包好的整体。


需求：

定义一个 Student 类，有 eat 函数 两参 food where

使用 函数对象 接收 bind 类对象函数，并使用 无参 function<> 输出 eat 函数

使用占位符 placeholders 对缺省参数进行填充，并在调用时补上


*/


#include <iostream>
#include <functional>


class Student {
public:

	void eat(std::string where, std::string food) {
		std::cout << "..jacob eat " << food << " at " << where << "\n";
	}

};



void printStu_arg_0(std::function<void()> f_eat_0) {
	f_eat_0();
}


void printStu_arg_1(std::function<void(std::string)> f_eat_1) {
	f_eat_1("hello");
}


void printStu_arg_2(std::function<void(Student, std::string, std::string)> f_eat_2,
	Student stu, std::string where, std::string food) {
	f_eat_2(stu, where, food);
}



int main() {

	std::cout << "..in day11_bind_02_memeber_function_placeHolder...\n";

	{
		// 使用 函数对象
		std::function<void(Student, std::string, std::string)> f_eat_2 = &Student::eat;			// 走有参

		Student stu_jacob;
		f_eat_2(stu_jacob, "canteen", "breakfast");
		printStu_arg_2(f_eat_2, stu_jacob, "canteen", "breakfast");
	}

	{
		// 使用绑定
		Student stu_raptor;
		auto p_eat_2 = std::bind(&Student::eat, stu_raptor, "home", "banana");
		p_eat_2();
		printStu_arg_0(p_eat_2);
	}

	{
		Student stu_king;
		//std::function<void(Student, std::string, std::string)> f_eat_2 = std::bind(&Student::eat, stu_king, "home", "banana");
		std::function<void()> f_eat_2 = std::bind(&Student::eat, stu_king, "home", "banana");	// bind 已经把对象+函数+参数打包了，所以函数对象为无参
		f_eat_2();
		printStu_arg_0(f_eat_2);
	}


	//{
	//	// 验证 place holder
	//	Student stu_haha;
	//	//std::function<void(Student, std::string, std::string)> f_eat_2 = std::bind(&Student::eat, stu_king, "home", "banana");
	//	std::function<void(std::string)> f_eat_2 = std::bind(&Student::eat, stu_haha, "home", std::placeholders::_1);	// bind 已经把对象+函数+参数打包了，所以函数对象为无参
	//	//f_eat_2("home");
	//	//printStu_arg_0(f_eat_2);
	//}

	return 0;

}



/*


output:

..in day11_bind_02_memeber_function_placeHolder...
..jacob eat breakfast at canteen
..jacob eat breakfast at canteen
..jacob eat banana at home
..jacob eat banana at home
..jacob eat banana at home
..jacob eat banana at home



*/



//#include <iostream>
//#include <functional>
//
//using namespace std;
//
///*
// * bind
// *      2. 绑定成员函数
// */
//
//class stu {
//
//public:
//    void eat(string where, string food) {
//        cout << "学生在" << where << " 吃 " << food << endl;
//    }
//};
//
//void printStu(function <void(stu, string)> f, stu s) {
//
//    f(s, "红烧鱼");
//}
//
//
//
//int main() {
//
//    stu s;
//    stu& s1 = s;
//    stu* s2 = &s;
//
//    //占位符，告诉编译器，这里语法是没问题的，只是没有实质的参数值。
//    //回头调用的时候，必须要传递参数进来
//    //按照没有给的未知的参数来确定， 从1开始。
//    auto f = bind(&stu::eat, s2, "宿舍", placeholders::_1);
//    f("吃米线");
//
//    printStu(bind(&stu::eat, s2, "食堂", placeholders::_1));
//    return 0;
//}
//
