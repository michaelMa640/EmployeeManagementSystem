#pragma once
#include<iostream>
using namespace std;
#include"worker.h";

class Employee :public Worker
{
	Employee(int id,string name, string deptId);
	void showInfo();
	string getDeptName();
};