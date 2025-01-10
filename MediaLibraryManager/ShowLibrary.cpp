#include <iostream>
#include "Globals.h"
using namespace std;

void ShowLibrary() { // ÏÔÊ¾ÎïÆ·¿â
	system("cls");

	for (int i = 0; res[i]; i++)
	{
		res[i]->Show();
	}

	cout << endl;
	system("pause");
}