#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;
#include<string>
#include<vector>
#include"computerRoom.h"
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"
class Student :public Identity //继承基类
{
public:

	//默认构造
	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu();

	//申请预约
	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	void updateOrder();
	int m_Id;

	vector<ComputerRoom>vCom;



	

};
