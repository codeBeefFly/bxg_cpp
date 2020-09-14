#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
 * 关联容器 - map
 *
 */

int main() {

    //1. 存值
    map<string, int > m;

    /* pair <string , int > p ("张三",198);
     m.insert(p);*/

    m.insert({ "zs" , 88 });
    m.insert({ "lisi" , 68 });
    m.insert({ "wangwu" , 78 });

    pair <string, int > p("张三", 198);
    m.insert(p);

    //2. 取值
    cout << m.at("zs") << endl;

    //只有存在了这个key才去取值，如果有，count函数会返回它存在的个数。 1
    if (m.count("zs2") > 0) {
        cout << m.count("zs2") << endl;
    }

    //3.如果添加的key已经存在，那么是无法添加进去的。长度不会变。
    m.insert({ "zs",66 });
    cout << "zs的分数：" << m.at("zs") << endl;

    //4. 长度
    cout << "长度：" << m.size() << endl;
    cout << "最大长度：" << m.max_size() << endl;

    //5. 修改数据
    m.at("zs") = 70;
    cout << "zs的分数：" << m.at("zs") << endl;

    cout << " **************** 遍历****************" << endl;
    //6. 遍历  每一次取出来都是一个键值对  就是一个 pair类型。
    for (pair<string, int> p : m) { //c++11的时候出现的，基于范围的for循环
        cout << p.first << " : " << p.second << endl;
    }

    //在以前不能使用基于范围的for循环
    for (auto i = m.begin(); i != m.end(); i++) {
        pair<string, int > p = *i;
    }

    // i的方式拿不了值！  能用 i 的方式，是必须有下标。
    /*for (int i = 0; i < m.size(); ++i) {

    }*/


    return 0;
}


/*

output:

88
zs的分数：88
长度：4
最大长度：230584300921369395
zs的分数：70
 **************** 遍历****************
lisi : 68
wangwu : 78
zs : 70
张三 : 198


*/