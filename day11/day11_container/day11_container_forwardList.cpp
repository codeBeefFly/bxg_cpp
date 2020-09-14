/*

需求：

练习 forward_list 单向列表


forward_list 单向链表、只支持单向顺序访问，插入和删除快，查询和更新慢

*/


#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

using namespace std;


/*
 * forward_list
 *
 *      //特点一： 查询和修改比较慢 没有下标
 *      //特点二 ：插入和删除比较快
 *
 */

 //typedef :已经知道的名称到简单的名称。
 //typedef typename vector::iterator iterator;
int main() {


    vector<int>::iterator vi;

    forward_list<int> flist{ 3,4,5 };

    //追加元素
    flist.push_front(6);

    //特点一： 查询和修改比较慢 没有下标，使用迭代器 .begin() end() 查找
    //flist.assign(0 , 88);
    for (auto i = flist.begin(); i != flist.end(); i++) {
        if (*i == 4) {
            *i = 44;
        }
    }

    for (auto i = flist.begin(); i != flist.end(); i++) {
        cout << " i = " << *i << endl;
    }


    //特点二 ：插入和删除比较快

    flist.remove(44);


    for (auto i = flist.begin(); i != flist.end(); i++) {
        cout << " i = " << *i << endl;
    }



    return 0;
}


/*

output

 i = 6
 i = 3
 i = 44
 i = 5
 i = 6
 i = 3
 i = 5

*/
