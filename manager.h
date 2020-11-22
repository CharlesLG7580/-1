#pragma once
#include<iostream>
#include"Identity.h"
using namespace std;
#include<fstream>
#include<string>  //
#include"globalFile.h"
#include<vector>
#include"teacher.h"
#include"student.h"
#include<algorithm>
#include"computerRoom.h"
//管理员的类的设计
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();


	//添加账号
	void addPerson();

	//查看账号用的
	void showPerson();

	void showComputer();

	//清空预约
	void cleanFile();

	//初始化容器
	void initVector();

	bool checkRepeat(int id, int type);

	//学生容器
	vector<Student>vStu;

	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};