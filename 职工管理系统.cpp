#include<iostream>
using namespace std;
#include"workerManager.h"

int main()
{
	WorkerManager wm;
	int choice;

	while (true)
	{
		wm.Show_Menu();
		cout << "��ѡ����Ҫ���еĲ����� " << endl;
		cin >> choice;
		
		//�˵�����
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���ְ��
			break;
		case 2://��ʾְ��
			break;
		case 3://ɾ��ְ��
			break;
		case 4://�޸�ְ��
			break;
		case 5://����ְ��
			break;
		case 6://����ְ��
			break;
		case 7://����ļ�
			break;
		default://
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}