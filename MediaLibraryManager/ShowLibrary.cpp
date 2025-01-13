#include <iostream>
#include "Globals.h"
using namespace std;

void ShowLibrary() { // 显示物品库
	system("title 物品库 - 媒体库管理系统");
	system("cls");

	for (int i = 0; res[i]; i++)
	{
		res[i]->Show();
	}

	cout << endl;
	system("pause");
}