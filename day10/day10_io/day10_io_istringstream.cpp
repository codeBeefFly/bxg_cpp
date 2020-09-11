#include <iostream>
#include <sstream>

using namespace std;

/*
 *  字符串的输入流
 *
 */
int main() {

    string data = "我是中国人  我深爱着我的祖国 我住在深圳";

    //字符串流管理着上面的字符串
    istringstream  iss(data);

    string content;
    cin >> std::noskipws;   // 为什么没有作用？ 按照空格切割
    while (iss >> content) {
        cout << "content = " << content << endl;
    }


    return 0;
}

/*

output:

content =我是中国人
content =我深爱着我的祖国
content =我住在深圳

*/
