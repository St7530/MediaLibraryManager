#include <iostream>
#include "Globals.h"
using namespace std;

void ShowLibrary() { // ��ʾ��Ʒ��
	system("title ��Ʒ�� - ý������ϵͳ");
	system("cls");

	for (int i = 0; res[i]; i++)
	{
		res[i]->Show();
	}

	cout << endl;
	system("pause");
}