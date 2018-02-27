#include "MyComplex.h"







ostream &operator<<(ostream &out, MyComplex &object)
{
	out << object.real << "+i(" << object.image << ")";

	return out;
}

istream &operator >> (istream &in, MyComplex &object)
{


	cout << "\n\tВведите действительную часть==> ";
	while (!(in >> object.real)) {
		cout << "\nОшибка ввода! Повторите еще раз\n==>";
		in.clear();
		while (in.get() != '\n') continue;
	}


	cout << "\tВведите мнимую часть==> ";
	while (!(in >> object.image)) {
		cout << "\nОшибка ввода! Повторите еще раз\n==>";
		in.clear();
		while (in.get() != '\n') continue;
	}

	return in;
}



bool MyComplex:: operator > (MyComplex object)
{
	if (this->real > object.real)
		return true;

	else if (this->image > object.image)
		return true;
	else return false;
}

bool MyComplex:: operator < (MyComplex object)
{
	if (this->real < object.real)
		return true;

	else if (this->image < object.image)
		return true;
	else return false;
}


bool MyComplex:: operator > (int num)
{
	if (this->real > num)
		return true;

	else
		return false;
}


bool MyComplex:: operator < (int num)
{
	if (this->real < num)
		return true;

	else
		return false;
}



// Перегрузка оператора НЕэквивалентности комплексных чисел
bool MyComplex::operator !=(MyComplex& object)
{

	if (this->real != object.real || this->image != object.image)
		return true;
	else
		return false;
}


// Перегрузка оператора умножения комплексных чисел
MyComplex operator*(MyComplex &object_1, MyComplex &object_2)
{
	MyComplex new_object;
	long double i,i1,i2,j1,j2,j;
	i1 = object_1.real * object_2.real;
	i2 = object_1.image * object_2.image;
	if (i1 > DBL_MAX || i1<-DBL_MAX || i2>DBL_MAX || i2 < -DBL_MAX)
	{
		cout << "\nПереполнение при вычислении умножения действительной части!\n";
		i = 999999.0;
	}
	else i = i1 - i2;

	j1 = object_1.real * object_2.image;
	j2 = object_2.real * object_1.image;
	if (j1 > DBL_MAX || j1<-DBL_MAX || j2>DBL_MAX || j2 < -DBL_MAX)
	{
		cout << "\nПереполнение при вычислении умножения мнимой части !\n";
		j = 999999.0;
	}
	else j = j1 + j2;
	
	new_object.real = i;
	new_object.image = j;
	return new_object;
}


//Перегрузка оператора деления комплексных чисел
MyComplex operator/(MyComplex &object_1, MyComplex &object_2)

{



	MyComplex new_object;

	long double i, i1, i2, j, j1, j2, k/* ,k1, k2*/;
	k = (long double)object_2.real * object_2.real + (long double)object_2.image * object_2.image;

	
	if (k > DBL_MAX || k < -DBL_MAX)
	{
		cout << "\nПереполнение при вычислении деления (переполнение знаменателя)!\n";
		k = -1;
	}
	if (k == 0)
	{
		cout << "\nОшибка деления на ноль!\n";
		k = -1;
	}
	i1 = object_1.real * object_2.real;
	i2 = object_1.image * object_2.image;
	if (i1 > DBL_MAX || i1<-DBL_MAX || i2>DBL_MAX || i2 < -DBL_MAX)
	{
		cout << "\nПереполнение при вычислении деления действительной части !\n";
		i = 999999.0;
	}
	else i = (i1 + i2) / k;

	j1 = object_2.real * object_1.image;
	j2 = object_1.real * object_2.image;

	if (j1 > DBL_MAX || j1<-DBL_MAX || j2>DBL_MAX || j2 < -DBL_MAX)
	{
		cout << "\nПереполнение при вычислении деления мнимой части !\n";
		j = 999999.0;
	}
	else j = (j1 - j2) / k;
	new_object.real = (double)i;
	new_object.image = (double)j;
	return new_object;
}


MyComplex& MyComplex::operator =(MyComplex object)
{
	this->real = object.real;
	this->image = object.image;
	return *this;
}



MyComplex& MyComplex::operator =(int num)
{
	this->real = num;
	this->image = 0;
	return *this;
}



MyComplex operator+(MyComplex& object_1, MyComplex& object_2)
{
	MyComplex new_object;
	long double i = (long double)object_1.real + object_2.real;
	long double j = (long double)object_1.image + object_2.image;

	if ((i > DBL_MAX) || (i < -DBL_MAX))
	{
		cout << "\nПереполнение при вычислении суммы!\n";
		new_object.real = 999999.0;
	}
	else new_object.real = object_1.real + object_2.real;

	if ((j > DBL_MAX) || (j < -DBL_MAX)) {

		cout << "\nПереполнение при вычислении суммы!\n";
		new_object.image = 999999.0;
	}
	else new_object.image = object_1.image + object_2.image;

	return new_object;

}



MyComplex operator*(MyComplex &object, int num)
{
	MyComplex new_object;
	long double check = (long double)object.real * num;
	if (check > DBL_MAX || check < -DBL_MAX) {
		cout << "\nПереполнение при вычислении суммы!\n";
		new_object.real = 999999.0;
	}
	else new_object.real = object.real * num;
	new_object.image = object.image;
	return new_object;
}





MyComplex operator+(MyComplex & object, int num)
{
	MyComplex new_object;
	long double check = (long double)object.real + num;
	if (check > DBL_MAX || check < -DBL_MAX) {
		cout << "\nПереполнение при вычислении суммы!\n";
		new_object.real = 999999.0;

	}

	else  new_object.real = object.real + num;
	new_object.image = object.image;

	return new_object;
}



MyComplex operator-(MyComplex &object_1, MyComplex& object_2)
{
	MyComplex new_object;
	long double a, b;
	a = (long double)object_1.real - object_2.real;
	b = (long double)object_1.image - object_2.image;



	if (a > DBL_MAX || a < -DBL_MAX)
	{
		cout << "\nПереполнение при вычислении вычитания!\n";
		new_object.real = 999999.0;
	}
	else new_object.real = object_1.real - object_2.real;



	if ((b <-DBL_MAX || b > DBL_MAX)) {
		cout << "\nПереполнение при вычислении вычитания!\n";
		new_object.image = 999999.0;
	}
	else new_object.image = object_1.image - object_2.image;
	return new_object;
}



MyComplex operator-(MyComplex& object, int num)
{
	MyComplex new_object;
	long double check = (long double)object.real - num;
	if ((check < -DBL_MAX) || (check > DBL_MAX)) {
		cout << "\nПереполнение при вычислении вычитания!\n";
		new_object.real = 999999.0;

	}
	else new_object.real = object.real - num;
	new_object.image = object.image;


	return new_object;
}

MyComplex::operator double()
{
	return (double)this->real;
}