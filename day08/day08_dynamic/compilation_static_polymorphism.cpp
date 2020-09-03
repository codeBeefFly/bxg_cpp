/*

需求：

静态编译

学习模式：拷贝课程代码，调试，运行，总结

*/


#include <iostream>
#include <string>

using namespace std;

/*
 * 多态
 *      静态多态 ，在编译期间就已经明确了要执行什么函数。 函数重载。
 */

int add(int a, int b) {
    return a + b;
}

int add(double a, int b) {
    return a + b;
}

int main() {

    std::cout << "..in compilation_static...\n";

    std::cout << add(3.3, 4) << "\n";
    std::cout << add(3, 4) << "\n";

    return 0;
}
