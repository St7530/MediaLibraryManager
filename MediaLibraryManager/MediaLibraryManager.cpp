// "main"

#include <iostream>
#include <fstream>
#include <string>
#include "Globals.h"
#include "ShowLibrary.h"
#include "FindItem.h"
#include "AddItem.h"
#include "EditItem.h"
#include "DeleteItem.h"
#include "ShowStats.h"
using namespace std;

streampos linePos[100];

int main()
{
	// Initialize
	system("title 媒体库管理系统");
	ifstream inFile("Library.txt");
	if (!inFile)
	{
		ofstream outFile("Library.txt"); // Generate example Library.txt
		outFile << "1 Book 示例标题 示例作者 adult 示例出版社 12345678 75";
		outFile.close();
	}
	inFile.close();

	while (true)
	{
		// Calculate linePos
		ifstream inFile("Library.txt");
		string tmpLine;
		linePos[0] = 0;
		for (int i = 1; i < 100; i++)
		{
			linePos[i] = -1;
		}
		for (int i = 1; getline(inFile, tmpLine); i++)
		{
			linePos[i] = inFile.tellg();
		}
		inFile.close();

		// Home
		system("cls");
		cout << "[1] 显示物品库" << endl
			<< "[2] 查找物品" << endl
			<< "[3] 添加物品" << endl
			<< "[4] 编辑物品" << endl
			<< "[5] 删除物品" << endl
			<< "[6] 统计信息" << endl
			<< "[0] 退出" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: // 显示物品库
			ShowLibrary();
			break;
		case 2: // 查找物品
			FindItem();
			break;
		case 3: // 添加物品
			AddItem();
			break;
		case 4: // 编辑物品
			EditItem();
			break;
		case 5: // 删除物品
			DeleteItem();
			break;
		case 6: // 统计信息
			ShowStats();
			break;
		case 0:
			return 0;
		}
	}
}