/*

### 2. �ۺ�����

1. ����ѧ���� `stu`������
   1. ���ԣ�������ѧ�š�ѧУ������
   2. ����Ϊָ�����ͣ�ѧ��Ϊ��ͨ�ַ�����ѧУΪ��̬��Ա������Ϊ` vector<int>`
2. ѧ����Ӧ�þ��� `stu.h` ��` stu.cpp` �����ļ�
   1. `stu.h`�������������Լ�������������������
   2. `stu.cpp` Ӧ����Ϊ�����������ľ���ʵ��
3. �� main �������棬����ȫ�ֱ��� `vector<student*> stu_vector`
4. ����ȫ�ֺ��� `initStu` ��ʼ��ѧ����Ϣ������¼��3��ѧ����Ϣ
5. ����ȫ�ֺ��� `updateStu` ����ѧ���ɼ������ú���ָ�뷽ʽ����
   1. �����ڲ�Ӧ����ѯ�ʸ��µ������ʲô������Ȼ��ʹ�� `switch` �ж�
   2. �������ݽ�ȥ��Ӧ�ĺ���ָ��
6. ����ȫ�ֺ��� `printStu` ���ڴ�ӡѧ����Ϣ��Ҫ��ѧ������������� `<<`��Ȼ��ʹ�� `cout << s << endl;`��`s` Ϊѧ������ķ�ʽ��ӡ��ѧ����Ϣ���鿴�ʼ�
7. ����ѡ�����ȫ�ֺ��� deleteStu ����ɾ��ѧ�����Ӽ���¼��ѧ��ѧ�ţ�ƥ��֮�󣬴�������ɾ����ѧ����
8. �ͷ�ѧ���������ڴ档



*/

#include <iostream>
#include "Student.h"

void initStu(std::vector<Student*>& student_vector);
//void updateStu(std::vector<Student*>& student_vector, int target_score, void (*fun)(std::vector<Student*>& student_vector, int target_score));
void updateStu(std::vector<Student*>& student_vector);
void printStu_normal(std::vector<Student*> student_vector);
void printStu_overload(std::vector<Student*> student_vector);
void deleteStu(std::vector<Student*>& student_vector);

std::ostream& operator<<(std::ostream& out, Student& stu);

void update_to_target(std::vector<Student*>& student_vector, int target_score);


int main() {

	std::cout << "..in student_marks_operation_overload_correction...\n";

	std::vector<Student*> student_vector;

	// ��ʼ��ѧ��
	initStu(student_vector);

	// ����ѧ���ɼ�
	//int target_score{ 0 };
	//updateStu(student_vector, target_score, update_to_target);
	updateStu(student_vector);

	// ��ӡѧ��
	printStu_normal(student_vector);

	// ɾ��ѧ��
	deleteStu(student_vector);


	return 0;

}


void initStu(std::vector<Student*>& student_vector) {
	std::cout << "\n******************************** ��ʼ��ѧ���� ********************************\n";
	
	std::cout << "..����ѧ������::\t";
	int number{ 0 };
	std::cin >> number;
	if (number == 0) {
		std::cout << "..ѧ������Ϊ 0...\n";
	}
	for (int i = 0; i < number; i++) {
		std::cout << "..�����[" << i + 1 << "]��ѧ��������id::\t";
		std::string tmp_name, tmp_id;
		std::cin >> tmp_name >> tmp_id;

		std::vector<int> score_vector{};
		for (int j = 0; j < 6; j++) {
			std::cout << "..�����[" << j + 1 << "]�ſεĳɼ�::\t";
			int tmp_score{ 0 };
			std::cin >> tmp_score;
			score_vector.push_back(tmp_score);
		}

		Student* stu = new Student(tmp_name, tmp_id, score_vector);
		student_vector.push_back(stu);
		
	}
}


//void updateStu(std::vector<Student*>& student_vector, int target_score, 
//	void (*fun)(std::vector<Student*>& student_vector, int target_score)) {
//	std::cout << "\n******************************** ����ѧ���ɼ� ********************************\n";
//	
//	fun(student_vector, target_score);
//}

void updateStu(std::vector<Student*>& student_vector) {
	std::cout << "\n******************************** ����ѧ���ɼ� ********************************\n";

	std::cout << "..������Ҫ���µ��ĳɼ�::\t";
	int target_score;
	std::cin >> target_score;

	update_to_target(student_vector, target_score);
}


void printStu_normal(std::vector<Student*> student_vector) {
	std::cout << "\n******************************** ��ӡѧ���ɼ� ********************************\n";

	for (Student* stu : student_vector) {
		std::cout << "..ѧ������::\t" << stu->name << ", id::\t" << stu->id << "\n";
		std::cout << "..ѧ������::\t";
		for (int score : stu->score_vector) {
			std::cout << score << "\t";
		}
		std::cout << "\n";
	}
}


void printStu_overload(std::vector<Student*> student_vector) {
	std::cout << "\n*************************** ��ӡѧ���ɼ�(overload) ***************************\n";

	for (Student* stu : student_vector) {
		std::cout << stu;
	}
}


std::ostream& operator<<(std::ostream& out, Student& stu) {
	out << "..ѧ������::\t" << stu.name << ", id::\t" << stu.id << "\n";
	out << "..ѧ������::\t";
	for (int score : stu.score_vector) {
		out << score << "\t";
	}
	out << "\n";

	return out;
}


//void deleteStu(std::vector<Student*>& student_vector) {
//	std::cout << "******************************** ɾ��ָ��ѧ�� ********************************";
//
//	std::cout << "..������Ҫɾ����ѧ��id::\t";
//	std::string target_id;
//	std::cin >> target_id;
//
//	for (Student* stu : student_vector) {
//		if (stu->id == target_id) {
//			std::cout << "..ѧ�� [" << stu->name << "] ɾ��..\n";
//			delete stu;
//		}
//	}


void deleteStu(std::vector<Student*>& student_vector) {
	std::cout << "\n******************************** ɾ��ָ��ѧ�� ********************************\n";
	
	std::cout << "..������Ҫɾ����ѧ��id::\t";
	std::string target_id;
	std::cin >> target_id;

	for (auto ptr = student_vector.begin(); ptr < student_vector.end(); ptr++) {
		if ((*ptr)->id == target_id) {			// ptr �� student*
			delete* ptr;
			//student_vector.erase(*ptr);
		}
	}
}

void update_to_target(std::vector<Student*>& student_vector, int target_score) {
	for (Student* stu : student_vector) {
		for (int& score : stu->score_vector) {
			if (score < 60) {
				score = target_score;
			}
		}
	}
}