//
// Created by xiaomi on 2020/3/18.
//
#include <iostream>
#include "teacher.h"
#include "stu.h"

using namespace std;

teacher::teacher(){
    cout << "teacher无参构造" <<endl;
}
teacher::teacher(string name , string subject):human(name) , subject(subject){
    cout << "teacher有参构造" <<endl;
}
teacher::~teacher(){
    cout << "teacher析构" <<endl;
}

void teacher::work() {
    cout << endl;
    cout << " ************************ " <<endl;
    cout << endl;
    cout << "教师的信息：" <<endl;
    cout<< name << " : "<< subject << endl;


    cout << "学生的信息：" <<endl;

    cout<<wp_stu.lock()->name << " : "<< wp_stu.lock()->no << endl;
}
void teacher::setStu(shared_ptr<stu> sp1){
    cout << "teacher::setStu" <<endl;
    wp_stu = sp1;
}