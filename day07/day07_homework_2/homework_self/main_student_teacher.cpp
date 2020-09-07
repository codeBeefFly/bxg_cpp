/*

����


һ��һ���ٸ�����ÿ��ѧ����һ����֮�Խӵ���ʦ��

1. ��ʦ��

   2. һ�� teacher �࣬��Ա�����������䣬����ѧ�ơ�
   2. ����ʽд�����ṩ�вι��캯������ teacher �ࡣ
   3. ��д�����������ȫ�֣���ȡ��ʦ����Ϣ��

2. ѧ����

   1. һ�� student �࣬��Ա��������ѧ�ţ��Խӵ� teacher ָ�����͡�

   2. ����ʽд�����ṩ�вι��캯������ student �ࡣ

   3. ��д�����������ȫ�֣���ȡѧ����Ϣ��

      ```cpp
      class stu{
        string name;
        string no;
        teacher* t = nullptr;

        // �вι���
        stu(){}
        ~stu(){
            //������Ҫ��ָ�� delete
        }

      ```


3. �� main �����ж��������ֲ������� ���� teacher �� student ��Ϣ

   ```cpp
   vector<teacher*> teacher_vector;
   vector<student*> student_vector;
   ```

4. ����һ��ȫ�ֺ��� initTeacher���Ӽ��̻�ȡ teacher ��Ϣ

5. ����һ��ȫ�ֺ��� initStu

   1. �Ӽ��̻�ȡѧ����Ϣ
   2. һ��һ�Ľ�ʦӦ�ô� teacher_vector �и����±��ȡ
   3. �ں��������ѧ���Ĺ�������������Ҫ�洢�� stu_vector ������

6. ����ȫ�ֺ��� updateStu����ѧ��Ϊ 10088 ��ͬѧһ��һ��ʦ���ڿο�Ŀ��Ϊ ���ߵ���ѧ��

7. ����ȫ�ֺ��� printStu����ӡѧ����Ϣ������һ��һ��ʦ��Ϣ

   1. �ú���������������������һ��ѧ������������������ӡ�ľ��庯��������ָ�룩

   2. ��������������ʹ�ô�ӡ��ø��Ӽ�

      ```cpp
      std::cout << s << std::endl;
      ```


*/


#include <vector>
#include "teacher.h"
#include "student.h"



void initTeacher(std::vector<Teacher*>& tec_vector);
void initStu(std::vector<Student*>& stu_vector, std::vector<Teacher*>& tec_vector);
void updateStu(std::vector<Student*>& stu_vector, std::string& id, std::string& new_subject);
void printStu(std::vector<Student*>& stu_vector, void (*print)(std::vector<Student*>& stu_vector));    //ʹ����������


std::ostream& operator<<(std::ostream& out, Teacher* teacher);  // why *? boz vector<Teacher*> ���Ͷ�Ӧ
std::istream& operator>>(std::istream& in, Teacher* teacher);

//std::ostream& operator<<(std::ostream& out, Student* student);
std::ostream& operator<<(std::ostream& out, Student& student);
std::istream& operator>>(std::istream& in, Student* student);

int main() {

    std::cout << "..in main_student_teacher...\n";

    std::vector<Student*> stu_vector;
    std::vector<Teacher*> tec_vector;


    // ��ʼ����ʦ
    initTeacher(tec_vector);


    // ��ʼ��ѧ��
    initStu(stu_vector, tec_vector);

    // ��ӡѧ��
    printStu(
        stu_vector,
        [](std::vector<Student*>& stu_vector) {

            //for (Student* stu : stu_vector) {
            //    std::cout << "..ѧ������::\t" << stu->name
            //        << ",\n..id::\t" << stu->id
            //        << ",\n..��ʦ::\t" << stu->teacher;
            //}

            for (Student* stu : stu_vector) {
                std::cout << *stu << "\n";
            }
        }
    );


    // ����ѧ��
    std::string id = "10088";
    std::string new_subject = "�ߵ���ѧ";
    updateStu(stu_vector, id, new_subject);


    // ��ӡѧ��
    printStu(
        stu_vector,
        [](std::vector<Student*>& stu_vector) {

            //for (Student* stu : stu_vector) {
            //    std::cout << "..ѧ������::\t" << stu->name
            //        << ",\n..id::\t" << stu->id
            //        << ",\n..��ʦ::\t" << stu->teacher;
            //}

            for (Student* stu : stu_vector) {
                std::cout << *stu << "\n";
            }
        }
    );


    // �ͷſռ�
    for (Teacher* teacher : tec_vector) {
        delete teacher;
    }

    for (Student* student : stu_vector) {
        delete student;
    }

    return 0;

}


