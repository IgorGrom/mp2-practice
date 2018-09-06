#ifndef TSTACK_H
#define TSTACK_H
#include "TList.h"
#include <locale.h>

template <typename Type>
class TStack{
	private:
		TList<Type> *pFirst; //Указатель на первое звено
	public:
		TStack(); //Конструктор
		TStack(const TStack<Type>& St); //Конструктор копирования
		~TStack(); //Деструктор
		bool Is_Full() const; //Проверка на полноту
		bool Is_Empty() const; //Проверка на пустоту
		void Push(Type key); //Добавление элемента в стек
		Type Pop(); //Изъятие элемента из стека
		Type GetKey(); 

};

template <typename Type> //Конструктор для стека
TStack <Type> ::TStack() {
	pFirst = new TList<Type>;
}

template <typename Type>   // Указатель на вершину
Type TStack<Type>::GetKey() {
	if (Is_Empty()) throw "Стек пуст";
	return pFirst->GetFirst->key;
}
template <typename Type >   //Конструктор копирования
TStack <Type> ::TStack(const TStack & St ) {
	pFirst = new TList<Type>(*(St.pFirst));
}

template <typename Type>  //Деструктор
TStack<Type>::~TStack(){
	delete pFirst;
}

template <typename Type>
bool TStack<Type>::Is_Empty() const{   //Контроль пустоты
	return (pFirst->GetFirst() == 0);
}

template <typename Type>
bool TStack<Type>::Is_Full() const {  //Контроль полноты
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

 template <typename Type>  //Добавление элемента в стек
 void TStack<Type>::Push(Type key){   
 setlocale(LC_CTYPE, "russian");
 if (Is_Full()) throw " Стек полон";
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
 Type TStack <Type>::Pop(){ //Изъятие элемента из стека
 setlocale(LC_CTYPE, "russian");
 if (Is_Empty()) throw " Стек пуст";
 Type tmp = pFirst->GetFirst()->key;
 pFirst->Delete(tmp);
 return tmp;
 }
#endif