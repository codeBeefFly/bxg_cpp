/*

需求：


一对一跟踪辅导，每个学生有一个与之对接的老师。

1. 教师类

   2. 一个 teacher 类，成员：姓名，年龄，教授学科。
   2. 分离式写法，提供有参构造函数构建 teacher 类。
   3. 重写输入运算符，全局，获取老师的信息。

2. 学生类

   1. 一个 student 类，成员：姓名，学号，对接的 teacher 指针类型。

   2. 分离式写法，提供有参构造函数构建 student 类。

   3. 重写输入运算符，全局，获取学生信息。

      ```cpp
      class stu{
        string name;
        string no;
        teacher* t = nullptr;

        // 有参构造
        stu(){}
        ~stu(){
            //析构，要放指针 delete
        }

      ```


3. 在 main 函数中定义两个局部容器， 保存 teacher 和 student 信息

   ```cpp
   vector<teacher*> teacher_vector;
   vector<student*> student_vector;
   ```

4. 定义一个全局函数 initTeacher，从键盘获取 teacher 信息

5. 定义一个全局函数 initStu

   1. 从键盘获取学生信息
   2. 一对一的教师应该从 teacher_vector 中根据下标获取
   3. 在函数中完成学生的构建工作，并且要存储到 stu_vector 容器中

6. 定义全局函数 updateStu，把学号为 10088 的同学一对一教师，授课科目改为 “高等数学”

7. 定义全局函数 printStu，打印学生信息，包括一对一教师信息

   1. 该函数接收两个参数，参数一：学生容器，参数二：打印的具体函数（函数指针）

   2. 重载输出运算符，使得打印变得更加简单

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
void printStu(std::vector<Student*>& stu_vector, void (*print)(std::vector<Student*>& stu_vector));    //使用匿名函数


std::ostream& operator<<(std::ostream& out, Teacher* teacher);  // why *? boz vector<Teacher*> 类型对应
std::istream& operator>>(std::istream& in, Teacher* teacher);

//std::ostream& operator<<(std::ostream& out, Student* student);
std::ostream& operator<<(std::ostream& out, Student& student);
std::istream& operator>>(std::istream& in, Student* student);

int main() {

    std::cout << "..in main_student_teacher...\n";

    std::vector<Student*> stu_vector;
    std::vector<Teacher*> tec_vector;


    // 初始化教师
    initTeacher(tec_vector);


    // 初始化学生
    initStu(stu_vector, tec_vector);

    // 打印学生
    printStu(
        stu_vector,
        [](std::vector<Student*>& stu_vector) {

            //for (Student* stu : stu_vector) {
            //    std::cout << "..学生姓名::\t" << stu->name
            //        << ",\n..id::\t" << stu->id
            //        << ",\n..老师::\t" << stu->teacher;
            //}

            for (Student* stu : stu_vector) {
                std::cout << *stu << "\n";
            }
        }
    );


    // 更新学生
    std::string id = "10088";
    std::string new_subject = "高等数学";
    updateStu(stu_vector, id, new_subject);


    // 打印学生
    printStu(
        stu_vector,
        [](std::vector<Student*>& stu_vector) {

            //for (Student* stu : stu_vector) {
            //    std::cout << "..学生姓名::\t" << stu->name
            //        << ",\n..id::\t" << stu->id
            //        << ",\n..老师::\t" << stu->teacher;
            //}

            for (Student* stu : stu_vector) {
                std::cout << *stu << "\n";
            }
        }
    );


    // 释放空间
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
    
    out << "..教师姓名::\t" << teacher->name
        << ".., 教师年龄::\t" << teacher->age
        << ".., 教师课程::\t" << teacher->subject;

    return out;

}


std::istream& operator>>(std::istream& in, Teacher* teacher) {
    
    in >> teacher->name >> teacher->age >> teacher->subject;

    return in;

}


//std::ostream& operator<<(std::ostream& out, Student* student) {
//
//    out << "..学生姓名::\t" << student->name
//        << "..学生id::\t" << student->id
//        << "..学生课程::\t" << student->teacher->subject;
//
//    return out;
//
//}


std::ostream& operator<<(std::ostream& out, Student& student) {

    //out << "..学生姓名::\t" << student->name
    //    << "..学生id::\t" << student->id
    //    << "..学生课程::\t" << student->teacher->subject;

    out << "..学生姓名::\t" << student.name
        << "\t..学生id::\t" << student.id
        << "\t..学生课程::\t" << student.teacher->subject;

    return out;

}


std::istream& operator>>(std::istream& in, Student* student) {

    in >> student->name >> student->id;

    return in;

}



void initTeacher(std::vector<Teacher*>& tec_vector) {

    
    for (int i = 0; i < 3; i++) {
        // 给对象开辟空间，在堆中
        Teacher* teacher = new Teacher();
        
        std::cout << "..输入教师的 姓名，年龄，课程::\t";
        //std::cin >> teacher->name >> teacher->age >> teacher->subject;
        std::cin >> teacher;
        
        tec_vector.push_back(teacher);
    }

}


void initStu(std::vector<Student*>& stu_vector, std::vector<Teacher*>& tec_vector) {


    for (int i = 0; i < 3; i++) {
        // 给对象开辟空间，在堆中
        Student* student = new Student();

        std::cout << "..输入学生的姓名，id::\t";
        std::cin >> student;
        
        // 绑定学生老师
        //stu_vector[i]->teacher = tec_vector[i];
        //student->teacher = tec_vector[i];   // 这样写 学生类中的老师指针指向老师类指针，在delete时就不用delete 老师指针对象

        student->teacher = new Teacher(*tec_vector[i]); // tec_vector[i] = teacher，是地址，*techer 是地址中的值，就是 类对象
        /*
        
        // 这样写的结果
        ..log::Teacher 的析构函数...
        ..log::Teacher 的析构函数...
        ..log::Teacher 的析构函数...
        ..log::Student 析构函数...
        ..log::Teacher 的析构函数...
        ..log::Student 析构函数...
        ..log::Teacher 的析构函数...
        ..log::Student 析构函数...
        ..log::Teacher 的析构函数...
                
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
            std::cout << "..id 不符合...\n";
        }
    }

}



void printStu(std::vector<Student*>& stu_vector, void (*print)(std::vector<Student*>& stu_vector)) {   //使用匿名函数

    print(stu_vector);

}


/*

output


..in main_student_teacher...
..输入教师的 姓名，年龄，课程:: a 1 aa
..输入教师的 姓名，年龄，课程:: b 2 bb
..输入教师的 姓名，年龄，课程:: c 3 cc
..输入学生的姓名，id::  sa 10086
..输入学生的姓名，id::  sb 10087
..输入学生的姓名，id::  sc 10088
..学生姓名::    sa      ..学生id::      10086   ..学生课程::    aa
..学生姓名::    sb      ..学生id::      10087   ..学生课程::    bb
..学生姓名::    sc      ..学生id::      10088   ..学生课程::    cc
..id 不符合...
..id 不符合...
..学生姓名::    sa      ..学生id::      10086   ..学生课程::    aa
..学生姓名::    sb      ..学生id::      10087   ..学生课程::    bb
..学生姓名::    sc      ..学生id::      10088   ..学生课程::    高等数学
..log::Student 析构函数...
..log::Teacher 的析构函数...
..log::Student 析构函数...
..log::Teacher 的析构函数...
..log::Student 析构函数...
..log::Teacher 的析构函数...

*/