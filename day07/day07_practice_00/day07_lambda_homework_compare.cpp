/*

 * lambda���ʽ ��ʹ�ó���
 * ����Ҫ�Ƚ�����ѧ���Ĵ�С�����԰������ֶ�������Ƚϡ�Ҳ���԰�������Ƚϡ�Ҳ���԰�����߱Ƚϡ�
 * ����һ��ȫ�ֺ���compare , ������������������һ�Ͳ����� ΪҪ�Ƚϵ�ѧ������
 * ������Ϊ�Ƚ��߼��ĺ��� ����ָ�루��Ӧ��ʹ��lambda���ʽ��д������lambda���ʽ�ķ���ֵ������˭��˭С����


 ֻ�Ƚ�����

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


// �������д��
int compare_student_01(Student stu_a, Student stu_b);

// ����ָ��д��������ָ���� lambda ����
int compare_student_02(Student stu_a, Student stu_b, bool (*compare)(std::string stu_name_a, std::string stu_name_b));

// ����ָ��д����������ĺ���������д��������ֵ����� bool ��ô��Ҫ���� true��false
int compare_student_03(Student stu_a, Student stu_b, bool (*compare)(std::string stu_name_a, std::string stu_name_b));




int main() {

	std::cout << "..in day07_lambda_homework_compare...\n";

	Student stu_a("jacob_lee", 10);
	Student stu_b("raptor", 20);

	// ���ó���д��
	int normal_result = compare_student_01(stu_a, stu_b);
	std::cout << "..normal_result = " << normal_result << "\n";
	std::cout << "..normal_result std::boolalpha = " << std::boolalpha << normal_result << "\n";

	// lambda ����ָ��д��
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


	// lambda ����ָ��д�����������д��������д��
	// step1: ���� lambda ��������һ�� bool ���͵ĺ���ָ��
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

	// step2: ���ô�����ָ��ĺ��������ݺ���ָ���ʱ����Ҫ���������ָ�봫�ݲ���
	//compare_student_03(Student stu_a, Student stu_b, compare(stu_a.name, stu_b.name));	// ��ô������д�أ����������е��ú�����ֻ�ø����������ʵ�ξ����ˣ������͸���
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


// �����ȽϺ���������ָ�뺯�����������string���ͳ�Ա���������������ָ��
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