/*

需求：

关联容器和顺序容器有很大的不同，
顺序容器的元素在容器中是有顺序的（按照添加先后计算） ， 
而关联容器并不计较顺序的概念，因为他们是按照关键字来访问元素的。
C++中常用的关联容器有两个：`map` 和 `set` , 
map 有点类似 python 里面的`字典`，使用键值对的形式来存储


pair定义在头文件`#include ` 中，一个pair保存两个数据成员，它是类模板，
所以在创建对象的时候，需要添加泛型参数，以用来表示所保存的数据类型。

*/


#include <iostream>
#include <string>
//#include <utility>

using namespace std;
/*
 * 关联容器 - map
 *      存储的是键值对。  key - value
 *      c++ 有一个类用来包装键值对   pair
 */

int main() {

    pair<string, int> p1("张三", 100);
    cout << p1.first << " : " << p1.second << endl;

    pair<string, int> p2("李四", 50);
    cout << p2.first << " : " << p2.second << endl;


    return 0;
}


/*

output


张三 : 100
李四 : 50


*/