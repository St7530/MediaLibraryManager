#include <iostream>
#include "Globals.h"
#include "SaveLibrary.h"
using namespace std;

int Exit() { // 0 - Exit, 1 - Do not exit
	system("cls");

	if (isChanged) // �и�����δ����
	{
		cout << "�и�����δ���棡" << endl
			<< "[1] ���沢�˳�" << endl
			<< "[2] �����沢�˳�" << endl
			<< "[3] ȡ���˳�" << endl;
		int choice;
		while(true)
		{
			cin >> choice;
			switch (choice)
			{
			case 1: // ���沢�˳�
				SaveLibrary();
				return 0;
			case 2: // �����沢�˳�
				return 0;
			case 3: // ȡ���˳�
				return 1;
			}
		}
	}
	else
		return 0; // û��δ����ĸ���
}