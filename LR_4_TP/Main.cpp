#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include"Queue.h"
using namespace std;


template<class T>
void sort_direct_merge(T a[], int fsize)  // ��������� ������� ���������� ��������
{
    if (fsize < 2)return;
    sort_direct_merge(a, fsize / 2);
    sort_direct_merge(&a[fsize / 2], fsize - (fsize / 2));
    T* buf = new T[fsize];
    int idbuf = 0, idl = 0, idr = fsize / 2;
    while ((idl < fsize / 2) && (idr < fsize))
        if (a[idl] > a[idr])
            buf[idbuf++] = a[idl++];
        else
            buf[idbuf++] = a[idr++];
    while (idl < fsize / 2) buf[idbuf++] = a[idl++];
    while (idr < fsize) buf[idbuf++] = a[idr++];
    for (idl = 0; idl < fsize; idl++)a[idl] = buf[idl];
   delete[]buf;
}


template<class T>
void mergeSort(T* array, int fsize) //��������� ������� �������� �������
{
    int i = 0;
    cout << "������ �������: ";
    cout << fsize << endl; //������� ������ �������
    
    cout << "�������� ������:" << endl;
    for (i = 0; i < fsize - 1; i++) //������� ������
        cout << array[i] << " -> ";
    cout << array[i] << endl;
    cout << endl;

    cout << "��������������� ������:" << endl;
    if (fsize < 2)return;
    sort_direct_merge(array, fsize / 2);
    sort_direct_merge(&array[fsize / 2], fsize - (fsize / 2));
    T* num = new T[fsize];
    int idbuf = 0, idl = 0, idr = fsize / 2;
    while ((idl < fsize / 2) && (idr < fsize))
        if (array[idl] > array[idr])
            num[idbuf++] = array[idl++];
        else
            num[idbuf++] = array[idr++];
    while (idl < fsize / 2) num[idbuf++] = array[idl++];
    while (idr < fsize) num[idbuf++] = array[idr++];
    for (idl = 0; idl < fsize; idl++)array[idl] = num[idl];
    delete[]num;


    for (i = 0; i < fsize - 1; i++) //������� ������
        cout << array[i] << " -> ";
    cout << array[i] << endl;
    cout << endl;
}

//�������, ��� ������ � ��������(� ������, ����� �������� � � �������� �����)->��� ��������� �������� ��������
template <class T, typename TT>
void work_with_queue(T* stptr, TT x)
{
	int choise, size, exit = 1;
	//TT element;
	
	try
	{
		cout << "������� ������ �������(�� 0 �� 50):\n--> ";
		cin >> size;
		if (size <= 0)
			throw "������ ������� �� ����� ���� ������� ��� �������������!";
		if (size > 50)
			throw "������ ������� ������ 50 - ��� �����������!";
	}
	catch (const char* ex) { cout << ex << endl; }

	T q;


	system("cls");

	while (exit == 1)
	{
		cout << "�������� ��������� ��������. ��������, ��� ��� ����������: " << endl;
		cout << "1 - �������� ������� � �������" << endl;
		cout << "2 - ������� ������� �� �������" << endl;
		cout << "3 - ��������� ������� �� �������" << endl;
		cout << "4 - ���������� �������" << endl;
		cout << "0 - ����� � ������ �������" << endl;
		cin >> choise;

		system("cls");

		switch (choise)
		{
		case 1:
			int elem;
			cout << "������� ������� �����, ������� ������ ��������: ";
			cin >> elem;
			q = q + elem;
			//q.print();

			system("pause");
			cout << "\n";
			break;
		case 2:
			try
			{
			

			}
			catch (const char* ex) { cout << ex << endl; }
			system("pause");
			break;
		case 3:
			


		case 4:
			
			//q.print();
			//���-�� ������� ����� �����
			cout << "\n";
			system("pause");
			break;
		case 0:
			delete[] stptr;
			exit = 0;
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//���������� ��� 1�� �������
	int size_array; //������ ��������� �������
	int* mass1 = 0;
	float* mass2 = 0;
	double* mass3 = 0;

	//���������� ��� 2�� �������
	Queue<int>* queue1 = nullptr;
	int x1 = 0;
	Queue<float>* queue2 = nullptr;
	float x2 = 0;
	Queue<double>* queue3 = nullptr;
	double x3 = 0;

	int choice, choice_type, exit = 1, exit1 = 1; //��� ������ � ����

	while (exit == 1)
	{
		cout << "�������� ����� �������: " << endl;
		cout << "1 - ������� 1 - ���������� �������\n2 - ������� 2 - ������������������� ����� ����������� �������\n0 - �����\n-->" << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:  ////////// �������_1 ///////////
			while (exit1 == 1)
			{
				cout << "�������� �������� ��� ������ �������: " << endl;
				cout << "1 - int\n2 - float\n3 - double\n0 - ����� --> " << endl;
				cin >> choice_type;

				switch (choice_type)
				{
				case 1:
					cout << "������� ������ �������: " << endl;
					cin >> size_array;
					mass1 = new int[size_array]; //�������� ������ ��� ������

					for (int i = 0; i < size_array; i++) //��������� ������
						mass1[i] = rand() % 20;

					mergeSort(mass1, size_array); //�������� ������� ����������
					delete[] mass1;
					system("pause");
					system("cls");
					break;
				case 2:
					cout << "������� ������ �������: " << endl;
					cin >> size_array;
					mass2 = new float[size_array]; //�������� ������ ��� ������

					for (int i = 0; i < size_array; i++) //��������� ������
						mass2[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2);

					mergeSort(mass2, size_array); //�������� ������� ����������
					delete[] mass2;
					system("pause");
					system("cls");
					break;
				case 3:
					cout << "������� ������ �������: " << endl;
					cin >> size_array;
					mass3 = new double[size_array]; //�������� ������ ��� ������

					for (int i = 0; i < size_array; i++) //��������� ������
						mass3[i] = (-60.0 + rand() % 119) / (2.0 + rand() % 2);

					mergeSort(mass3, size_array); //�������� ������� ����������
					delete[] mass3;
					system("pause");
					system("cls");
					break;
				
				case 0:
					exit1 = 0;
					break;
				default:
					break;
				}
			}
			break;
		case 2: ///////// �������_2 //////////
			system("cls");
			cout << "�������� �������� ��� ������ �������: " << endl;
			cout << "1 - int\n2 - float\n3 - double\n0 - ����� � ������ �������\n-->" << endl;
			cin >> choice_type;
			switch (choice_type)
			{
			case 1:
				work_with_queue(queue1, x1);
				system("pause");
				system("cls");
				break;
			case 2:
				work_with_queue(queue2, x2);
				system("pause");
				system("cls");
				break;
			case 3:
				work_with_queue(queue3, x3);
				system("pause");
				system("cls");
				break;
			case 0:
				break;
			default:
				break;
			}
			break;
		case 0:
			exit = 0;
			break;
		default:
			exit = 0;
			break;
		}
	}
	return 0;
}
