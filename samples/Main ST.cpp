#include <iostream>
#include <locale.h>
#include <conio.h>
#include "TStack.h"

using namespace std;


void main()
{
	setlocale(LC_CTYPE, "Russian");
	TStack<int>* st = new TStack<int>();
	cout << " ВВедите количество элементов в стеке" << endl;
	int n;
	cin >> n;
	int k;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент ";
		cin >> k;
		st->Push(k);
	}
	cout << endl << "Стек из " << n << " элементов " << endl;
	st->Print();
	cout << endl << "Вывод содержимого стека " << endl;
	st->Pop();
	st->Print();
	return;
}