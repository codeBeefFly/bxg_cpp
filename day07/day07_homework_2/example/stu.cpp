//
// Created by xiaomi on 2020/3/15.
//

#include <iostream>
#include "stu.h"
stu::stu(){
    cout <<"stu无参构造" <<endl;
}
stu::stu(string name , string no , teacher* t){

    cout <<"stu有参构造" <<endl;
}
stu::~stu(){
    cout <<"stu析构" <<endl;

}