std::ostream& operator<<(std::ostream& out, Teacher* teacher) {
    
    //teacher = new Teacher;
    
    out << "..��ʦ����::\t" << teacher->name
        << ".., ��ʦ����::\t" << teacher->age
        << ".., ��ʦ�γ�::\t" << teacher->subject;

    return out;

}


std::istream& operator>>(std::istream& in, Teacher* teacher) {
    
    in >> teacher->name >> teacher->age >> teacher->subject;

    return in;

}


//std::ostream& operator<<(std::ostream& out, Student* student) {
//
//    out << "..ѧ������::\t" << student->name
//        << "..ѧ��id::\t" << student->id
//        << "..ѧ���γ�::\t" << student->teacher->subject;
//
//    return out;
//
//}


std::ostream& operator<<(std::ostream& out, Student& student) {

    //out << "..ѧ������::\t" << student->name
    //    << "..ѧ��id::\t" << student->id
    //    << "..ѧ���γ�::\t" << student->teacher->subject;

    out << "..ѧ������::\t" << student.name
        << "\t..ѧ��id::\t" << student.id
        << "\t..ѧ���γ�::\t" << student.teacher->subject;

    return out;

}


std::istream& operator>>(std::istream& in, Student* student) {

    in >> student->name >> student->id;

    return in;

}



void initTeacher(std::vector<Teacher*>& tec_vector) {

    
    for (int i = 0; i < 3; i++) {
        // �����󿪱ٿռ䣬�ڶ���
        Teacher* teacher = new Teacher();
        
        std::cout << "..�����ʦ�� ���������䣬�γ�::\t";
        //std::cin >> teacher->name >> teacher->age >> teacher->subject;
        std::cin >> teacher;
        
        tec_vector.push_back(teacher);
    }

}


void initStu(std::vector<Student*>& stu_vector, std::vector<Teacher*>& tec_vector) {


    for (int i = 0; i < 3; i++) {
        // �����󿪱ٿռ䣬�ڶ���
        Student* student = new Student();

        std::cout << "..����ѧ����������id::\t";
        std::cin >> student;
        
        // ��ѧ����ʦ
        //stu_vector[i]->teacher = tec_vector[i];
        //student->teacher = tec_vector[i];   // ����д ѧ�����е���ʦָ��ָ����ʦ��ָ�룬��deleteʱ�Ͳ���delete ��ʦָ�����

        student->teacher = new Teacher(*tec_vector[i]); // tec_vector[i] = teacher���ǵ�ַ��*techer �ǵ�ַ�е�ֵ������ �����
        /*
        
        // ����д�Ľ��
        ..log::Teacher ����������...
        ..log::Teacher ����������...
        ..log::Teacher ����������...
        ..log::Student ��������...
        ..log::Teacher ����������...
        ..log::Student ��������...
        ..log::Teacher ����������...
        ..log::Student ��������...
        ..log::Teacher ����������...
                
        */



        stu_vector.push_back(student);
    }

}


void updateStu(std::vector<Student*>& stu_vector, std::string& id, std::string& new_subject) {
    
    for (Student* stu : stu_vector) {
        if (stu->id == id) {
            stu->teacher->subject = new_subject;
            break;
        }
        else {
            std::cout << "..id ������...\n";
        }
    }

}



void printStu(std::vector<Student*>& stu_vector, void (*print)(std::vector<Student*>& stu_vector)) {   //ʹ����������

    print(stu_vector);

}


/*

output


..in main_student_teacher...
..�����ʦ�� ���������䣬�γ�:: a 1 aa
..�����ʦ�� ���������䣬�γ�:: b 2 bb
..�����ʦ�� ���������䣬�γ�:: c 3 cc
..����ѧ����������id::  sa 10086
..����ѧ����������id::  sb 10087
..����ѧ����������id::  sc 10088
..ѧ������::    sa      ..ѧ��id::      10086   ..ѧ���γ�::    aa
..ѧ������::    sb      ..ѧ��id::      10087   ..ѧ���γ�::    bb
..ѧ������::    sc      ..ѧ��id::      10088   ..ѧ���γ�::    cc
..id ������...
..id ������...
..ѧ������::    sa      ..ѧ��id::      10086   ..ѧ���γ�::    aa
..ѧ������::    sb      ..ѧ��id::      10087   ..ѧ���γ�::    bb
..ѧ������::    sc      ..ѧ��id::      10088   ..ѧ���γ�::    �ߵ���ѧ
..log::Student ��������...
..log::Teacher ����������...
..log::Student ��������...
..log::Teacher ����������...
..log::Student ��������...
..log::Teacher ����������...

*/