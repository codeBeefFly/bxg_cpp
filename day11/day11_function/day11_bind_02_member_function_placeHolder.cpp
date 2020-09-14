/*

�������Ϊ�Ѻ��� ��������ʵ���Լ����ú����Ķ������󶨵�һ��
Ȼ����һ�����������������������Ҳ������Щ������õ����塣


����

����һ�� Student �࣬�� eat ���� ���� food where

ʹ�� �������� ���� bind �����������ʹ�� �޲� function<> ��� eat ����

ʹ��ռλ�� placeholders ��ȱʡ����������䣬���ڵ���ʱ����


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
		// ʹ�� ��������
		std::function<void(Student, std::string, std::string)> f_eat_2 = &Student::eat;			// ���в�

		Student stu_jacob;
		f_eat_2(stu_jacob, "canteen", "breakfast");
		printStu_arg_2(f_eat_2, stu_jacob, "canteen", "breakfast");
	}

	{
		// ʹ�ð�
		Student stu_raptor;
		auto p_eat_2 = std::bind(&Student::eat, stu_raptor, "home", "banana");
		p_eat_2();
		printStu_arg_0(p_eat_2);
	}

	{
		Student stu_king;
		//std::function<void(Student, std::string, std::string)> f_eat_2 = std::bind(&Student::eat, stu_king, "home", "banana");
		std::function<void()> f_eat_2 = std::bind(&Student::eat, stu_king, "home", "banana");	// bind �Ѿ��Ѷ���+����+��������ˣ����Ժ�������Ϊ�޲�
		f_eat_2();
		printStu_arg_0(f_eat_2);
	}


	//{
	//	// ��֤ place holder
	//	Student stu_haha;
	//	//std::function<void(Student, std::string, std::string)> f_eat_2 = std::bind(&Student::eat, stu_king, "home", "banana");
	//	std::function<void(std::string)> f_eat_2 = std::bind(&Student::eat, stu_haha, "home", std::placeholders::_1);	// bind �Ѿ��Ѷ���+����+��������ˣ����Ժ�������Ϊ�޲�
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
// *      2. �󶨳�Ա����
// */
//
//class stu {
//
//public:
//    void eat(string where, string food) {
//        cout << "ѧ����" << where << " �� " << food << endl;
//    }
//};
//
//void printStu(function <void(stu, string)> f, stu s) {
//
//    f(s, "������");
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
//    //ռλ�������߱������������﷨��û����ģ�ֻ��û��ʵ�ʵĲ���ֵ��
//    //��ͷ���õ�ʱ�򣬱���Ҫ���ݲ�������
//    //����û�и���δ֪�Ĳ�����ȷ���� ��1��ʼ��
//    auto f = bind(&stu::eat, s2, "����", placeholders::_1);
//    f("������");
//
//    printStu(bind(&stu::eat, s2, "ʳ��", placeholders::_1));
//    return 0;
//}
//
