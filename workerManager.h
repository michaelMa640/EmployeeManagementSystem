#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();
	//显示菜单
	void Show_Menu();
	//增加员工
	void Add_Emp();
	//统计文件中人数
	int get_EmpNum();
	//保存文件
	void save();
	//初始化员工
	void init_Emp();
	//退出系统
	void exitSystem();
	~WorkerManager();

	//判断文件是否为空 标志
	bool m_FileIsEmpty;
	//记录文件中员工人数
	int m_EmpNum;
	//员工数组指针
	Worker** EmpArray;
};

