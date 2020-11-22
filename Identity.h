#pragma once
#include<iostream>
using namespace std;
#include<string>
//身份基类
class Identity
{
public:

	//操作类， 纯虚函数  我们相当于把公共的部分封装起来一般就是用纯虚函数
	virtual void operMenu() = 0;  

	string m_Name;
	string m_Pwd;
};
