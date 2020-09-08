/*


需求：

递归拆包

可变参数从设计角度是方便了，但是在获取传递过来的参数却有点棘手，
因为索引下标在展开参数包场景下没有用，
而且可变参数可以看成是一个包裹，里面包装了传递过来的若干个实参。

通常展开参数包的做法是采用递归，不断的调用，每调用一次，减少一个实参，
最终把所有实参都捕获出来。


递归

**递归**在程序语言中简单的理解是：函数自己调用自己。但是递归需要有一个出口（也就是终止递归的条件），
否则有可能陷入无限循环调用那种，进而造成栈溢出异常。

*/



#include <iostream>
#include <vector>

using namespace std;

/*
 *  使用递归拆包可变参数的函数模板
 */


int add() {
    cout << "无参构造" << endl;
    return 0;
}
//可变参数的声明都得放在最后声明，大部分的编程语言都是这样。

//这里采用循环递归的拆包，每一次调用的时候，参数包的第一个数，永远会被number拿走
//所以下一次调用的时候，得到的参数永远会比上一次的参数少一个。

//参数总有被拆完的之后，当我们的参数已经变成没有参数了。那么还能接着调用你这个add函数吗？
//不能了，因为这个函数它一定，至少得有一个参数。   number
//因为number不是可变参数。

template < typename  ... T, typename K >
int add(K number, T ...a) { //a = (1,2);
    cout << "number = " << number << endl;

    //就第一次调用的第一个参数  和 以后的每一次调用的结果返回 累加即可。
    number += add(a...);
    return number;
}

int main() {

    cout << add(1, 2, 3, 4, 5) << endl;

    //add("aa" , "bb" , "cc" ,1,2,3 ,false ,4,5);

//    add(1 , 2 );

    return 0;
}


/*


output

number = 1
number = 2
number = 3
number = 4
number = 5
无参构造
15


*/
