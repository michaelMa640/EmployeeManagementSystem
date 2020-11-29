#include"workerManager.h"
//#include<string>

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//Ա������ָ���ʼ��
		this->EmpArray = NULL;
		//Ա��������ʼ��Ϊ0
		this->m_EmpNum = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ������
		//Ա������ָ���ʼ��
		this->EmpArray = NULL;
		//Ա��������ʼ��Ϊ0
		this->m_EmpNum = 0;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ����ڲ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ: " << num << endl;
	this->m_EmpNum = num;

	//��ʼ��Ա��
	//���ٿռ�
	this->EmpArray = new Worker * [this->m_EmpNum];
	//�洢����
	this->init_Emp();
	
	//���Դ���
	/*for (int i = 0; i < this->m_EmpNum; i++)
	{
		cout << "ְ����ţ�" << this->EmpArray[i]->m_Id
			<< " ְ��������" << this->EmpArray[i]->m_Name
			<< " ְ����λ��" << this->EmpArray[i]->m_DeptId << endl;
	}*/
}

//��ʾ�˵�
void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//����Ա��
void WorkerManager::Add_Emp()
{
	cout << "��������Ҫ��ӵ�Ա������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		//����ԭ�����ݵ��¿ռ���
		if (this->EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "�������" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;

			cout << "�������" << i + 1 << "��Ա���ĸ�λ" << endl;
			cout << "1����ͨԱ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			//���������λ����жϲ�д��
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
		//�ͷ�ԭ�пռ�
		delete[] this->EmpArray;
		//�����¿ռ��ָ��
		this->EmpArray = newSpace;
		//�����µ�Ա������
		this->m_EmpNum = newSize;
		this->m_FileIsEmpty = false;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "��Ա��!" << endl;
		this->save();
		//delete newSpace;
	}
	else
	{
		cout << "��������!" << endl;
	}
	system("pause");
	system("cls");
}

//ͳ���ļ�������
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

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int index=0;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId = 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId = 2)
		{
			worker = new Manager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//����
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->EmpArray[i]->m_Id << " "
			<< this->EmpArray[i]->m_Name << " "
			<< this->EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

//�˳�����
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}

//��ʾԱ��
void WorkerManager::show_Emp()
{
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "û����Ϣ" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬������ʾ�ӿ�
			this->EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->EmpArray != NULL)
	{
		delete[] this->EmpArray;
		this->EmpArray = NULL;
	}
}