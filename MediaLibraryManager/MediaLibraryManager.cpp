// "main"

#include <iostream>
#include <fstream>
#include "Globals.h"
#include "ShowLibrary.h"
#include "FindItem.h"
#include "AddItem.h"
#include "EditItem.h"
#include "DeleteItem.h"
#include "ShowStats.h"
#include "SaveLibrary.h"
#include "Exit.h"
using namespace std;

Resource* res[100];
bool isChanged = false;

int main()
{
	// Initialize system
	ifstream inFile("Library.txt");
	if (!inFile) // Generate example Library.txt
	{
		ofstream outFile("Library.txt");
		outFile << "1 Book 示例标题 示例作者 adult 示例出版社 12345678 75";
		outFile.close();
	}
	inFile.close();
	inFile.open("Library.txt");

	// Load res[]
	cout << "正在加载物品…";
	string tmpLine;
	for (int i = 0; ; i++)
	{
		int id, additional2, additional3;	string type, title, author, rate, additional1;
		inFile >> id >> type >> title >> author >> rate >> additional1 >> additional2 >> additional3;
		if (type == "Book")
		{
			res[i] = new Book(id, title, author, rate, additional1, additional2, additional3);
		}
		else if (type == "VCD")
		{
			res[i] = new VCD(id, title, author, rate, additional1, additional2, additional3);
		}
		else if (type == "Picture")
		{
			res[i] = new Picture(id, title, author, rate, additional1, additional2, additional3);
		}
		else
			break;
	}
	inFile.close();

	while (true)
	{
		// Home
		system("title 媒体库管理系统");
		system("cls");
		cout << "------------------" << endl
			<< "媒体库管理系统" << endl
			<< "------------------" << endl
			<< endl
			<< "[1] 显示物品库" << endl
			<< "[2] 查找物品" << endl
			<< "[3] 添加物品" << endl
			<< "[4] 编辑物品" << endl
			<< "[5] 删除物品" << endl
			<< "[6] 统计信息" << endl
			<< "[7] 保存更改" << endl
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
		case 7: // 保存更改
			SaveLibrary();
			break;
		case 0: // 退出
			choice = Exit();
			switch (choice)
			{
			case 0: // Exit
				return 0;
			case 1: // Do not exit
				break;
			}
			break;
		}
	}
}