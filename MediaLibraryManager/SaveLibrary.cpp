#include <iostream>
#include <fstream>
#include "Globals.h"
using namespace std;

void SaveLibrary() { // �������
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
	cout << endl << "�ѱ�����Ʒ�⡣" << endl;

	system("pause");
}