#include <iostream>
#include "Globals.h"
#include "FindItem.h"
using namespace std;

static void AddResource(string& title, string& author, string& rate) { // 添加物品 - 输入 Resource 属性
	cout << "输入标题：";	cin >> title;
	cout << "输入作者：";	cin >> author;
	cout << "输入评级：";	cin >> rate;
}

void AddItem(int id) {
	// Calculate res[] count
	int count = 0;
	while (res[count])
	{
		count++;
	}

	cout << "选择物品类别——[1] 图书, [2] 视频光盘, [3] 图画: ";
	int choice;
	cin >> choice;
	int additional2, additional3;	string type, title, author, rate, additional1;
	switch (choice)
	{
	case 1: // 图书
		type = "Book";
		AddResource(title, author, rate);
		cout << "输入出版社：";	cin >> additional1;
		cout << "输入 ISBN 号：";	cin >> additional2;
		cout << "输入页数：";	cin >> additional3;
		res[count] = new Book(id, title, author, rate, additional1, additional2, additional3);
		break;
	case 2: // 视频光盘
		type = "VCD";
		AddResource(title, author, rate);
		cout << "输入出品者：";	cin >> additional1;
		cout << "输入出品年份：";	cin >> additional2;
		cout << "输入视频时长：";	cin >> additional3;
		res[count] = new VCD(id, title, author, rate, additional1, additional2, additional3);
		break;
	case 3: // 图画
		type = "Picture";
		AddResource(title, author, rate);
		cout << "输入出口国籍：";	cin >> additional1;
		cout << "输入长（以厘米计，整数）：";	cin >> additional2;
		cout << "输入宽（以厘米计，整数）：";	cin >> additional3;
		res[count] = new Picture(id, title, author, rate, additional1, additional2, additional3);
		break;
	}
}

void AddItem() { // 添加物品
	system("title 添加物品 - 媒体库管理系统");
	system("cls");

	// Input id
	int id;
	cout << "输入编号：";
	cin >> id;
	if (HasId(id))
	{
		cerr << endl << "该编号已存在！" << endl;
		system("pause");
		return;
	}
	else
	{
		AddItem(id);
		isChanged = true;
		cout << endl << "已添加物品。" << endl;
		system("pause");
		return;
	}

	cerr << endl << "无效的输入！" << endl;
	system("pause");
}