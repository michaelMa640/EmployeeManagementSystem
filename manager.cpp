#include<iostream>
using namespace std;
#include"manager.h"

Manager::Manager(int id, string name, string DeptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Manager::showInfo()
{
	cout << "Ա�����: " << m_Id
		<< "/t������ " << m_Name
		<< "/t��λ�� " << getDeptName
		<< "/t�������ݣ�����ϰ岼�õĹ�������Ա���·�����" << endl;
}

string Manager::getDeptName()
{
	return "����";
}