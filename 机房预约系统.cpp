#include<iostream>
using namespace std;
#include<fstream>
#include"Identity.h"
#include<string>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include"manager.h"

//����ѧ���Ӳ˵�����


void studentMenu(Identity*&student)
{
	while (true)
	{
		//����ѧ���Ӳ˵�
		student->operMenu();  //����һ����̬�Ľӿ�

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			stu->applyOrder();

		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴������ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{

		}
		else
		{
			delete student; //���ٵ������Ķ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�����ʦ���Ӳ˵�����
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu(); //
		Teacher* tea = (Teacher*)teacher;
		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			tea->showAllOrder();

		}
		else if (select == 2)
		{
			tea->validOrder();;
		}
		else
		{
			delete teacher; //���ٵ������Ķ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�������Ա���Ӳ˵�����
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//���ù���Ա�Ӳ˵�(�����Ƕ�̬�����ø����ָ���������ĺ���)
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;
		//�����û�ѡ��
		cin >> select;
		if (select == 1)//����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();

		}
		else if (select == 4)//���ԤԼ
		{
			cout << "����ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager; //���ٵ������Ķ���
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}




//һ��ȫ�ֵĵ�¼������װ�õ�
void LoginIn(string fileName, int type)
{
	Identity * person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(fileName, ios::in);   //�൱��һ�����ݿ�����֤��¼

	//�ж�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û�����Ϣ
	int id = 0;
	string name;
	string pwd;

	if (type == 1)
	{
		cout << "���������ѧ�ţ�" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "����������ְ���ţ�" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	if (type == 1)
	{
		///ѧ�������֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			//�����൱�ڰ��տո�ȥ����Ȼ��һ����ȥ��ȡ

		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
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
		//��ʦ�����֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			//�����൱�ڰ��տո�ȥ����Ȼ��һ����ȥ��ȡ

		{
			//���û��������Ϣ���Ա�
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
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
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
			//�����൱�ڰ��տո�ȥ����Ȼ��һ����ȥ��ȡ

		{
			//���û��������Ϣ���Ա�
			if ( fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name,pwd);

				//�������Ա�Ӳ˵�����
				managerMenu(person);
				return;
			}
			cout << endl;
		}
	}
	cout << "��֤��¼ʧ��" << endl;
	system("pause");
	system("cls");



}
int main()
{
	int select;
	while (true)
	{
		cout << "==================  ��ӭ��������ԤԼϵͳ ================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t --------------------------\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          1.ѧ������       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          2.��    ʦ       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          3.�� �� Ա       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t|          0.��    ��       |\n";
		cout << "\t\t|                           |\n";
		cout << "\t\t --------------------------\n";
		
		cout << "����������ѡ��  ";
		cin >> select;
		switch (select)
		{
		case 1://ѧ��
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");   //������ǰ����������
			system("cls");
			break;
		}

	}
	
		system("pause");

}
/*
1 ��дһ��˼ά��ͼ�����������
2һ������д����һ��ϵͳ�����Ȱ�Ҫ����һ��������������Ȼ����
ȥд�����ʵ��
3����½ģ���װ����.����������������������������������������������������������������������������������������������������1����
*/