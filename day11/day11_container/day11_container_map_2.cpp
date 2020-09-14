#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
 * �������� - map
 *
 */

int main() {

    //1. ��ֵ
    map<string, int > m;

    /* pair <string , int > p ("����",198);
     m.insert(p);*/

    m.insert({ "zs" , 88 });
    m.insert({ "lisi" , 68 });
    m.insert({ "wangwu" , 78 });

    pair <string, int > p("����", 198);
    m.insert(p);

    //2. ȡֵ
    cout << m.at("zs") << endl;

    //ֻ�д��������key��ȥȡֵ������У�count�����᷵�������ڵĸ����� 1
    if (m.count("zs2") > 0) {
        cout << m.count("zs2") << endl;
    }

    //3.�����ӵ�key�Ѿ����ڣ���ô���޷���ӽ�ȥ�ġ����Ȳ���䡣
    m.insert({ "zs",66 });
    cout << "zs�ķ�����" << m.at("zs") << endl;

    //4. ����
    cout << "���ȣ�" << m.size() << endl;
    cout << "��󳤶ȣ�" << m.max_size() << endl;

    //5. �޸�����
    m.at("zs") = 70;
    cout << "zs�ķ�����" << m.at("zs") << endl;

    cout << " **************** ����****************" << endl;
    //6. ����  ÿһ��ȡ��������һ����ֵ��  ����һ�� pair���͡�
    for (pair<string, int> p : m) { //c++11��ʱ����ֵģ����ڷ�Χ��forѭ��
        cout << p.first << " : " << p.second << endl;
    }

    //����ǰ����ʹ�û��ڷ�Χ��forѭ��
    for (auto i = m.begin(); i != m.end(); i++) {
        pair<string, int > p = *i;
    }

    // i�ķ�ʽ�ò���ֵ��  ���� i �ķ�ʽ���Ǳ������±ꡣ
    /*for (int i = 0; i < m.size(); ++i) {

    }*/


    return 0;
}


/*

output:

88
zs�ķ�����88
���ȣ�4
��󳤶ȣ�230584300921369395
zs�ķ�����70
 **************** ����****************
lisi : 68
wangwu : 78
zs : 70
���� : 198


*/