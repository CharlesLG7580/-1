#include"orderFile.h"

OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;*/

		//date:1
		string key;
		string value;
		map<string, string>m;
		int pos = date.find(":");   //������ǰ�date������
		if (pos != -1)		//-1����û�ҵ�
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);//�����õ��˽�ȡ�ַ����ķ���������Ĳ���������ʼλ�úͽ�ȡ�ĸ���
			m.insert(make_pair(key, value));

		}

		pos = interval.find(":");   //������ǰ�date������
		if (pos != -1)		//-1����û�ҵ�
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);//�����õ��˽�ȡ�ַ����ķ���������Ĳ���������ʼλ�úͽ�ȡ�ĸ���
			m.insert(make_pair(key, value));

		}
		pos = stuId.find(":");   //������ǰ�date������
		if (pos != -1)		//-1����û�ҵ�
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);//�����õ��˽�ȡ�ַ����ķ���������Ĳ���������ʼλ�úͽ�ȡ�ĸ���
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");   //������ǰ�date������
		if (pos != -1)		//-1����û�ҵ�
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);//�����õ��˽�ȡ�ַ����ķ���������Ĳ���������ʼλ�úͽ�ȡ�ĸ���
			m.insert(make_pair(key, value));
		}
		pos =roomId.find(":");   //������ǰ�date������
		if (pos != -1)		//-1����û�ҵ�
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);//�����õ��˽�ȡ�ַ����ķ���������Ĳ���������ʼλ�úͽ�ȡ�ĸ���
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");   //������ǰ�date������
		if (pos != -1)		//-1����û�ҵ�
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);//�����õ��˽�ȡ�ַ����ķ���������Ĳ���������ʼλ�úͽ�ȡ�ĸ���
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
		
	}
	ifs.close();

	/*//�������map����
	for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "key= " << it->first << "value=" << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		{
			cout << "key=" << mit->first << "value" << mit->second <<endl;
		}
	}*/
}