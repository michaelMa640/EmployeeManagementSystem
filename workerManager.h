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
	//��ʾ�˵�
	void Show_Menu();
	//����Ա��
	void Add_Emp();
	//�����ļ�
	void save();
	//�˳�ϵͳ
	void exitSystem();
	~WorkerManager();

	//��¼�ļ���Ա������
	int m_EmpNum;
	//Ա������ָ��
	Worker** EmpArray;
};

