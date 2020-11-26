#include"boss.h"

Boss::Boss(int id, string name, int DeptId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

void Boss::showInfo()
{
	cout << "员工编号: " << m_Id
		<< "\t姓名： " << m_Name
		<< "\t岗位： " << getDeptName()
		<< "\t工作内容：向经理发布工作任务" << endl;
}

string Boss::getDeptName()
{
	return string("老板");
}