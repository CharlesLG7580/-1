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
		int pos = date.find(":");   //这里就是把date节奏了
		if (pos != -1)		//-1就是没找到
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);//这里用到了截取字符串的方法，后面的参数就是起始位置和截取的个数
			m.insert(make_pair(key, value));

		}

		pos = interval.find(":");   //这里就是把date节奏了
		if (pos != -1)		//-1就是没找到
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);//这里用到了截取字符串的方法，后面的参数就是起始位置和截取的个数
			m.insert(make_pair(key, value));

		}
		pos = stuId.find(":");   //这里就是把date节奏了
		if (pos != -1)		//-1就是没找到
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);//这里用到了截取字符串的方法，后面的参数就是起始位置和截取的个数
			m.insert(make_pair(key, value));
		}

		pos = stuName.find(":");   //这里就是把date节奏了
		if (pos != -1)		//-1就是没找到
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);//这里用到了截取字符串的方法，后面的参数就是起始位置和截取的个数
			m.insert(make_pair(key, value));
		}
		pos =roomId.find(":");   //这里就是把date节奏了
		if (pos != -1)		//-1就是没找到
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);//这里用到了截取字符串的方法，后面的参数就是起始位置和截取的个数
			m.insert(make_pair(key, value));
		}

		pos = status.find(":");   //这里就是把date节奏了
		if (pos != -1)		//-1就是没找到
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);//这里用到了截取字符串的方法，后面的参数就是起始位置和截取的个数
			m.insert(make_pair(key, value));
		}

		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
		
	}
	ifs.close();

	/*//测试最大map容器
	for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "key= " << it->first << "value=" << endl;
		for (map<string, string>::iterator mit = (*it).second.begin(); mit != (*it).second.end(); mit++)
		{
			cout << "key=" << mit->first << "value" << mit->second <<endl;
		}
	}*/
}