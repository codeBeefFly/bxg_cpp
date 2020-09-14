#include <iostream>
/*

A() {
  // output P
}

B(fn) {
  fn();  // B knows only fn, not A
         // B treats fn as a variable
}

B(A);  // B called at T
       // B calling fn() (i.e. calling A())



函数 A 作为参数 fn 传入 函数 B
B 不知道 A 的存在，只知道 fn
B 将 fn 当作一个传入函数的局部变量处理
函数 B 通过 fn() 的语法，调用 函数 A
B 在 调用时刻 T，调用 fn
B 调用 fn 可能是是为了得到结果 P


*/



#include <vector>
#include <algorithm>

using  namespace std;

//回调函数，由sort内部调用，并且要求返回结果。
bool mysort(const string & a, const string & b) {
    return a.size() < b.size();
}


int main() {

    vector<string> vv{ "ab","bc","aa","abc","ac" };

    //默认使用字母表顺序排序 按照我们规定的排序算法排序
    sort(vv.begin(), vv.end(), mysort);

    //如果字数一样，长度一样，那么再按字母表顺序排序，可以使用stable_sort
    stable_sort(vv.begin(), vv.end(), mysort);


    for (string ss : vv) {
        cout << "===>" << ss << endl;
    }
    return 0;
}



/*

output


===>ab
===>bc
===>aa
===>ac
===>abc

*/