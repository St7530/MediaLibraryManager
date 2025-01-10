#include <iostream>
#include "Globals.h"
#include "ShowLibrary.h"
using namespace std;

void FindBy(int choice) {
	int count = 0;
	switch (choice)
	{
	case 1: // �����
	{
		cout << "������Ʒ��ţ�";
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
	case 2: // �����
	{
		cout << "ѡ����Ʒ��𡪡�[1] ͼ��, [2] ��Ƶ����, [3] ͼ����";
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
	case 3: // ������
	{
		cout << "������Ʒ���⣺";
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
	cout << endl << "���ҵ� " << count << " ����Ʒ��" << endl;
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
	case 1: // ͼ��
		findContent = "Book";
		break;
	case 2: // ��Ƶ����
		findContent = "VCD";
		break;
	case 3: // ͼ��
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

int GetIndexById(int id) { // ����Ʒ�� id ��ȡ���� res[] ������
	for (int i = 0; res[i]; i++)
	{
		if (res[i]->GetId() == id)
		{
			return i;
		}
	}
}