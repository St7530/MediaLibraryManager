#include <iostream>
#include <fstream>
#include "Globals.h"
using namespace std;

void ShowLibrary() { // 显示物品库
	system("cls");
	ifstream inFile("Library.txt");

	for (int i = 0; linePos[i] > -1; i++)
	{
		inFile.seekg(linePos[i]);
		int id, additional2, additional3;	string type, title, author, rate, additional1;
		inFile >> id >> type >> title >> author >> rate >> additional1 >> additional2 >> additional3;
		cout << "编号：" << id << "\t";
		if (type == "Book")
		{
			cout << "类别：图书\t";
			cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
			cout << "出版社：" << additional1 << "\tISBN 号：" << additional2 << "\t页数：" << additional3 << endl;
		}
		if (type == "VCD")
		{
			cout << "类别：视频光盘\t";
			cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
			cout << "出品者：" << additional1 << "\t出品年份：" << additional2 << "\t视频时长：" << additional3 << endl;
		}
		if (type == "Picture")
		{
			cout << "类别：图画\t";
			cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
			cout << "出口国籍：" << additional1 << "\t长：" << additional2 << "\t宽：" << additional3 << endl;
		}
	}

	inFile.close();
	cout << endl;
	system("pause");
}

void ShowItem(int i) {
	ifstream inFile("Library.txt");
	inFile.seekg(linePos[i]);
	int id, additional2, additional3;	string type, title, author, rate, additional1;
	inFile >> id >> type >> title >> author >> rate >> additional1 >> additional2 >> additional3;
	cout << "编号：" << id << "\t";
	if (type == "Book")
	{
		cout << "类别：图书\t";
		cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
		cout << "出版社：" << additional1 << "\tISBN 号：" << additional2 << "\t页数：" << additional3 << endl;
	}
	if (type == "VCD")
	{
		cout << "类别：视频光盘\t";
		cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
		cout << "出品者：" << additional1 << "\t出品年份：" << additional2 << "\t视频时长：" << additional3 << endl;
	}
	if (type == "Picture")
	{
		cout << "类别：图画\t";
		cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
		cout << "出口国籍：" << additional1 << "\t长：" << additional2 << "\t宽：" << additional3 << endl;
	}
	inFile.close();
}
