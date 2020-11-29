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
	//ͳ���ļ�������
	int get_EmpNum();
	//�����ļ�
	void save();
	//��ʼ��Ա��
	void init_Emp();
	//�˳�ϵͳ
	void exitSystem();
	~WorkerManager();

	//�ж��ļ��Ƿ�Ϊ�� ��־
	bool m_FileIsEmpty;
	//��¼�ļ���Ա������
	int m_EmpNum;
	//Ա������ָ��
	Worker** EmpArray;
};

