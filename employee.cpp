#include<iostream>
using namespace std;
#include"employee.h"

Employee::Employee(int id, string name, string deptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = deptId;
}

void Employee::showInfo()
{
	cout << "员工编号: " << m_Id
		<< "/t姓名： " << m_Name
		<< "/t岗位： " << getDeptName
		<< "/t工作内容：完成经理布置的工作" << endl;
}

string Employee::getDeptName()
{
	return string("员工");
}