#pragma once
#include<iostream>
#include"Identity.h"
#include<string>
#include"orderFile.h"
#include"globalFile.h"
#include<vector>
using namespace std;

class Teacher :public Identity
{
public:
	Teacher();

	Teacher(int empId, string name, string pwd);

	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	void validOrder();

	int id;


};