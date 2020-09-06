//
// Created by xiaomi on 2020/3/15.
//

#include <string>

using namespace std;

#ifndef DAY08_TEACHER_H
#define DAY08_TEACHER_H

class teacher{
public:
    string name;
    int age;
    string subject;

    teacher();
    teacher(string name , int age , string subject);
    ~teacher();
};

#endif //DAY08_TEACHER_H
