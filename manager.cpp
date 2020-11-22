#include<iostream>
using namespace std;
#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	//初始化管理员的信息
	this->m_Name = name;
	this->m_Pwd = pwd;

	//初始化容器获取到所有文件中老师和学生的信息
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量" << vCom.size();
}
void Manager::operMenu()
{
	cout << "欢迎管理员"<<this->m_Name <<"登录"<< endl;
	cout << "\t\t --------------------------\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          1.添加账号       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          2.查看账号       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          3.查看机房       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          4.清空预约       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          0.注销登录       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t --------------------------\n";

	cout << "请输入您的选择：  ";

}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1 添加学生" << endl;
	cout << "2 添加老师" << endl;
	string fileName;
	string tip;
	string errorTip;

	ofstream ofs; //文件操作的对象
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//添加学生
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
		errorTip = "学号重复，请重新输入";

	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复,请重新输入";
	}
	ofs.open(fileName, ios:: out | ios::app);

	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)   //这里主要就是针对id进行去重操作，
	{
		cin >> id;
		bool ret=checkRepeat(id, select);
		if (ret) //有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	

	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	
	system("pause");
	system("cls");
	ofs.close();

	//调用初始化容器的接口可以防止bug出现，这个bug就是我们在添加的时候可以重复添加新的
	this->initVector();
}


void Manager::initVector()
{
	//确保容器是空的
	vStu.clear();
	vTea.clear();
	//读取信息 学生老师

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为; " << vStu.size() << endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);
	
	Teacher t;
	while (ifs >> t.id && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为; " << vTea.size() << endl;
	ifs.close();
}


bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}

	}
	return false;

}
void printStudent(Student& s)
{
	cout << "学号： " << s.m_Id << "姓名： " << s.m_Name << "密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "职工号： " << s.id << "姓名： " << s.m_Name << "密码：" << s.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "请选择查看的内容： " << endl;
	cout << "1 查看所有的学生" << endl;
	cout << "2 查看所有的老师" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

	}
	else 
	{
		//查看老师
		cout << "所有老师信息如下" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);

	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_ComId << "机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}


void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);  //这个就是一个清空文件的方法，
	ofs.close();

	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}