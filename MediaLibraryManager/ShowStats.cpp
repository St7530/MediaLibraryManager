#include <iostream>
#include "FindItem.h"
using namespace std;

void ShowStats() {
	system("cls");

	cout << "����Ʒ����" << GetResourceCount(0) << endl << endl
		<< "ͼ������" << GetResourceCount(1) << endl
		<< "��Ƶ��������" << GetResourceCount(2) << endl
		<< "ͼ������" << GetResourceCount(3) << endl;
	cout << endl;

	system("pause");
}