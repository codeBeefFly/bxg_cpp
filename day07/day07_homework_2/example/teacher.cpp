//
// Created by xiaomi on 2020/3/15.
//

#include <iostream>
#include "teacher.h"


teacher::teacher(){
    cout <<"teacher�޲ι���" << endl;
}
teacher::teacher(string name , int age , string subject): name{name},age{age},subject{subject}{
    cout <<"teacher�вι���" << endl;
}
teacher::~teacher(){
    cout <<"teacher����" << endl;
}
