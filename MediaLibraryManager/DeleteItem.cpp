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

void DeleteItem() { // ɾ����Ʒ
	system("cls");

	// Gather information
	int id;
	cout << "����Ҫɾ����Ʒ�ı�ţ�";
	cin >> id;
	cout << endl;
	if (!HasItem(id))
	{
		cerr << "�ñ�Ų����ڣ�" << endl;
		system("pause");
		return;
	}
	ShowItem(GetLineById(id));
	int confirm;
	cout << endl << "���� 1 ȷ��ɾ������������ֵȡ��ɾ����";
	cin >> confirm;
	if (confirm != 1)
	{
		cout << endl << "��ȡ��ɾ����" << endl;
		system("pause");
		return;
	}

	// Delete the row from Library.txt
	cout << ((DeleteItem(id) == 0) ? "��ɾ������Ʒ��" : "Error!") << endl;
	system("pause");
}
