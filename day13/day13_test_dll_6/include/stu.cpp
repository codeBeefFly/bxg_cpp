#include "stu.h"
#include <iostream>

using namespace std;

stu::stu(){
    cout <<"无参构造" <<endl;
}

stu::stu(string name):name(name){
    cout <<"有参构造" <<endl;
}

void stu::run(){
    cout << name << " 在公园里跑步!" << endl;
}

stu::~stu(){
    cout <<"析构" <<endl;
}

