#include<iostream>
using namespace std;
#include"student.h"

Student::Student()
{

}

Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
}

void Student::operMenu()
{
	cout << "��ӭѧ������" << this->m_Name << "��¼" << endl;
	cout << "\t\t --------------------------\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          1.����ԤԼ       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ   |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          3.�鿴����ԤԼ   |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          4.ȡ��ԤԼ       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t|          0.ע����¼       |\n";
	cout << "\t\t|                           |\n";
	cout << "\t\t --------------------------\n";

	cout << "����������ѡ��  ";
}

//ԤԼ
void Student::applyOrder()
{


	int date = 0;
	int interval = 0;
	int room = 0;


	cout << "�������ŵ�ʱ��Ϊ��һ������" << endl;//////////////
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1.��һ" << endl;
	cout << "2.�ܶ�" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "5.����" << endl;

	

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;

	}
	cout << "����������ԤԼ��ʱ���" << endl;/////////////////////////
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�����" << endl;/////////////////////////////
	for (int i = 0; i < vCom.size(); i++)
	{
		cout << vCom[i].m_ComId << "�Ż�������Ϊ��" << vCom[i].m_MaxNum << endl;
	}
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;				//���Կ�����������ݶ����Լ�ֵ�Ե���ʽ���ڵ�
	ofs.open(ORDER_FILE, ios::app);			//�������ǿ�������һ��map���洢
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << " ";
	ofs << endl;

	ofs.close();
	system("pause");
	system("cls");

}

void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << of.m_Size;
	for (int i = 0; i < of.m_Size; i++)
	{
		//stringתint
		//string����c_str()תΪconst char*��ת��Ϊc����ַ�����
		//����atoi(const char*��תint
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			cout << "ԤԼ����: ��" << of.m_orderData[i]["date"];
			cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");//��Ŀ�������ֵ
			cout << "������: " << of.m_orderData[i]["roomId"];
			string status = "״̬";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";

			}
			else 
			{
				status += "ԤԼ��ȡ��";

			}
			cout << status << endl;
			
		}
	}
	system("pause");
	system("cls");

}


void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		//stringתint
		//string����c_str()תΪconst char*��ת��Ϊc����ַ�����
		//����atoi(const char*��תint
		cout << i + 1 << ". ";
			cout << "ԤԼ����: ��" << of.m_orderData[i]["date"];
			cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");//��Ŀ�������ֵ
			cout << "������: " << of.m_orderData[i]["roomId"];
			cout<<"ѧ�� "<<of.m_orderData[i]["stuId"];
			cout << "ѧ��������" << of.m_orderData[i]["stuName"];
			string status = " ״̬";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";

			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";

			}
			else
			{
				status += "ԤԼ��ȡ��";

			}
			cout << status << endl;

	
	}
	system("pause");
	system("cls");

}
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�����ԤԼ�ɹ��ļ�¼����ȡ����" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (this->m_Id == atoi(of.m_orderData[i]["stuId"].c_str()))
		{
			v.push_back(i);
			cout << index++ << ". ";
			cout << "ԤԼ����: ��" << of.m_orderData[i]["date"];
			cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");//��Ŀ�������ֵ
			cout << "������: " << of.m_orderData[i]["roomId"];
			cout << "ѧ�� " << of.m_orderData[i]["stuId"];
			cout << "ѧ��������" << of.m_orderData[i]["stuName"];
			string status = " ״̬";
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";

			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "ԤԼʧ�ܣ����δͨ��";

			}
			else
			{
				status += "ԤԼ��ȡ��";

			}
		}
	}
	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_orderData[v[select - 1]]["status"] == "0";
				//of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");

}