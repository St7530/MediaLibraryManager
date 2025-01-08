#include <iostream>
#include <fstream>
#include "Globals.h"
#include "ShowLibrary.h"
using namespace std;

void FindBy(int way) { // way 指对应内容在库中的位置，也是后方读取内容时需要循环的次数
	string findContent;

	switch (way)
	{
	case 1: // 按编号
		cout << "输入物品编号：";
		cin >> findContent;
		break;
	case 2: // 按类别
		cout << "选择物品类别——[1] 图书, [2] 视频光盘, [3] 图画：";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			findContent = "Book";
			break;
		case 2:
			findContent = "VCD";
			break;
		case 3:
			findContent = "Picture";
			break;
		}
		break;
	case 3: // 按标题
		cout << "输入物品标题：";
		cin >> findContent;
		break;
	}

	ifstream inFile("Library.txt");
	cout << endl;
	int count = 0;

	for (int i = 0; linePos[i] > -1; i++)
	{
		inFile.seekg(linePos[i]);
		string tmpContent;
		for (int j = 0; j < way; j++)
		{
			inFile >> tmpContent;
		}
		if (tmpContent == findContent)
		{
			ShowItem(i);
			count++;
		}
	}
	cout << endl << "共找到 " << count << " 个物品。" << endl;
	inFile.close();
}

void FindItem() { // 查找物品
	system("cls");
	cout << "选择查找方式——[1] 按编号, [2] 按类别, [3] 按标题: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: // 按编号
		FindBy(1);
		break;
	case 2: // 按类别
		FindBy(2);
		break;
	case 3: // 按标题
		FindBy(3);
		break;
	}
	system("pause");
}

int GetResourceCount(int resourceClass) { // 0 - All, 1 - Book, 2 - VCD, 3 - Picture
	ifstream inFile("Library.txt");
	string findContent;
	int count = 0;

	switch (resourceClass)
	{
	case 0: // All
		for (int i = 0; linePos[i] > -1; i++)
		{
			count++;
		}
		inFile.close();
		return count;
		break;
	case 1: // Book
		findContent = "Book";
		break;
	case 2: // VCD
		findContent = "VCD";
		break;
	case 3: // Picture
		findContent = "Picture";
		break;
	}

	for (int i = 0; linePos[i] > -1; i++)
	{
		inFile.seekg(linePos[i]);
		string tmpContent;
		for (int j = 0; j < 2; j++)
		{
			inFile >> tmpContent;
		}
		if (tmpContent == findContent)
		{
			count++;
		}
	}
	inFile.close();
	return count;
}

bool HasItem(int id) {
	ifstream inFile("Library.txt");
	for (int i = 0; linePos[i] > -1; i++)
	{
		inFile.seekg(linePos[i]);
		int tmpContent;
		inFile >> tmpContent;
		if (tmpContent == id)
		{
			return true;
		}
	}
	return false;
}

int GetLineById(int id) {
	if (!HasItem(id))
	{
		cerr << "Error!";
		return -1;
	}
	ifstream inFile("Library.txt");
	for (int i = 0; linePos[i] > -1; i++)
	{
		inFile.seekg(linePos[i]);
		int tmpContent;
		inFile >> tmpContent;
		if (tmpContent == id)
		{
			return i;
		}
	}
}