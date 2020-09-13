#pragma once
//
// Created by xiaomi on 2020/3/18.
//

#include <memory>
#include <string>
#include "human.h"
//#include "stu.h"   //最简单的写法就是所有的导入，都放到下面的宏里面去，就不会产生重复嵌套的问题

//这种接法也是一种曲线救国的解法，欺骗一下编译器，现在有一个类，名字叫做stu
//但是这个类里面都有哪些成员，现在不知道。以后如果真的去使用到了stu里面的成员
//光靠这个类的前置声明是不够的。未来使用的时候，有可能需要再导入一次stu.h 头文件。
class stu;

//这里只是头文件 里面并不会使用到stu的任何成员。

//#ifndef DAY10_TEACHER_H
//#define DAY10_TEACHER_H


using namespace std;

class teacher : public human{

public:
    string subject;
    weak_ptr<stu> wp_stu ;

    teacher();
    teacher(string name , string subject);
    ~teacher();

    void work() override ;
    void setStu(shared_ptr<stu> sp1);

};

//#endif //DAY10_TEACHER_H
