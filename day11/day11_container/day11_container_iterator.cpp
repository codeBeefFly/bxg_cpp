#include <iostream>
#include <vector>

using namespace std;


/*
 * 迭代器
 */

int main() {


    vector<int> vi{ 10,20,30,40 };

    /* template<typename _Iterator, typename _Container>
     class __normal_iterator*/

     //STL 的源码读一下。  vector

    //__gnu_cxx::__normal_iterator<int*, vector<int>>  it = vi.begin();

    //vector 也是一个类。
    //这个迭代器实际上也是一个类。  当我们往vector里面存元素的时候
    //底层| 内部会用迭代器来对我们的元素进行关联。
    auto  iterator = vi.begin();

    //背后调用的是这个： *_M_current;  _M_current 就是我们的元素对应的指针类型

    //如果vector里面存放的是int类型的数据， 那么_M_current 就是 int*
    // 如果对迭代器使用*符号，背后就是对 _M_current 使用解引用。
    cout << "iterator = " << *iterator << endl;
    //cout << "base() = " << *iterator.base() << endl;    // 没有 base 这个函数 no member base

    cout << *(vi.begin() + 1) << endl;


    return 0;
}

/*

output

iterator = 10
20

*/