/*

需求：

函数模板 + 可变参数

如普通函数一般，函数模板也可以重载，以便灵活应对更多的需求


模板函数的重载

 *      可变参数： 解决参数的多变（可多可少）
 *      函数模板：解决了类型的多变 (类型可以变化，接收很多不一样的类型。)

*/


#include <iostream>
#include <iomanip>

using namespace std;

/*
 *  模板编程
 *      模板函数的重载
 *
 *      函数模板的重载是可以应对不同的参数个数，以及参数的顺序变化的。
 *      但是如果参数的类型都一样，唯独只有参数的个数在变化， 那么可以考虑使用
 *      可变参数来升级函数模板。
 *
 *      可变参数： 解决参数的多变（可多可少）
 *      函数模板：解决了类型的多变 (类型可以变化，接收很多不一样的类型。)
 *
 */
 /*

 int add(int a , int b ){
     return a + b;
 }
 */

template <typename  T>
T add(T a, T b) {
    return a + b;
}

template <typename  T>
T add(T a, T b, T c) {
    return a + b + c;
}

template <typename  T>
T add(T a, T b, T c, T d) {
    return a + b + c;
}



int main() {

    cout << add(3, 4) << endl;
    cout << add(3.5, 4.5) << endl;


    return 0;
}

/*

output


7
8

*/
