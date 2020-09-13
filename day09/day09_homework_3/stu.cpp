//
// Created by xiaomi on 2020/3/18.
//

#include "stu.h"
#include <iostream>
using namespace std;

stu::stu(){
    cout <<"stu无参构造" <<endl;

}



stu::stu(string no , string name):no{no}{
    this-> name = name;
    //this->name = name;
    cout <<"stu有参构造" <<endl;
}

//编译器规定父类的成员，应该在父类的构造函数上初始化。
/*stu::stu(string no , string name):human(name),no{no}{
    //this->name = name;
    cout <<"stu有参构造" <<endl;
}*/
stu::~stu(){
    cout <<"stu析构" <<endl;
}

//这里直接写的是父类的函数。不知道行还是不行！
void stu::work(){
//    张三老师教授的学科是英文，他负责的学生是张三三,
//            张同学的学号是10086 ，他正在学英英语。
    cout << endl;
    cout << " ************************ " <<endl;
    cout << endl;
    cout << "教师的信息：" <<endl;
    cout<< sp_teacher->name << " : "<< sp_teacher->subject << endl;


    cout << "学生的信息：" <<endl;
    cout<< name << " : "<< no << endl;
}
void stu::setTeacher(shared_ptr<teacher> sp1){
    sp_teacher = sp1;
}