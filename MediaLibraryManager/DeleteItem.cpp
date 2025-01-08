#include <iostream>
#include <fstream>
#include <string>
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

int DeleteItem(int id) {
	int lineNumber = GetLineById(id);
	ifstream inFile("Library.txt");
	ofstream tmpFile("tmpLibrary.tmp");
	string line;
	int currentLine = 0;
	bool isFirstLine = true;
	while (getline(inFile, line)) {
		if (currentLine != lineNumber) {
			if (!isFirstLine) {
				tmpFile << endl;
			}
			tmpFile << line;
			isFirstLine = false;
		}
		++currentLine;
	}
	inFile.close();
	tmpFile.close();
	remove("Library.txt");
	return ((rename("tmpLibrary.tmp", "Library.txt") == 0) ? 0 : 1); // 0 - Success, 1 - Exception
}

void DeleteItem() { // 删除物品
	system("cls");

	// Gather information
	int id;
	cout << "输入要删除物品的编号：";
	cin >> id;
	cout << endl;
	if (!HasItem(id))
	{
		cerr << "该编号不存在！" << endl;
		system("pause");
		return;
	}
	ShowItem(GetLineById(id));
	int confirm;
	cout << endl << "输入 1 确认删除，输入其它值取消删除：";
	cin >> confirm;
	if (confirm != 1)
	{
		cout << endl << "已取消删除。" << endl;
		system("pause");
		return;
	}

	// Delete the row from Library.txt
	cout << ((DeleteItem(id) == 0) ? "已删除该物品。" : "Error!") << endl;
	system("pause");
}
