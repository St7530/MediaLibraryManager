#include <iostream>
#include "Globals.h"
#include "AddItem.h"
#include "DeleteItem.h"
#include "FindItem.h"
#include "ShowLibrary.h"
using namespace std;

void EditItem() { // �༭��Ʒ
	system("title �༭��Ʒ - ý������ϵͳ");
	system("cls");

	// Gather information
	int id;
	cout << "����Ҫ�༭��Ʒ�ı�ţ�";
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
	cout << endl << "���� 1 ȷ�ϱ༭����������ֵȡ���༭��";
	cin >> confirm;
	cout << endl;
	if (confirm != 1)
	{
		cout << "��ȡ���༭��" << endl;
		system("pause");
		return;
	}

	DeleteItem(id);
	AddItem(id);
	isChanged = true;
	cout << endl << "�༭�ɹ���" << endl;
	system("pause");
}