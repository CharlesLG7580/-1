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
class Student :public Identity //�̳л���
{
public:

	//Ĭ�Ϲ���
	Student();

	Student(int id, string name, string pwd);

	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	void updateOrder();
	int m_Id;

	vector<ComputerRoom>vCom;



	

};
