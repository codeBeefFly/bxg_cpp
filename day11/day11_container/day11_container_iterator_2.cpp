#include <iostream>
#include <vector>

using namespace std;


/*
 * 迭代器
 *
 *  end();
 */

int main() {

    vector<int> vi{ 10,20,30,40,50 };

    // __gnu_cxx::__normal_iterator<int*, vector<int>> it =  vi.begin();

    //这是一个迭代器，它包装了第一个元素的指针。  如果想研究的话，其实可以打地址。
    auto begin = vi.begin(); //iterator(this->_M_impl._M_start);
    cout << "begin = " << *begin << endl;

    auto end = vi.end(); // iterator(this->_M_impl._M_finish);
    cout << "end = " << *(end - 1) << endl;


    //这里的 <  和 ++ 实际上是调用了iterator类里面的两个函数
    //operator< ()  operator++()
    //不是任何容器里面都重载  < 符号  有可能重载 !=
    for (auto i = vi.begin(); i != vi.end(); i++) {
        cout << " i = " << *i << endl;
        if (*i == 30) {
            //这里要迭代器，不是要指针。
            vi.erase(i);       // 有bug

        }
    }


    return 0;
}


/*

output

begin = 10
end = 50
 i = 10
 i = 20
 i = 30

*/
