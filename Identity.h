#pragma once
#include<iostream>
using namespace std;
#include<string>
//��ݻ���
class Identity
{
public:

	//�����࣬ ���麯��  �����൱�ڰѹ����Ĳ��ַ�װ����һ������ô��麯��
	virtual void operMenu() = 0;  

	string m_Name;
	string m_Pwd;
};
