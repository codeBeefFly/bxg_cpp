/*

需求：

定义可变参数模板

函数模板解决了相同功能、不同数据类型造成多个方法重载的局面，

而当模板的参数类型都是一样的，或者有多个一样的参数类型一样，
那么使用可变参数来改进模板函数，就显得更为美观。


 * 可变参数的函数模板
 *      函数的参数不固定， 
		函数的参数类型也不固定（类型可以不一样。）

*/

#include <iostream>
#include <vector>

using namespace std;

/*
 * 可变参数的函数模板
 *      函数的参数不固定， 函数的参数类型也不固定（类型可以不一样。）
 *
 */

 /*void add(int a , int b){

 }*/

 //参数个数可变， 参数的类型可变。
 //一般多个参数传递进来的时候，几乎不会用 ... 的方式来匹配他们。因为取值比较难。
//template <typename ... T> //这里的 ... 表示的是类型有很多种。不止一种。
//void add(T ... a) { //表示可以穿很多的参数进来。...就是可变参数。 参数的类型不固定。
//
//    //拆包
//
//    int a = sizeof...(a);
//    cout <<"a =" << a << endl;
//}
//
//int main() {
//    add(3, 4, "aaa", false);
//
//    //add(3,4,5,6 ,"aa", " cc");
//
//
//    return 0;
//}



template <typename ...Args>
void add(Args...args1) {
    int a = sizeof...(args1);
    cout << "传递进来的参数有：" << a << endl;
}

int main() {
    //Args是： int ,int ,int,string ,string ,string
    // args1 : 2, 3, 4, a, b, c
    add(2, 3, 4, "a", "b", "c");

    return 0;
}




