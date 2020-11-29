#include"workerManager.h"
//#include<string>

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		//初始化属性
		//员工数组指针初始化
		this->EmpArray = NULL;
		//员工人数初始化为0
		this->m_EmpNum = 0;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		//初始化属性
		//员工数组指针初始化
		this->EmpArray = NULL;
		//员工人数初始化为0
		this->m_EmpNum = 0;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在不为空
	int num = this->get_EmpNum();
	cout << "职工人数为: " << num << ednl;
	this->m_EmpNum = num;
}

//显示菜单
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//增加员工
void WorkerManager::Add_Emp()
{
	cout << "请输入您要添加的员工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		//复制原有数据到新空间下
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第" << i+1 << "个员工的编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;

			cout << "请输入第" << i + 1 << "个员工的岗位" << endl;
			cout << "1、普通员工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			//根据输入岗位序号判断并写入
			Worker* worker = NULL;
			switch(dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] this->EmpArray;
		//更改新空间的指向
		this->EmpArray = newSpace;
		//更新新的员工人数
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		//提示信息
		cout << "成功添加" << addNum << "名员工!" << endl;
		this->save();
		delete newSpace;
	}
	else
	{
		cout << "输入有误!" << endl;
	}
	system("pause");
	system("cls");
}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> name && ifs >> name && ifs >> dId)
	{
		num++;
	}
	return num;
}

//保存
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::app);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->EmpArray[i]->m_Id << " "
			<< this->EmpArray[i]->m_Name << " "
			<< this->EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//退出程序
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager()
{
	if (this->EmpArray != NULL)
	{
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}