#include <iostream>
#include <locale.h>
#include <conio.h>
#include "TStack.h"

using namespace std;


void main()
{
	setlocale(LC_CTYPE, "Russian");
	TStack<int>* st = new TStack<int>();
	cout << " ������� ���������� ��������� � �����" << endl;
	int n;
	cin >> n;
	int k;
	for (int i = 0; i < n; i++)
	{
		cout << "������� ������� ";
		cin >> k;
		st->Push(k);
	}
	cout << endl << "���� �� " << n << " ��������� " << endl;
	st->Print();
	cout << endl << "����� ����������� ����� " << endl;
	st->Pop();
	st->Print();
	return;
}