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
			if (res[i]->GetId() == findContent)
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
		cin >> choice;
		string findContent;
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
			if (res[i]->GetTitle() == findContent)
			{
				res[i]->Show();
				count++;
			}
		}
	}
		break;
	}
	cout << endl << "共找到 " << count << " 个物品。" << endl;
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
	int count = 0;
	if (resourceClass==0) // All
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

bool HasId(int id) {
	for (int i = 0; res[i]; i++)
	{
		if (res[i]->GetId() == id)
		{
			return true;
		}
	}
	return false;
}

int GetIndexById(int id) { // 用物品的 id 获取其在 res[] 的索引
	for (int i = 0; res[i]; i++)
	{
		if (res[i]->GetId() == id)
		{
			return i;
		}
	}
}