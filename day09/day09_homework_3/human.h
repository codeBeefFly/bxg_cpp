#pragma once
//
// Created by xiaomi on 2020/3/18.
//
#include <iostream>
#include <string>
using namespace std;

//#ifndef DAY10_HUMAN_H
//#define DAY10_HUMAN_H

//�Ա�
enum  class Gender{MALE , FEMALE};

//������������Զ�����ͨ������ ���ԣ� ���Ը�������á�
class human{
public:
    string name;
    virtual void work() = 0;


    //�����������ܲ��ܶ��幹�캯����
    //�����й��캯���� ���ǻ��ǲ��ܴ�������
    //�������� ---> ���캯��
    //���캯�� ----> һ������������

    // ���캯����������ʼ�����ݵģ����Ը��������ڵ��ó�ʼ��ѽ��
    human() = default;
    explicit human(string name):name(move(name))  {
        cout << "ִ����human���вι���" << endl;
    }
};

//#endif //DAY10_HUMAN_H
