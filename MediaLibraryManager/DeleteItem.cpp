#include <iostream>
#include "Globals.h"
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

void DeleteItem(int id) {
	for (int i = GetIndexById(id); res[i]; i++)
	{
		if (res[i + 1])
		{
			res[i] = res[i+1];
		}
		else
		{
			res[i] = NULL;
		}
	}
}

void DeleteItem() { // 删除物品
	system("title 删除物品 - 媒体库管理系统");
	system("cls");

	// Gather information
	int id;
	cout << "输入要删除物品的编号：";
	cin >> id;
	cout << endl;
	if (!HasId(id))
	{
		cerr << "该编号不存在！" << endl;
		system("pause");
		return;
	}
	res[GetIndexById(id)]->Show();
	int confirm;
	cout << endl << "输入 1 确认删除，输入其它值取消删除：";
	cin >> confirm;
	if (confirm != 1)
	{
		cout << endl << "已取消删除。" << endl;
		system("pause");
		return;
	}

	DeleteItem(id);
	isChanged = true;
	cout << endl << "已删除该物品。" << endl;
	system("pause");
}