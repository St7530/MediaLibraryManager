#include <iostream>
#include <fstream>
#include "FindItem.h"
using namespace std;

void AddResource(ofstream& out) { // �����Ʒ - ���� Resource ����
	string tmp;
	cout << "������⣺";	cin >> tmp;	out << tmp << " ";
	cout << "�������ߣ�";	cin >> tmp;	out << tmp << " ";
	cout << "����������";	cin >> tmp;	out << tmp << " ";
}

int AddItem(int id) {
	ofstream outFile("Library.txt", ios::app);
	if (HasItem(id))
	{
		outFile.close();
		cerr << endl << "����ظ���";
		system("pause");
		return 1;
	}
	outFile << endl;
	outFile << id << " ";

	cout << "ѡ����Ʒ��𡪡�[1] ͼ��, [2] ��Ƶ����, [3] ͼ��: ";
	int choice;
	cin >> choice;
	string tmp;
	switch (choice)
	{
	case 1: // Book
		outFile << "Book ";
		AddResource(outFile);
		cout << "��������磺";	cin >> tmp; outFile << tmp << " ";
		cout << "���� ISBN �ţ�";	cin >> tmp; outFile << tmp << " ";
		cout << "����ҳ����";	cin >> tmp; outFile << tmp;
		break;
	case 2: // VCD
		outFile << "VCD ";
		AddResource(outFile);
		cout << "�����Ʒ�ߣ�";	cin >> tmp; outFile << tmp << " ";
		cout << "�����Ʒ��ݣ�";	cin >> tmp; outFile << tmp << " ";
		cout << "������Ƶʱ����";	cin >> tmp; outFile << tmp;
		break;
	case 3: // Picture
		outFile << "Picture ";
		AddResource(outFile);
		cout << "������ڹ�����";	cin >> tmp; outFile << tmp << " ";
		cout << "���볤�������׼ƣ���������";	cin >> tmp; outFile << tmp << " ";
		cout << "����������׼ƣ���������";	cin >> tmp; outFile << tmp;
		break;
	};
	outFile.close();
	return 0;
}

void AddItem() { // �����Ʒ
	system("cls");

	// Input id
	int id;
	cout << "�����ţ�";
	cin >> id;
	AddItem(id);

	cout << endl << "�������Ʒ��";
	system("pause");
}