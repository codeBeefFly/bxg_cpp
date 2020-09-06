//
// Created by xiaomi on 2020/3/15.
//
#include <string>
#include "teacher.h"

using namespace std;

#ifndef DAY08_STU_H
#define DAY08_STU_H

class stu{
public:
    string name;
    string no ;
    teacher *t = nullptr ;

    stu();
    stu(string name , string no , teacher* t);
    ~stu();
};

#endif //DAY08_STU_H
