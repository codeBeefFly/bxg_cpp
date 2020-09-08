#include <iostream>
#include <vector>

using namespace std;

/*
 *  可变参数的函数模板，还是使用initializer_list
 *
 *  不管是可变参数还是可变参数的函数模板，就记这种 initializer_list 即可。
 */

 //AA
int add1(int a) {
    return a;
}

// BB 可以接受可变参数。
int add2(initializer_list<int> list) {
    // 直接打印元素
    for (auto i = list.begin(); i < list.end(); i++) {
        // 析构指针
        std::cout << "..元素 = " << *i << "\t";
    }
    return 0;
}

// CC 模板。
template <typename  T>
T add3(initializer_list<T> list) {
    int total = 0;
    for (auto i = list.begin(); i < list.end(); i++) {
        total += *i;
    }
    return total;
}

int main() {
    cout << add3({ 1,2,3 }) << endl;
    add2({ 4, 5, 6, 7, 8 });

    return 0;
}


/*

output:


6
..元素 = 4      ..元素 = 5      ..元素 = 6      ..元素 = 7      ..元素 = 8

*/
