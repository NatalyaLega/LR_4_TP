#pragma once
#include <iostream>
#include <ctime>

template <typename T>
class Queue_elem //������ ������
{
private:
	T data = 0; //������ �������� �����
	Queue_elem<T>* next = 0; //��������� �� �������� ������� �����
public:
	Queue_elem() : data(0) {};
	Queue_elem(T value) { data = value; };
	~Queue_elem() {};

	T get_data() { return data; };
	void set_data(T value) { data = value; };
	Queue_elem<T>*& get_next() { return next; };
	void set_next(Queue_elem<T>* new_next) { next = new_next; };

};


