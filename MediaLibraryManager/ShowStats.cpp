#include <iostream>
#include "FindItem.h"
using namespace std;

void ShowStats() { // 统计信息
	system("title 统计信息 - 媒体库管理系统");
	system("cls");

	cout << "总物品数：\t" << GetResourceCount() << endl << endl
		<< "图书数：\t" << GetResourceCount(1) << endl
		<< "视频光盘数：\t" << GetResourceCount(2) << endl
		<< "图画数：\t" << GetResourceCount(3) << endl;
	cout << endl;

	system("pause");
}