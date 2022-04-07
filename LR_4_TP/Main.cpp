#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <random>
#include"Queue.h"
using namespace std;

//������� ��� 1�� �������
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



template <typename T>
void fillArrayWithRandomNumbers(T* array, int size);


template <>
void fillArrayWithRandomNumbers(float* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 51;
        array[i] += (float)(rand() % 100) / (float)100;
    }
}

template <>
void fillArrayWithRandomNumbers(double* array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 51;
        array[i] += (double)(rand() % 100) / (double)100;
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

    int choice, choice_type, choice_type2, exit = 1, exit1 = 1; //��� ������ � ����

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
            cout << "�������� �������� ��� ������ �������: " << endl;
            cout << "1 - Int\n2 - Float\n3 - Double\n0 - ����� � ������ �������\n-->" << endl;
            cin >> choice_type2;
            system("cls");
            switch (choice_type2)
            {
            case '1': {
                cout << "case1";//�� ������� � ����
                CyclicQueue<int> queue;
                queue.queueMenu();
                break; }
            case '2': {
                CyclicQueue<float> queue;
                queue.queueMenu();
                break; }
            case '3': {
                CyclicQueue<double> queue;
                queue.queueMenu();
                break; }
            case '0': {
                choice_type = 0;
                break; }
            default: {
                choice_type = 0;
                cout << "Wrong key!!!";
                break; }
            }
        }
    }
    return 0;
}

