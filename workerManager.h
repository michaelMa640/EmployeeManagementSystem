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
	//��ʾ�˵�
	void Show_Menu();
	//����Ա��
	void Add_Emp();
	//�˳�ϵͳ
	void exitSystem();
	~WorkerManager();

	//��¼�ļ���Ա������
	int m_EmpNum;
	//Ա������ָ��
	Worker** EmpArray;
};

