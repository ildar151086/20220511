/*
Измените стек из первого задания со статического типа на
динамический (при нехватке свободного места нужно изменить
размер внутреннего массива без потери данных).
*/

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Stack
{
	enum { EMPTY = -1 };
	int size;
	//Массив для хранения данных
	//char st[FULL + 1];
	char *st;

	//индекс определяющий вершину стека
	int top;

public:

	//Конструктор
	Stack();

	//Добавление элемента
	void Push(char c);

	//Извлечение элемента
	char Pop();

	//Очистка стека
	void Clear();

	//Проверка существования элементов в стеке
	bool IsEmpty();

	//Количество элементов в стеке
	int GetCount();

	~Stack();
};

Stack::Stack()
{
	//Изначально стек пуст
	st = nullptr;
	size = 0;
}
Stack::~Stack()
{
	if (st != nullptr) {
		delete[] st;
	}
}

void Stack::Clear()
{
	if (st != nullptr) {
		delete[] st;
		size = 0;
	}
}

bool Stack::IsEmpty()
{
	//Пуст?
	if (size == 0) {
		return top == EMPTY;
	}
	else return 1;
}

int Stack::GetCount()
{
	//Количество присутствующих в стеке элементов
	return size + 1;
}

void Stack::Push(char c)
{
	char* temp = new char[size + 1];
	for (int i = 0; i < size; i++) {
		*(temp + i) = *(st + i);
	}
	*(temp + size) = c;
	size++;

	if (st != nullptr) {
		delete[] st;
	}

	st = temp;
}


char Stack::Pop()
{
	if ( IsEmpty() != EMPTY) {
		--size;
		return *(st + size +1);
	}
	else //Если в стеке элементов нет
		return 0;
}


void main()
{
	srand(time(0));
	int const SIZE_COUNT = 20;

	Stack ST;
	char c;
	//пока стек не заполнится
	for (int i = 0; i < SIZE_COUNT; i++) {
		c = '3';// rand() % 4 + 2;
		ST.Push(c);
	}

	ST.Push('7');
	//пока стек не освободится
	while (c = ST.Pop()) {
		cout << c << " ";
	}
	cout << "\n\n";
}