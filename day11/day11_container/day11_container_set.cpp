#include <iostream>
#include <string>
#include <set>

using namespace std;
/*
 * 关联容器 - set
 *      set 看起来像是一个麻袋，可以往里面装东西，这些东西
 *      不会有专门的标签  、 下标来对应那他们， 所以要想找单独的一个数据
 *      或者去修改单独的指定数据是没有。
 *
 *      set的主要作用是用来存储不重复的数据。 数据的唯一
 */

int main() {

    //1. 创建对象 , 并且初始化数据。
    set<int> s({ 3,4,5 });

    //2. 添加内容
    s.insert(6);
    s.insert(6);  //重复的数据放不进去。

    //3.清除
    s.erase(5);

    //4. 长度  、 检索里面是否有这份数据 ，
    cout << "总长度：" << s.size() << endl;
    cout << "有没有8：" << s.count(8) << endl;


    for (int val : s) {
        cout << "val = " << val << endl;
    }




    return 0;
}

/*

output

总长度：3
有没有8：0
val = 3
val = 4
val = 6


*/
