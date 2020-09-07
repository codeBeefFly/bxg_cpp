#include <iostream>
#include <memory>
using  namespace std;

/*
 * 唯一指针
 *  unique_ptr;
 */
int main() {
    int a = 3;
    int* p = &a;
    int* p2 = new int(3);

    // 创建一个只能指针的对象， 里面指向的数据类型是 int
    //无参构造。  没有管理指针
    unique_ptr<int>  uq;

    //调用它的有参构造  管理了一个指针 p
    //unique_ptr<int> uq2(p);     // 错的 

    //所谓的智能指针，其实就是有一个类，帮助我们来管理指针。
    //关于指针的释放，就由它来完成。 管理堆内存的指针。
    unique_ptr<int> uq3(new int(3));



    return 0;
}
