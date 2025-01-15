#include <iostream>
#include "Globals.h"
#include "FindItem.h"
using namespace std;

static void AddResource(string& title, string& author, string& rate) { // �����Ʒ - ���� Resource ����
	cout << "������⣺";	cin >> title;
	cout << "�������ߣ�";	cin >> author;
	cout << "����������";	cin >> rate;
}

void AddItem(int id) {
	// Calculate res[] count
	int count = 0;
	while (res[count])
	{
		count++;
	}

	cout << "ѡ����Ʒ��𡪡�[1] ͼ��, [2] ��Ƶ����, [3] ͼ��: ";
	int choice;
	cin >> choice;
	int additional2, additional3;	string type, title, author, rate, additional1;
	switch (choice)
	{
	case 1: // ͼ��
		type = "Book";
		AddResource(title, author, rate);
		cout << "��������磺";	cin >> additional1;
		cout << "���� ISBN �ţ�";	cin >> additional2;
		cout << "����ҳ����";	cin >> additional3;
		res[count] = new Book(id, title, author, rate, additional1, additional2, additional3);
		break;
	case 2: // ��Ƶ����
		type = "VCD";
		AddResource(title, author, rate);
		cout << "�����Ʒ�ߣ�";	cin >> additional1;
		cout << "�����Ʒ��ݣ�";	cin >> additional2;
		cout << "������Ƶʱ����";	cin >> additional3;
		res[count] = new VCD(id, title, author, rate, additional1, additional2, additional3);
		break;
	case 3: // ͼ��
		type = "Picture";
		AddResource(title, author, rate);
		cout << "������ڹ�����";	cin >> additional1;
		cout << "���볤�������׼ƣ���������";	cin >> additional2;
		cout << "����������׼ƣ���������";	cin >> additional3;
		res[count] = new Picture(id, title, author, rate, additional1, additional2, additional3);
		break;
	}
}

void AddItem() { // �����Ʒ
	system("title �����Ʒ - ý������ϵͳ");
	system("cls");

	// Input id
	int id;
	cout << "�����ţ�";
	cin >> id;
	if (HasId(id))
	{
		cerr << endl << "�ñ���Ѵ��ڣ�" << endl;
		system("pause");
		return;
	}
	else
	{
		AddItem(id);
		isChanged = true;
		cout << endl << "�������Ʒ��" << endl;
		system("pause");
		return;
	}

	cerr << endl << "��Ч�����룡" << endl;
	system("pause");
}