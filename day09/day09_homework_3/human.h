#pragma once
//
// Created by xiaomi on 2020/3/18.
//
#include <iostream>
#include <string>
using namespace std;

//#ifndef DAY10_HUMAN_H
//#define DAY10_HUMAN_H

//性别
enum  class Gender{MALE , FEMALE};

//抽象类里面可以定义普通函数吗？ 可以！ 可以给子类调用。
class human{
public:
    string name;
    virtual void work() = 0;


    //抽象类里面能不能定义构造函数？
    //可以有构造函数。 但是还是不能创建对象。
    //创建对象 ---> 构造函数
    //构造函数 ----> 一定创建对象吗？

    // 构造函数是用来初始化数据的，可以给子类用于调用初始化呀。
    human() = default;
    explicit human(string name):name(move(name))  {
        cout << "执行了human的有参构造" << endl;
    }
};

//#endif //DAY10_HUMAN_H
