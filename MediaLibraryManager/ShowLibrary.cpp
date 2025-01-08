#include <iostream>
#include <fstream>
#include "Globals.h"
using namespace std;

void ShowLibrary() { // ��ʾ��Ʒ��
	system("cls");
	ifstream inFile("Library.txt");

	for (int i = 0; linePos[i] > -1; i++)
	{
		inFile.seekg(linePos[i]);
		int id, additional2, additional3;	string type, title, author, rate, additional1;
		inFile >> id >> type >> title >> author >> rate >> additional1 >> additional2 >> additional3;
		cout << "��ţ�" << id << "\t";
		if (type == "Book")
		{
			cout << "���ͼ��\t";
			cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
			cout << "�����磺" << additional1 << "\tISBN �ţ�" << additional2 << "\tҳ����" << additional3 << endl;
		}
		if (type == "VCD")
		{
			cout << "�����Ƶ����\t";
			cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
			cout << "��Ʒ�ߣ�" << additional1 << "\t��Ʒ��ݣ�" << additional2 << "\t��Ƶʱ����" << additional3 << endl;
		}
		if (type == "Picture")
		{
			cout << "���ͼ��\t";
			cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
			cout << "���ڹ�����" << additional1 << "\t����" << additional2 << "\t��" << additional3 << endl;
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
	cout << "��ţ�" << id << "\t";
	if (type == "Book")
	{
		cout << "���ͼ��\t";
		cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
		cout << "�����磺" << additional1 << "\tISBN �ţ�" << additional2 << "\tҳ����" << additional3 << endl;
	}
	if (type == "VCD")
	{
		cout << "�����Ƶ����\t";
		cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
		cout << "��Ʒ�ߣ�" << additional1 << "\t��Ʒ��ݣ�" << additional2 << "\t��Ƶʱ����" << additional3 << endl;
	}
	if (type == "Picture")
	{
		cout << "���ͼ��\t";
		cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
		cout << "���ڹ�����" << additional1 << "\t����" << additional2 << "\t��" << additional3 << endl;
	}
	inFile.close();
}
