#include <iostream>
#include <string>
#include "teacher.h"
#include "stu.h"
#include <vector>

using namespace std;

//重载teacher的输入运算符
void operator >>(istream &in , teacher *t){
    //teacher里面有三份小数据。所以不能直接写成 in >> t;
    in >> t->name >> t->age >> t->subject;
}

void initTeacher(vector<teacher *> &teacher_vector){
    for (int i = 0; i < 3; ++i) {
        /*string name;
        cin >>name;

        int age ;
        cin >> age ;

        string subject ;
        cin >> subject;

        //要长记性啦！！！！
        teacher *t  = new teacher(name , age , subject);*/

        teacher *t = new teacher();
        cout <<"请输入第 "<< i+1 <<" 个教师的姓名、年龄、学科" <<endl;
        cin >> t;

        //如果一个容器里面存指针，那么要非常小心，容器存指针，大多数情况下都是在别的地方用的
        teacher_vector.push_back(t);
    }
    cout <<"初始化教师的函数走完了，教师的容器大小是几个：" << teacher_vector.size() <<endl;
}

//学生相关

void operator >>(istream& in , stu &s){
    in >> s.name >> s.no ;
}

void initStu(vector<stu > &stu_vector ,  vector<teacher *> &teacher_vector) {
    for(int i = 0 ; i < 3 ; i++){
        stu s;
         //赋值 =  取值
           // 这个额容器里面有东西吗？
           //取出来是不是越界了？
           //左右两边是不是没对等上？
           //因为这两个容器里面都没有值。！！！！所以看不了
           cout <<"教师的大小：" <<teacher_vector.size() <<endl;
           cout <<"aaaa" <<endl;
           s.t =  teacher_vector[i];

        cout <<"请输入第 "<< i+1 <<" 个学生的姓名、学号" <<endl;
        cin >> s;

        stu_vector.push_back(s);
    }
}

//更新是修改的操作。
void updateStu( vector<stu > &stu_vector){
    for(stu &s: stu_vector){
        if(s.no == "10088"){
            //找到教师
            teacher *t = s.t;
            t->subject  = "高等数学";

            //跳出循环。 因为有可能这个容器有10个学生，结果我们遍历了第一次就找到这个学生了，后面的9次遍历不需要做了。
            break;
        }
    }
}

void printStu(vector<stu > &stu_vector, void(*op)(vector<stu > stu_vector)){
    op(stu_vector);
}


int main() {

    //教师容器
    vector<teacher *> teacher_vector;

    //学生容器
    vector<stu > stu_vector;

    //1. 初始化教师
    cout <<"***** 初始化教师信息****" <<endl;
    initTeacher(teacher_vector);
    cout <<"在main函数走完initTeacher之后，又打印一会：" << teacher_vector.size() <<endl;

    //2 初始化学生。
    cout <<"***** 初始化学生信息****" <<endl;
    initStu(stu_vector , teacher_vector);

    //3. 更新学生
    cout <<"***** 更新学生信息****" <<endl;
    updateStu(stu_vector);

    //4. 打印学生
   /* void(*op)(vector<stu > stu_vector)  = [](vector<stu > stu_vector){
        for(stu s: stu_vector){
            cout << s.name << "\t" << s.no <<endl;
            //接收一下一对一的教师指针
            teacher *t = s.t;
            cout << t->name << "\t" << t->age << "\t" << t->subject <<endl;
        }
    };
    printStu(stu_vector , op);*/

   cout <<"***** 打印学生信息****" <<endl;
    printStu(stu_vector , [](vector<stu > stu_vector){
        for(stu s: stu_vector){
            cout << s.name << "\t" << s.no <<endl;
            //接收一下一对一的教师指针
            teacher *t = s.t;
            cout << t->name << "\t" << t->age << "\t" << t->subject <<endl;
        }
    });

    return 0;
}



/*

***** 初始化教师信息****
teacher无参构造
请输入第 1 个教师的姓名、年龄、学科
a 1 aaa
teacher无参构造
请输入第 2 个教师的姓名、年龄、学科
b 2 bbb
teacher无参构造
请输入第 3 个教师的姓名、年龄、学科
c 3 ccc
初始化教师的函数走完了，教师的容器大小是几个：3
在main函数走完initTeacher之后，又打印一会：3
***** 初始化学生信息****
stu无参构造
教师的大小：3
aaaa
请输入第 1 个学生的姓名、学号
aa 10086
stu析构
stu无参构造
教师的大小：3
aaaa
请输入第 2 个学生的姓名、学号
bb 10087
stu析构
stu析构
stu无参构造
教师的大小：3
aaaa
请输入第 3 个学生的姓名、学号
cc 10088
stu析构
stu析构
stu析构
***** 更新学生信息****
***** 打印学生信息****
aa      10086
a       1       aaa
stu析构
bb      10087
b       2       bbb
stu析构
cc      10088
c       3       高等数学
stu析构
stu析构
stu析构
stu析构
stu析构
stu析构
stu析构

*/