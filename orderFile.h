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

	//更新预约记录
	void updateOrder();

	//记录预约条数
	int m_Size;

	map<int, map<string, string>>m_orderData;
};