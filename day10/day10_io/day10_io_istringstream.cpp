#include <iostream>
#include <sstream>

using namespace std;

/*
 *  �ַ�����������
 *
 */
int main() {

    string data = "�����й���  ������ҵ���� ��ס������";

    //�ַ�����������������ַ���
    istringstream  iss(data);

    string content;
    cin >> std::noskipws;   // Ϊʲôû�����ã� ���տո��и�
    while (iss >> content) {
        cout << "content = " << content << endl;
    }


    return 0;
}

/*

output:

content =�����й���
content =������ҵ����
content =��ס������

*/
