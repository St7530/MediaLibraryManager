#include <iostream>
#include "AddItem.h"
#include "DeleteItem.h"
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

void EditItem() { // 编辑物品
	system("cls");

	// Gather information
	int id;
	cout << "输入要编辑物品的编号：";
	cin >> id;
	cout << endl;
	if (!HasItem(id))
	{
		cerr << "该编号不存在！" << endl;
		system("pause");
		return;
	}
	ShowItem(GetLineById(id));
	int confirm;
	cout << endl << "输入 1 确认编辑，输入其它值取消编辑：";
	cin >> confirm;
	if (confirm != 1)
	{
		cout << endl << "已取消编辑。" << endl;
		system("pause");
		return;
	}

	// Delete item
	if (DeleteItem(id) != 0)
	{
		cerr << "Error!" << endl;
		system("pause");
		return;
	}

	// Add item
	if (AddItem(id) != 0)
	{
		cerr << "Error!" << endl;
		system("pause");
		return;
	}

	cout << endl << "编辑成功。";
	system("pause");
}