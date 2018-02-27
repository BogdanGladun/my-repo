#pragma once

#include <iostream>
#include <math.h> 
#include <conio.h>
#include"MyComplex.h"
#include "MyInput.h"


using namespace std;

template<typename T>
class MyClass
{

private:

	int size_of_array;	//������ �������

	T *mas;				//��������� �� ������

	double legend;		//�������� �������

						// ��������� �������
	void Set_legend() {


		double legend;
		double sum = 0;
		int count = 0;
		double j;

		for (int i = 0; i < size_of_array; i++)
		{
			if (mas[i] < 0) {
				j = mas[i] * -1;
				count++;
			}
			else j = mas[i];

			sum += (int)i*j - count*i;

		}
		legend = sum / size_of_array;

		this->legend = legend;
	}




	//��������� ���������� ��������
	void Rand(int& object)
	{

		object = -1000 + rand() % 2000;
	}
	void Rand(double &object) {

		object = (double)rand() / RAND_MAX*(2000 + 1000) - 1000;
	}
	void Rand(MyComplex &object)
	{
		MyComplex name(-50 + rand() % 100, -50 + rand() % 100);

		object = name;
	}
	///////////////////////////////

public:




	//�������� ��������� ������� �������
	int Get_size()
	{
		return this->size_of_array;
	}




	//�������� ��������� �������� �������
	double Get_legend()

	{
		return this->legend;
	}




	//����������� �� ���������
	MyClass()
	{
		size_of_array = 0;
		legend = 0;
		*mas = nullptr;
	}




	//�����������
	MyClass(int _size) :legend(0)
	{
		size_of_array = _size;
		if (_size == 1) {
			mas = new T;
		}
		else
		{
			mas = new T[_size];
		}
	}



	//�����������
	MyClass(const MyClass & object)
	{
		this->size_of_array = object.size_of_array;
		this->mas = new T[object.size_of_array];
		for (int i = 0; i < size_of_array; i++)
		{
			mas[i] = object.mas[i];
		}

	}




	//�����������
	MyClass(const MyClass &object_1, const MyClass &object_2)
	{

		if (object_1.size_of_array > object_2.size_of_array)
			this->size_of_array = object_1.size_of_array;
		else
			this->size_of_array = object_2.size_of_array;


		if (this->size_of_array == 1)
		{
			mas = new T;

		}
		else
		{
			mas = new T[this->size_of_array];
		}

	}



	//����������
	~MyClass()
	{
		if (size_of_array == 1) {
			delete mas;
		}
		else delete[]mas;
	}



	//���������� ��������� ����� ��������� �������
	friend istream & operator >> (istream &stream, MyClass& object)
	{

		if (object.size_of_array < 10) {
			for (int i = 0; i < object.size_of_array; i++)
			{
				cout << "������� ������ #" << i + 1 << " ==> ";
				Check_input(object.mas[i]);


			}

		}

		else {

			cout << "����������� �������������� ���������� �������==>\n";
			for (int i = 0; i < object.size_of_array; i++)
			{

				object.Rand(object.mas[i]);
			}

		}

		object.Set_legend();
		return stream;
	}




	//���������� ��������� ������ ��������� �������
	friend ostream & operator<<(ostream & stream, MyClass & object)
	{
		cout << "\n";

		for (int i = 0; i < object.size_of_array; i++)
		{

			stream << object.mas[i] << "\t";

		}
		cout << "\n";

		return stream;
	}


	bool operator == (MyClass & object)
	{
		bool res = true;
		if (this->size_of_array == object.size_of_array)
		{
			for (int i = 0; i < object.size_of_array; i++) {
				if (mas[i] != object.mas[i]) {
					res = false;
				}
			}
		}
		else { res = false; }
		return res;
	}


	//���������� ��������� �����������
	bool operator>(MyClass &object)
	{
		if (size_of_array == 1 && object.size_of_array == 1) {
			return *mas > *object.mas;
		}

		else {
			if (this->size_of_array == object.size_of_array)
			{
				return(Get_legend() > object.Get_legend());
			}
			else
			{
				if (this->size_of_array > object.size_of_array) {
					return true;
				}
				else
				{
					return false;
				}
			}

		}

	}


	bool operator<(MyClass object)
		//���������� ��������� �����������
	{
		if (size_of_array == 1 && object.size_of_array == 1) {
			return *mas < *object.mas;
		}

		else {
			if (this->size_of_array == object.size_of_array)
			{
				return(Get_legend() < object.Get_legend());
			}
			else
			{
				if (this->size_of_array < object.size_of_array) {
					return true;
				}
				else
				{
					return false;
				}
			}

		}

	}

	//���������� ��������� ������������
	MyClass operator=(MyClass &object)
	{

		for (int i = 0; i < this->size_of_array; i++)
		{
			this->mas[i] = object.mas[i];
		}
		return *this;
	}


	//���������� ��������� ������������
	MyClass operator=(int num)
	{
		for (int i = 0; i < this->size_of_array; i++)
		{
			this->mas[i] = num;
		}
		return *this;

	}



