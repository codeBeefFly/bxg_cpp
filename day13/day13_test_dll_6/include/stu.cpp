#include "stu.h"
#include <iostream>

using namespace std;

stu::stu(){
    cout <<"�޲ι���" <<endl;
}

stu::stu(string name):name(name){
    cout <<"�вι���" <<endl;
}

void stu::run(){
    cout << name << " �ڹ�԰���ܲ�!" << endl;
}

stu::~stu(){
    cout <<"����" <<endl;
}

