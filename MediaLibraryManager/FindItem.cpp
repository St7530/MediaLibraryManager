#include <iostream>
#include <fstream>
#include "Globals.h"
#include "ShowLibrary.h"
using namespace std;

void FindBy(int way) { // way ָ��Ӧ�����ڿ��е�λ�ã�Ҳ�Ǻ󷽶�ȡ����ʱ��Ҫѭ���Ĵ���
	string findContent;

	switch (way)
	{
	case 1: // �����
		cout << "������Ʒ��ţ�";
		cin >> findContent;
		break;
	case 2: // �����
		cout << "ѡ����Ʒ��𡪡�[1] ͼ��, [2] ��Ƶ����, [3] ͼ����";
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
	case 3: // ������
		cout << "������Ʒ���⣺";
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
	cout << endl << "���ҵ� " << count << " ����Ʒ��" << endl;
	inFile.close();
}

void FindItem() { // ������Ʒ
	system("cls");
	cout << "ѡ����ҷ�ʽ����[1] �����, [2] �����, [3] ������: ";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1: // �����
		FindBy(1);
		break;
	case 2: // �����
		FindBy(2);
		break;
	case 3: // ������
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