	//���������� ��������� �����
	friend MyClass operator+(MyClass &object, int num)
	{
		MyClass<T> new_mas(object);
		long double check;
		for (int i = 0; i < object.size_of_array; i++)
		{
			if (typeid(object.mas[i]) == typeid(int))
			{
				check = (long double)object.mas[i] + num;
				if (check > INT_MAX || check < -INT_MAX)
				{
					cout << "\n������������ ��� ���������� �����!\n";
					new_mas.mas[i] = 999999;
				}
				else new_mas.mas[i] = object.mas[i] + num;
			}
			else if (typeid(object.mas[i]) == typeid(double))
			{

				check = 1.0*object.mas[i] + num;
				if (check > DBL_MAX || check < -DBL_MAX)
				{
					cout << "\n������������ ��� ���������� �����!\n";
					new_mas.mas[i] = 999999.0;

				}
				else new_mas.mas[i] = object.mas[i] + num;
			}
			else new_mas.mas[i] = object.mas[i] + num;


		}
		return new_mas;
	}


	//���������� ��������� ���������
	friend MyClass operator-(MyClass &object, int num)
	{
		MyClass<T> new_mas(object);
		long double check;
		for (int i = 0; i < object.size_of_array; i++)
		{
			if (typeid(object.mas[i]) == typeid(int))
			{
				check = (long double)object.mas[i] - num;
				if (check > INT_MAX || check < -INT_MAX)
				{
					cout << "\n������������ ��� ���������� ���������!\n";
					new_mas.mas[i] = 999999;
				}
				else new_mas.mas[i]= object.mas[i] - num;

			}
			else if (typeid(object.mas[i]) == typeid(double))
			{

				check = (long double)object.mas[i] - num;
				if (check > DBL_MAX || check < -DBL_MAX)
				{
					cout << "\n������������ ��� ���������� ���������!\n";
					new_mas.mas[i] = 999999.0;

				}
				else new_mas.mas[i] = object.mas[i] - num;
			}
			else new_mas.mas[i] = object.mas[i] - num;


		}
		return new_mas;
	}


	//���������� ��������� ���������
	friend MyClass operator*(const MyClass&object_1, const MyClass& object_2)
	{
		MyClass<T> new_mas(object_1, object_2);
		long double check;

		for (int i = 0, j = 0, k = 0; k < new_mas.size_of_array; i++, j++, k++) {
			if (i == object_1.size_of_array)
				i = 0;
			if (j == object_2.size_of_array)
				j = 0;



			if (typeid(T) == typeid(int))
			{
				check = (long double)object_1.mas[i] * object_2.mas[j];
				if (check > INT_MAX || check < INT_MIN)
				{
					cout << "\n������������ ��� ���������� ���������!\n";
					new_mas.mas[i] = 999999;
				}
				else new_mas.mas[i]= object_1.mas[i] * object_2.mas[j];

			}
			else if (typeid(T) == typeid(double))
			{


				check = (long double)object_1.mas[i] * object_2.mas[j];
				if (check > DBL_MAX || check < -DBL_MAX)
				{
					cout << "\n������������ ��� ���������� ���������!\n";
					new_mas.mas[i] = 999999.0;
				}
				else new_mas.mas[i] = object_1.mas[i] * object_2.mas[j];

			}

			else new_mas.mas[k] = object_1.mas[i] * object_2.mas[j];


		}
		return new_mas;
	}


	//���������� ��������� �������
	friend  MyClass operator /(const MyClass& object_1, const MyClass& object_2)
	{

		MyClass<T> new_mas(object_1, object_2);
		long double check;

		for (int i = 0, j = 0, k = 0; i < new_mas.size_of_array; i++, j++, k++)
		{

			if (j == object_1.size_of_array)
				j = 0;

			if (k == object_2.size_of_array)
				k = 0;



			if ((typeid(mas[k]) != typeid(MyComplex)) && (object_2.mas[k] == 0))
			{
				cout << "\n������ ������� �� ����!\n";
				k = -1;
			}



			if (typeid(mas[i]) == typeid(int))
			{
				check = (long double)object_1.mas[j] / object_2.mas[k];
				
				if (check > INT_MAX || check < INT_MIN)
				{
					cout << "\n������������ ��� ���������� �������!\n";
					new_mas.mas[i] = 999999;
				}
				else  new_mas.mas[i] = object_1.mas[i] /object_2.mas[j];
			}


			else if (typeid(mas[i]) == typeid(double))
			{
				check = (long double)object_1.mas[j] / object_2.mas[k];
				if (check > DBL_MAX || check < -DBL_MAX) {
					cout << "\n������������ ��� ���������� �������!\n";
					new_mas.mas[j] = 999999.0;				
				}
				else new_mas.mas[i] = object_1.mas[i]/ object_2.mas[j];
			}

			else  new_mas.mas[i] =object_1.mas[j] / object_2.mas[k];
		}


		return new_mas;
	}


};