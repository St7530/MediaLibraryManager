#include <iostream>
#include <fstream>
#include "FindItem.h"
using namespace std;

void AddResource(ofstream& out) { // 添加物品 - 输入 Resource 属性
	string tmp;
	cout << "输入标题：";	cin >> tmp;	out << tmp << " ";
	cout << "输入作者：";	cin >> tmp;	out << tmp << " ";
	cout << "输入评级：";	cin >> tmp;	out << tmp << " ";
}

int AddItem(int id) {
	ofstream outFile("Library.txt", ios::app);
	if (HasItem(id))
	{
		outFile.close();
		cerr << endl << "编号重复！";
		system("pause");
		return 1;
	}
	outFile << endl;
	outFile << id << " ";

	cout << "选择物品类别——[1] 图书, [2] 视频光盘, [3] 图画: ";
	int choice;
	cin >> choice;
	string tmp;
	switch (choice)
	{
	case 1: // Book
		outFile << "Book ";
		AddResource(outFile);
		cout << "输入出版社：";	cin >> tmp; outFile << tmp << " ";
		cout << "输入 ISBN 号：";	cin >> tmp; outFile << tmp << " ";
		cout << "输入页数：";	cin >> tmp; outFile << tmp;
		break;
	case 2: // VCD
		outFile << "VCD ";
		AddResource(outFile);
		cout << "输入出品者：";	cin >> tmp; outFile << tmp << " ";
		cout << "输入出品年份：";	cin >> tmp; outFile << tmp << " ";
		cout << "输入视频时长：";	cin >> tmp; outFile << tmp;
		break;
	case 3: // Picture
		outFile << "Picture ";
		AddResource(outFile);
		cout << "输入出口国籍：";	cin >> tmp; outFile << tmp << " ";
		cout << "输入长（以厘米计，整数）：";	cin >> tmp; outFile << tmp << " ";
		cout << "输入宽（以厘米计，整数）：";	cin >> tmp; outFile << tmp;
		break;
	};
	outFile.close();
	return 0;
}

void AddItem() { // 添加物品
	system("cls");

	// Input id
	int id;
	cout << "输入编号：";
	cin >> id;
	AddItem(id);

	cout << endl << "已添加物品。";
	system("pause");
}