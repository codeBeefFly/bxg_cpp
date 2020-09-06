//
// Created by xiaomi on 2020/3/15.
//

#include <iostream>
#include "teacher.h"


teacher::teacher(){
    cout <<"teacher无参构造" << endl;
}
teacher::teacher(string name , int age , string subject): name{name},age{age},subject{subject}{
    cout <<"teacher有参构造" << endl;
}
teacher::~teacher(){
    cout <<"teacher析构" << endl;
}
