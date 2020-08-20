/*

ǳ���������еĳ�Ա��ָ�����ͣ��ı�����һ�����ָ���Ա

*/


#include<iostream>


class Student_Shallow {

public:
	std::string name;
	int age;

	Student_Shallow() {
		std::cout << "..Student_Shallow�޲ι��캯��...\n";
	}

	Student_Shallow(std::string name_val, int age_val) {
		std::cout << "..Student_Shallow�����ι��캯��...\n";
		name = name_val;
		age = age_val;
	}

	// ǳ�����������Ա��ָ�룬ʹ��ǳ�����ᵼ�¸ı�һ�����Ͷ����Ա����һ�����Ͷ����ԱҲ�ı�
	Student_Shallow(const Student_Shallow& stu) {
		std::cout << "..Student_Shallow�������캯��...\n";
		name = stu.name;
		age = stu.age;
	}

	~Student_Shallow() {
		std::cout << "..Student_Shallow��������...\n";
	}
};


class Student_Deep {
public:

	//std::string* name = nullptr;
	std::string* name = new std::string;
	int age;

	Student_Deep() {
		std::cout << "..Student_Deep�޲ι��캯��...\n";
	}

	Student_Deep(std::string name_val, int age_val) {	// �������Ĳ�����һ��string��
		std::cout << "..Student_Deep�����ι��캯��...\n";
		*name = name_val;
		age = age_val;
	}

	// ǳ�����������Ա��ָ�룬ʹ��ǳ�����ᵼ�¸ı�һ�����Ͷ����Ա����һ�����Ͷ����ԱҲ�ı�
	Student_Deep(const Student_Deep& stu) {
		std::cout << "..Student_Deep�������캯��...\n";
		//*name = stu.name;
		name = stu.name;	// Ϊʲô���䣿 stu.name �ǵ�ַ��*stu.name ��ֵ������ name(��ַ) = stu.name(��ַ)
		age = stu.age;
	}

	~Student_Deep() {
		std::cout << "..Student_Deep��������...\n";
	}


};



int main() {

	std::cout << "..in special_function_06...\n";

	{	// ǳ����

		Student_Shallow stu_a("jacob", 18);

		Student_Shallow stu_b = stu_a;

	}

	{	// ���

		Student_Deep stu_a("jacob", 18);

		Student_Deep stu_b = stu_a;

		std::cout << *stu_a.name << ", " << stu_a.age << "\n";		// ��Ϊ��ַһ������Ը�һ�����ظ���һ��
		std::cout << *stu_b.name << ", " << stu_b.age << "\n";

		*stu_b.name = "raptor";

		std::cout << *stu_a.name << ", " << stu_a.age << "\n";
		std::cout << *stu_b.name << ", " << stu_b.age << "\n";


	}


	return 0;

}


