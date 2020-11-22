#include<iostream>
using namespace std;
#include<fstream>
#include"Identity.h"
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//进入学生子菜单界面


void studentMenu(Identity*&student)
{
	while (true)
	{
		//调用学生子菜单
		student->operMenu();  //这是一个多态的接口

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			stu->applyOrder();

		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3) //查看所有人预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{

		}
		else
		{
			delete student; //销毁掉堆区的对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入教师的子菜单界面
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu(); //
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;

		if (select == 1)//申请预约
		{
			tea->showAllOrder();

		}
		else if (select == 2)
		{
			tea->validOrder();;
		}
		else
		{
			delete teacher; //销毁掉堆区的对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入管理员的子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员子菜单(这里是多态，利用父类的指针访问子类的函数)
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;
		//接收用户选项
		cin >> select;
		if (select == 1)//添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();

		}
		else if (select == 4)//清空预约
		{
			cout << "机房预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager; //销毁掉堆区的对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}




//一个全局的登录函数封装好的
void LoginIn(string fileName, int type)
{
	Identity * person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);   //相当于一个数据库来验证登录

	//判断
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户的信息
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		///学生身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			//这里相当于按照空格去右移然后一个个去读取

		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
			cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;
			cout << endl;
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			//这里相当于按照空格去右移然后一个个去读取

		{
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				teacherMenu(person);
				return;
				
			}
			cout << endl;
		}

		
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
			//这里相当于按照空格去右移然后一个个去读取

		{
			//与用户输入的信息做对比
			if ( fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name,pwd);

				//进入管理员子菜单界面
				managerMenu(person);
				return;
			}
			cout << endl;
		}
	}
	cout << "验证登录失败" << endl;
	system("pause");
	system("cls");



}
int main()
{
	int select;
	while (true)
	{
		cout << "==================  欢迎来到机房预约系统 ================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t --------------------------\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          1.学生代表       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          2.老    师       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          3.管 理 员       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          0.退    出       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t --------------------------\n";
		
		cout << "请输入您的选择：  ";
		cin >> select;
		switch (select)
		{
		case 1://学生
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误请重新选择" << endl;
			system("pause");   //这个就是按任意键继续
			system("cls");
			break;
		}

	}
	
		system("pause");

}
/*
1 先写一个思维导图做好需求分析
2一般我们写这样一个系统可以先把要做的一个架子做出来，然后再
去写具体的实现
3将登陆模块封装起来.··················································1··
*/