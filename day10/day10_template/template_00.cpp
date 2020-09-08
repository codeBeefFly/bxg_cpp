/*

需求：

模板编程

函数模板

函数多态

C++ 多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。

函数重载
在同一个作用域内，可以声明几个功能类似的同名函数，但是这些同名函数的形式参数
（指参数的个数、类型或者顺序）必须不同。您不能仅通过返回类型的不同来重载函数。

区分多态与函数重载

*/


#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  模板编程的意义
 *      观察下面的三个函数，他们的功能都一样，除了函数的参数类型不同而已。
 *      那么是否能只写一个函数，然后可以匹配多种类型呢？
 *
 *      所谓的模板编程就是只要做好了一个模子，然后根据这个模子创建出来不同类型的函数。
 *
 *      def add(a , b):
 *          return a + b ;
 *
 */

int add(int a, int b) {
    return a + b;
}
int add(double a, double b) {
    return a + b;
}
int add(double a, int b) {
    return a + b;
}

int main() {

    add(3, 4);
    add(3.5, 4.5);
    add(3.5, 5);

    return 0;
}
