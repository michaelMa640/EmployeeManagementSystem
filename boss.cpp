#include<iostream>
using namespace std;
#include"boss.h"

Boss::Boss(int id, string name, string DeptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Boss::getInfo()
{
	cout << "Ա�����: " << m_Id
		<< "/t������ " << m_Name
		<< "/t��λ�� " << getDeptName
		<< "/t�������ݣ���������������" << endl;
}

string Boss::getDeptName()
{
	return "�ϰ�";
}