#include <iostream>
#include "Globals.h"
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

void DeleteItem(int id) {
	for (int i = GetIndexById(id); res[i]; i++)
	{
		if (res[i + 1])
		{
			res[i] = res[i+1];
		}
		else
		{
			res[i] = NULL;
		}
	}
}

void DeleteItem() { // ɾ����Ʒ
	system("title ɾ����Ʒ - ý������ϵͳ");
	system("cls");

	// Gather information
	int id;
	cout << "����Ҫɾ����Ʒ�ı�ţ�";
	cin >> id;
	cout << endl;
	if (!HasId(id))
	{
		cerr << "�ñ�Ų����ڣ�" << endl;
		system("pause");
		return;
	}
	res[GetIndexById(id)]->Show();
	int confirm;
	cout << endl << "���� 1 ȷ��ɾ������������ֵȡ��ɾ����";
	cin >> confirm;
	if (confirm != 1)
	{
		cout << endl << "��ȡ��ɾ����" << endl;
		system("pause");
		return;
	}

	DeleteItem(id);
	isChanged = true;
	cout << endl << "��ɾ������Ʒ��" << endl;
	system("pause");
}