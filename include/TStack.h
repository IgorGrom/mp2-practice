#ifndef TSTACK_H
#define TSTACK_H
#include "TList.h"
#include <locale.h>

template <typename Type>
class TStack{
	private:
		TList<Type> *pFirst; //��������� �� ������ �����
	public:
		TStack(); //�����������
		TStack(const TStack<Type>& St); //����������� �����������
		~TStack(); //����������
		bool Is_Full() const; //�������� �� �������
		bool Is_Empty() const; //�������� �� �������
		void Push(Type key); //���������� �������� � ����
		Type Pop(); //������� �������� �� �����
		Type GetKey(); 

};

template <typename Type> //����������� ��� �����
TStack <Type> ::TStack() {
	pFirst = new TList<Type>;
}

template <typename Type>   // ��������� �� �������
Type TStack<Type>::GetKey() {
	if (Is_Empty()) throw "���� ����";
	return pFirst->GetFirst->key;
}
template <typename Type >   //����������� �����������
TStack <Type> ::TStack(const TStack & St ) {
	pFirst = new TList<Type>(*(St.pFirst));
}

template <typename Type>  //����������
TStack<Type>::~TStack(){
	delete pFirst;
}

template <typename Type>
bool TStack<Type>::Is_Empty() const{   //�������� �������
	return (pFirst->GetFirst() == 0);
}

template <typename Type>
bool TStack<Type>::Is_Full() const {  //�������� �������
	Type key = 1;
	try{
		pFirst->Insert_Begin(key);
		pFirst->Delete(key);
	}
	catch (...){
		return true;
	}
		return false;
}

 template <typename Type>  //���������� �������� � ����
 void TStack<Type>::Push(Type key){   
 setlocale(LC_CTYPE, "russian");
 if (Is_Full()) throw " ���� �����";
 pFirst->Insert_Begin(key);
 }

 //template <typename TYPE>
 //void TStack<TYPE>::Print()
 //{
	// TStack<TYPE>* tmp = new TStack<TYPE>(*this);
	// while (!(tmp->Is_Empty()))
	//	 cout << tmp->Pop() << endl;

 //}

 template <typename Type>
 Type TStack <Type>::Pop(){ //������� �������� �� �����
 setlocale(LC_CTYPE, "russian");
 if (Is_Empty()) throw " ���� ����";
 Type tmp = pFirst->GetFirst()->key;
 pFirst->Delete(tmp);
 return tmp;
 }
#endif