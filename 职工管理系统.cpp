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
		cout << "请选择您要进行的操作： " << endl;
		cin >> choice;
		
		//菜单操作
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加职工
			break;
		case 2://显示职工
			break;
		case 3://删除职工
			break;
		case 4://修改职工
			break;
		case 5://查找职工
			break;
		case 6://排序职工
			break;
		case 7://清空文件
			break;
		default://
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}