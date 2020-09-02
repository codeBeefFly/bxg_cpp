/*

需求：

类中有其他类对象时的初始化，只能使用初始化列表的方式。不能使用委托构造函数的形式。

类构造函数只能初始化自己的类成员，不能初始化继承的类成员



	3. 手动调用父类的构造

		注意！！！！！
			子类里面的任何一个构造函数都会隐式的调用父类的无参构造
			如果父类不存在无参构造，那么一定要在子类的构造中手动指定调用有参构造

		class father{
		public:
			father(string name){}
		}

		class son :public father{
			son():father("张三"){
				//father("张三"); //不对的！！禁止！！错误的！！！
			}

		}

*/


#include <iostream>


class A {

public:

	int number;
	std::string color;

	A() : A(0, "unknown_color") { 
		std::cout << "..A 无参构造函数...\n";  
	}
	A(int number, std::string color) : number{ number }, color{ color } {
		std::cout << "..A 有参构造函数...\n";
	}

	~A() {
		std::cout << "..A 析构函数...\n";
	}

};


class Father {

public:

	std::string name;

	Father() : Father("unknown") {
		std::cout << "..Father 无参构造...\n";
	}
	Father(std::string name) : name{ name } {
		std::cout << "..Father 有参构造...\n";
	}

	~Father() {
		std::cout << "..Father 析构函数...\n";
	}

};


class Son : public Father {
public:

	A a;


	//Son() : Son(a(0, "unknown_color", "unknwon") {
	//	std::cout << "..Son 无参构造函数...\n";
	//}

	//类中含有其他类的对象成员，如果要初始化，只能使用初始化类列表方式。
	Son() : a(0, "unknown_color") {
		std::cout << "..Son 无参构造函数...\n";
	}

	//Son(A a, std::string name) : a(0), name{ name }{	// 子类在构造函数中不能初始化父类的成员
	Son(A a) : a(0, "unknown_color"){	// 在类中初始化类对象的方式，初始化类中类对象为无参构造形式
		std::cout << "..Son 有参构造...\n";
	}

	~Son() {
		std::cout << "..Son 析构函数...\n";
	}
};



int main() {

	std::cout << "..inherit_object_in_class...\n";

	Son s;

	return 0;
}



/*

..inherit_object_in_class...
..Father 有参构造...   //因为father的无参构造委托了有参构造
..Father 无参构造...
..A 有参构造函数...
..Son 无参构造函数...
..Son 析构函数...
..A 析构函数...
..Father 析构函数...

*/