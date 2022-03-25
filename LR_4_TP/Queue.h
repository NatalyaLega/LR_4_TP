#pragma once
#include "Queue_elem.h"
using namespace std;
template <class T> class Queue
{

	T* q; //указатель на тип T
	int sloc, rloc; //переменные
	int length;
public:
	Queue(int size) //конструктор
	{
		size++;
		q = new T[size]; //создали массив в динамической памяти
		if (!q)
		{
			cout << "Nevozmoghno sozdaty ocheredy. \n";
			exit(1);
		}
		length = size; //длина массива на единицу больше чем длина очереди;сохранить в length
		sloc = rloc = 0;
	}
		Queue() : length(0) {}; //конструктор без параметров (исп. список инициализации); 
	~Queue() { delete[] q; } //деструктор встроенный
	void operator+ (Queue<T>& r) //оператор добавления  
	{
		if (sloc == length || (sloc == length && !rloc))
		{
			cout << "Ocheredy zapolnena.\n";
			return;
		}
		q[sloc] = r;
		sloc++;
		if (sloc == length) sloc = 0; //циклический переход
	}
	void operator- () //оператор извлечения
	{
		if (rloc == length) rloc = 0;//циклический переход
		if (rloc == sloc)
		{
			cout << "Ocheredy pusta.\n";
			return 0;
		}
		rloc++;
		return q[rloc - 1];
	}
	bool operator! () const //проверка на пустоту
	{
		if (length == 0)
			return true;
		else
			return false;
	};
	//геттеры и сеттеры
	int get_size() const //взять размер стека
	{
		return length;
	};

	void print()
	{
		try
		{
			if (!this)
				throw "Стек пуст, выводить нечего.\n";

			Queue_elem<T>* temp = q;
			if (q == 0)
				throw "Удалять нечего, стек и так пуст!";
			while (temp->get_next() != nullptr)
			{
				std::cout << temp->get_data() << " <-- ";
				temp = temp->get_next();
			}
			std::cout << temp->get_data() << std::endl;
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}; //вывод стека на экран
	
};