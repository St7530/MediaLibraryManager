#include <iostream>
#include "Globals.h"
#include "ShowLibrary.h"
using namespace std;

void FindBy(int choice) {
	int count = 0;
	switch (choice)
	{
	case 1: // 按编号
	{
		cout << "输入物品编号：";
		int findContent;
		cin >> findContent;
		cout << endl;
		for (int i = 0; res[i]; i++)
		{
			if (res[i]->id == findContent)
			{
				res[i]->Show();
				count++;
			}
		}
	}
	break;
	case 2: // 按类别
	{
		cout << "选择物品类别——[1] 图书, [2] 视频光盘, [3] 图画：";
		int choice_;
		cin >> choice_;
		string findContent;
		switch (choice_)
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
		default:
			cerr << endl << "无效的输入！";
			findContent = "";
			break;
		}
		cout << endl;
		for (int i = 0; res[i]; i++)
		{
			if (res[i]->GetClassName() == findContent)
			{
				res[i]->Show();
				count++;
			}
		}
	}
	break;
	case 3: // 按标题
	{
		cout << "输入物品标题：";
		string findContent;
		cin >> findContent;
		cout << endl;
		for (int i = 0; res[i]; i++)
		{
			if (res[i]->title == findContent)
			{
				res[i]->Show();
				count++;
			}
		}
	}
	break;
	}
	cout << endl;
	if (count > 0)
	{
		cout << "共找到 " << count << " 个物品。";
	}
	else
	{
		switch (choice)
		{
		case 1:
			cerr << "该编号不存在！";
			break;
		case 2:
			cerr << "该类别没有物品！";
			break;
		case 3:
			cerr << "该标题不存在！";
			break;
		}
	}
}

void FindItem() { // 查找物品
	system("title 查找物品 - 媒体库管理系统");
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
	default:
		cerr << endl << "无效的选择！";
		break;
	}

	cout << endl;
	system("pause");
}

bool HasId(int id) {
	for (int i = 0; res[i]; i++)
	{
		if (res[i]->id == id)
		{
			return true;
		}
	}
	return false;
}

int GetIndexById(int id) { // 用物品的 id 获取其在 res[] 的索引
	for (int i = 0; res[i]; i++)
	{
		if (res[i]->id == id)
		{
			return i;
		}
	}
	return -1;
}

int GetResourceCount(int resourceClass) { // 0 - All (Default), 1 - 图书, 2 - 视频光盘, 3 - 图画
	int count = 0;
	if (resourceClass == 0) // All
	{
		for (int i = 0; res[i]; i++)
		{
			count++;
		}
		return count;
	}
	string findContent;
	switch (resourceClass)
	{
	case 1: // 图书
		findContent = "Book";
		break;
	case 2: // 视频光盘
		findContent = "VCD";
		break;
	case 3: // 图画
		findContent = "Picture";
		break;
	}
	for (int i = 0; res[i]; i++)
	{
		if (res[i]->GetClassName() == findContent)
		{
			count++;
		}
	}
	return count;
}