#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

class WorkerManager
{
public:
	WorkerManager();
	//显示菜单
	void Show_Menu();
	//增加员工
	void Add_Emp();
	//退出系统
	void exitSystem();
	~WorkerManager();

	//记录文件中员工人数
	int m_EmpNum;
	//员工数组指针
	Worker** EmpArray;
};

