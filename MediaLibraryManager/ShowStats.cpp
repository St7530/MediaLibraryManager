#include <iostream>
#include "FindItem.h"
using namespace std;

void ShowStats() {
	system("cls");

	cout << "总物品数：" << GetResourceCount(0) << endl << endl
		<< "图书数：" << GetResourceCount(1) << endl
		<< "视频光盘数：" << GetResourceCount(2) << endl
		<< "图画数：" << GetResourceCount(3) << endl;
	cout << endl;

	system("pause");
}