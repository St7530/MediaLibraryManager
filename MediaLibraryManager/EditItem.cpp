#include <iostream>
#include "Globals.h"
#include "AddItem.h"
#include "DeleteItem.h"
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

void EditItem() { // 编辑物品
	system("title 编辑物品 - 媒体库管理系统");
	system("cls");

	// Gather information
	int id;
	cout << "输入要编辑物品的编号：";
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
	cout << endl << "输入 1 确认编辑，输入其它值取消编辑：";
	cin >> confirm;
	cout << endl;
	if (confirm != 1)
	{
		cout << "已取消编辑。" << endl;
		system("pause");
		return;
	}

	DeleteItem(id);
	AddItem(id);
	isChanged = true;
	cout << endl << "编辑成功。" << endl;
	system("pause");
}