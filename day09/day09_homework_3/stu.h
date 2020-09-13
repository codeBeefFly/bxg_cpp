#pragma once
//
// Created by xiaomi on 2020/3/18.
//

#include <memory>
#include "human.h"
#include "teacher.h"

//#ifndef DAY10_STU_H
//#define DAY10_STU_H

class stu :public human{

public:
    string no;//学号

    Gender gender ;//这里缺性别：

    shared_ptr<teacher> sp_teacher; // 是谁负责我们这个学生

    stu();
    stu(string no , string name);
    ~stu();

    stu(stu & s){
        this->name = s.name;
        this->no = s.no;
    }
    void work() override ;
    void setTeacher(shared_ptr<teacher> sp1);
};

//#endif //DAY10_STU_H
