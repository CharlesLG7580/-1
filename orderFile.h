#pragma once
#include<iostream>
using namespace std;

#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>

class OrderFile
{
public:
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼ԤԼ����
	int m_Size;

	map<int, map<string, string>>m_orderData;
};