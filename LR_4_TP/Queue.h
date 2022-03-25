#pragma once
#include "Queue_elem.h"
using namespace std;
template <class T> class Queue
{

	T* q; //��������� �� ��� T
	int sloc, rloc; //����������
	int length;
public:
	Queue(int size) //�����������
	{
		size++;
		q = new T[size]; //������� ������ � ������������ ������
		if (!q)
		{
			cout << "Nevozmoghno sozdaty ocheredy. \n";
			exit(1);
		}
		length = size; //����� ������� �� ������� ������ ��� ����� �������;��������� � length
		sloc = rloc = 0;
	}
		Queue() : length(0) {}; //����������� ��� ���������� (���. ������ �������������); 
	~Queue() { delete[] q; } //���������� ����������
	void operator+ (Queue<T>& r) //�������� ����������  
	{
		if (sloc == length || (sloc == length && !rloc))
		{
			cout << "Ocheredy zapolnena.\n";
			return;
		}
		q[sloc] = r;
		sloc++;
		if (sloc == length) sloc = 0; //����������� �������
	}
	void operator- () //�������� ����������
	{
		if (rloc == length) rloc = 0;//����������� �������
		if (rloc == sloc)
		{
			cout << "Ocheredy pusta.\n";
			return 0;
		}
		rloc++;
		return q[rloc - 1];
	}
	bool operator! () const //�������� �� �������
	{
		if (length == 0)
			return true;
		else
			return false;
	};
	//������� � �������
	int get_size() const //����� ������ �����
	{
		return length;
	};

	void print()
	{
		try
		{
			if (!this)
				throw "���� ����, �������� ������.\n";

			Queue_elem<T>* temp = q;
			if (q == 0)
				throw "������� ������, ���� � ��� ����!";
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
	}; //����� ����� �� �����
	
};