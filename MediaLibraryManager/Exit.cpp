#include <iostream>
#include "Globals.h"
#include "SaveLibrary.h"
using namespace std;

int Exit() { // 0 - Exit, 1 - Do not exit
	system("cls");
	if (isChanged)
	{
		cout << "更改尚未保存！" << endl
			<< "[1] 保存并退出" << endl
			<< "[2] 不保存并退出" << endl
			<< "[3] 取消退出" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // 保存并退出
			SaveLibrary();
			return 0;
		case 2: // 不保存并退出
			return 0;
		case 3: // 取消退出
			return 1;
		}
	}
	return 0;
}