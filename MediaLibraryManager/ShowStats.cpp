#include <iostream>
#include "FindItem.h"
using namespace std;

void ShowStats() { // ͳ����Ϣ
	system("title ͳ����Ϣ - ý������ϵͳ");
	system("cls");

	cout << "����Ʒ����\t" << GetResourceCount() << endl << endl
		<< "ͼ������\t" << GetResourceCount(1) << endl
		<< "��Ƶ��������\t" << GetResourceCount(2) << endl
		<< "ͼ������\t" << GetResourceCount(3) << endl;
	cout << endl;

	system("pause");
}