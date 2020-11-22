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
//����Ա��������
class Manager :public Identity
{
public:
	Manager();

	Manager(string name, string pwd);

	virtual void operMenu();


	//����˺�
	void addPerson();

	//�鿴�˺��õ�
	void showPerson();

	void showComputer();

	//���ԤԼ
	void cleanFile();

	//��ʼ������
	void initVector();

	bool checkRepeat(int id, int type);

	//ѧ������
	vector<Student>vStu;

	vector<Teacher>vTea;

	vector<ComputerRoom>vCom;
};