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
	cout << "Ա�����: " << m_Id
		<< "/t������ " << m_Name
		<< "/t��λ�� " << getDeptName
		<< "/t�������ݣ���ɾ����õĹ���" << endl;
}

string Employee::getDeptName()
{
	return string("Ա��");
}