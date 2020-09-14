/*
* function
*  1. 接收类当中的静态成员函数
*      function<返回值 <函数本来的参数类型>> = 类名::函数名
*      f(参数);
*
*  2. 接收类当中的普通成员函数
*      a. 有两个要注意的地方，接收的函数的时候，需要使用  &类名:: 函数名来指定函数的位置
*
*      b. 函数的参数第一个，一定是类的类型。
*
*      function<返回值 <对象的类型 , 函数本来的参数类型>> f = &类名::函数名
*      f(对象 ， 参数);
*
*
*/

#include <iostream>
#include <functional>

using namespace std;


class stu {

public:
    static void read() {
        cout << "学生在看书" << endl;
    }

    void eat(string name) {
        cout << "学生在吃 " << name << endl;
    }

    void play(string where, string sport) {
        cout << "学生在" << where << " ：" << sport << endl;
    }

};



int main() {

    // 调用静态成员函数
    function<void()> f_static = stu::read;
    f_static();

    // 调用普通成员函数
    stu s_eat;
    function<void(stu, string)> f_eat = &stu::eat;
    f_eat(s_eat, "jacob");


    stu s_play;
    function<void(stu&, string, string)> f_play = &stu::play;
    f_play(s_play, "here", "baseball");

}


/*

output

学生在看书
学生在吃 jacob
学生在here ：baseball


*/