#include <iostream>
#include <fstream>
#include "Globals.h"
using namespace std;

void SaveLibrary() { // 保存更改
	system("cls");

	ofstream outFile("Library.txt");
	for (int i = 0; res[i]; i++)
	{
		res[i]->Save(outFile);
		if (res[i + 1])
		{
			outFile << endl;
		}
	}
	isChanged = false;
	cout << endl << "已保存物品库。" << endl;

	system("pause");
}