/*

浅拷贝：类中的成员是指针类型，改变其中一个类的指针成员

*/


#include<iostream>


class Student_Shallow {

public:
	std::string name;
	int age;

	Student_Shallow() {
		std::cout << "..Student_Shallow无参构造函数...\n";
	}

	Student_Shallow(std::string name_val, int age_val) {
		std::cout << "..Student_Shallow有两参构造函数...\n";
		name = name_val;
		age = age_val;
	}

	// 浅拷贝，如果成员有指针，使用浅拷贝会导致改变一个类型对象成员，另一个类型对象成员也改变
	Student_Shallow(const Student_Shallow& stu) {
		std::cout << "..Student_Shallow拷贝构造函数...\n";
		name = stu.name;
		age = stu.age;
	}

	~Student_Shallow() {
		std::cout << "..Student_Shallow析构函数...\n";
	}
};


class Student_Deep {
public:

	//std::string* name = nullptr;
	std::string* name = new std::string;
	int age;

	Student_Deep() {
		std::cout << "..Student_Deep无参构造函数...\n";
	}

	Student_Deep(std::string name_val, int age_val) {	// 类对象传入的参数是一个string类
		std::cout << "..Student_Deep有两参构造函数...\n";
		*name = name_val;
		age = age_val;
	}

	/*
	
	// 浅拷贝，如果成员有指针，使用浅拷贝会导致改变一个类型对象成员，另一个类型对象成员也改变
	Student_Deep(const Student_Deep& stu) {
		std::cout << "..Student_Deep浅拷贝构造函数...\n";
		//*name = stu.name;
		name = stu.name;	// 为什么不变？ stu.name 是地址，*stu.name 是值，所以 name(地址) = stu.name(地址)
		age = stu.age;
	}
	
	*/

	// 深拷贝，两个指针成员一定要有各自的内存空间（地址）
	Student_Deep(const Student_Deep& stu) {
		std::cout << "..Student_Deep深拷贝构造函数...\n";
		*name = *stu.name;
		age = stu.age;
	}

	~Student_Deep() {
		std::cout << "..Student_Deep析构函数...\n";
	}


};


class Student_Deep_Nullptr {
public:																									   

	std::string* name = nullptr;	// 类中成员为空指针，空指针不能解引用，内存报错
	int age;

	Student_Deep_Nullptr() {
		std::cout << "..Student_Deep_Nullptr无参构造函数...\n";
	}

	Student_Deep_Nullptr(std::string name_val, int age_val) {	// 类对象传入的参数是一个string类
		std::cout << "...Student_Deep_Nullptr有两参构造函数...\n";

		//给指针赋值，使指针指向一个非空空间

		/* 复杂写法
		
		name = new std::string;
		*name = name_val;	// 值 = 值
		
		*/

		name = new std::string(name_val);	// 简洁写法
		age = age_val;
	}


	// 深拷贝
	Student_Deep_Nullptr(const Student_Deep_Nullptr& stu) {
		std::cout << "..Student_Deep_Nullptr深拷贝构造函数...\n";
	
		/* 浅拷贝写法
		
		////给指针开辟堆空间
		//name = new std::string();
		
		//name = stu.name;	// 这里使地址
		//age = stu.age;
		
		*/

		////给指针开辟堆空间，这段代码是对的
		//name = new std::string();

		//*name = *stu.name;
		//age = stu.age;

		name = new std::string(*stu.name);	// 值 = 值

	}

	~Student_Deep_Nullptr() {
		std::cout << "..Student_Deep_Nullptr析构函数...\n";
	}


};

int main() {

	std::cout << "..in special_function_06...\n";

	{	// 浅拷贝

		std::cout << "..浅拷贝...\n";

		Student_Shallow stu_a("jacob", 18);

		Student_Shallow stu_b = stu_a;

	}

	{	// 深拷贝
		
		std::cout << "..深拷贝...\n";

		Student_Deep stu_a("jacob", 18);

		Student_Deep stu_b = stu_a;

		std::cout << *stu_a.name << ", " << stu_a.age << "\n";		// 因为地址一样嘛，所以改一个，必改另一个
		std::cout << *stu_b.name << ", " << stu_b.age << "\n";

		*stu_b.name = "raptor";

		std::cout << *stu_a.name << ", " << stu_a.age << "\n";
		std::cout << *stu_b.name << ", " << stu_b.age << "\n";


	}

	{	// 深拷贝，类中的指针为 nullptr

		std::cout << "..深拷贝，类中的指针为 nullptr...\n";

		Student_Deep_Nullptr stu_a("jacob", 18);

		Student_Deep_Nullptr stu_b = stu_a;

		std::cout << *stu_a.name << ", " << stu_a.age << "\n";		// 因为地址一样嘛，所以改一个，必改另一个
		std::cout << *stu_b.name << ", " << stu_b.age << "\n";

		*stu_b.name = "raptor";

		std::cout << *stu_a.name << ", " << stu_a.age << "\n";
		std::cout << *stu_b.name << ", " << stu_b.age << "\n";

	}

	return 0;

}


