#include<iostream>
using namespace std;
#include"manager.h"

Manager::Manager()
{

}

Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա����Ϣ
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������ȡ�������ļ�����ʦ��ѧ������Ϣ
	this->initVector();

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������" << vCom.size();
}
void Manager::operMenu()
{
	cout << "��ӭ����Ա"<<this->m_Name <<"��¼"<< endl;
	cout << "\t\t --------------------------\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          1.�����˺�       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          2.�鿴�˺�       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          3.�鿴����       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          4.���ԤԼ       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          0.ע����¼       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t --------------------------\n";

	cout << "����������ѡ��  ";

}
//�����˺�
void Manager::addPerson()
{
	cout << "�����������˺ŵ�����" << endl;
	cout << "1 ����ѧ��" << endl;
	cout << "2 ������ʦ" << endl;
	string fileName;
	string tip;
	string errorTip;

	ofstream ofs; //�ļ������Ķ���
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//����ѧ��
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errorTip = "ѧ���ظ�������������";

	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�,����������";
	}
	ofs.open(fileName, ios:: out | ios::app);

	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)   //������Ҫ�������id����ȥ�ز�����
	{
		cin >> id;
		bool ret=checkRepeat(id, select);
		if (ret) //���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	

	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "���ӳɹ�" << endl;

	
	system("pause");
	system("cls");
	ofs.close();

	//���ó�ʼ�������Ľӿڿ��Է�ֹbug���֣����bug�������������ӵ�ʱ������ظ������µ�
	this->initVector();
}


void Manager::initVector()
{
	//ȷ�������ǿյ�
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ ѧ����ʦ

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ; " << vStu.size() << endl;
	ifs.close();


	ifs.open(TEACHER_FILE, ios::in);
	
	Teacher t;
	while (ifs >> t.id && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ; " << vTea.size() << endl;
	ifs.close();
}


bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
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
	cout << "ѧ�ţ� " << s.m_Id << "������ " << s.m_Name << "���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& s)
{
	cout << "ְ���ţ� " << s.id << "������ " << s.m_Name << "���룺" << s.m_Pwd << endl;
}
void Manager::showPerson()
{
	cout << "��ѡ��鿴�����ݣ� " << endl;
	cout << "1 �鿴���е�ѧ��" << endl;
	cout << "2 �鿴���е���ʦ" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

	}
	else 
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ����" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);

	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ� " << it->m_ComId << "������������� " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}


void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);  //�������һ������ļ��ķ�����
	ofs.close();

	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}