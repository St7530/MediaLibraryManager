#include <iostream>
#include "AddItem.h"
#include "DeleteItem.h"
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

void EditItem() { // �༭��Ʒ
	system("cls");

	// Gather information
	int id;
	cout << "����Ҫ�༭��Ʒ�ı�ţ�";
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
	cout << endl << "���� 1 ȷ�ϱ༭����������ֵȡ���༭��";
	cin >> confirm;
	if (confirm != 1)
	{
		cout << endl << "��ȡ���༭��" << endl;
		system("pause");
		return;
	}

	// Delete item
	if (DeleteItem(id) != 0)
	{
		cerr << "Error!" << endl;
		system("pause");
		return;
	}

	// Add item
	if (AddItem(id) != 0)
	{
		cerr << "Error!" << endl;
		system("pause");
		return;
	}

	cout << endl << "�༭�ɹ���";
	system("pause");
}