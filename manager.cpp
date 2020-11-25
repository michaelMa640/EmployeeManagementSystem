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
	cout << "员工编号: " << m_Id
		<< "/t姓名： " << m_Name
		<< "/t岗位： " << getDeptName
		<< "/t工作内容：完成老板布置的工作并向员工下发工作" << endl;
}

string Manager::getDeptName()
{
	return "经理";
}