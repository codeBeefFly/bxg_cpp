
#include <iostream>
#include <string>
#include <map>

using namespace std;
/*
 * �������� - map
 *
 */

int main() {

    // pair<string , int> p1("����",100) ;

    //������һ��map
    map<string, int> m;

    //�涫��
    pair<string, int > p("����", 100);        // ����һ����ֵ

    m.insert(p);


    m.insert({ "����",95 });

    //ȡֵ ��������key���ڣ��ͷ��أ����û�о�ֱ�ӱ���
    int result = m.at("����");
    cout << "result = " << result << endl;



    return 0;
}

/*

output

result = 100
 
*/
