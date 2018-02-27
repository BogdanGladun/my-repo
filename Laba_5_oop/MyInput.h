#pragma once

#include<fstream>
#include<iostream>
#include<Windows.h>

using namespace std;






void InputSize(int &size) {

	ifstream my_cin("CON");


	do {

		while (!(my_cin >> size))
		{
			cout << "\nОшибка ввода! Повторите еще раз\n==>";
			my_cin.clear();

			while (my_cin.get() != '\n')
				continue;
		}

		if (size < 1 || size>1000) {
			cout << "Ошибка ввода размера массива! Допустимое значение 1<=размер<=1000\n==>";
			continue;
		}

		else break;

	} while (true);


}



int InputType()
{

	ifstream my_cin("CON");
	int type_num;
	while (!(my_cin >> type_num))
	{
		cout << "\nОшибка ввода! Повторите еще раз\n==>";
		my_cin.clear();

		while (my_cin.get() != '\n')
			continue;
	}
	return type_num;
}


int Set_size(int size_1, int size_2) {


	return (size_1 + size_2) / 2;;
}


template<typename T>
void Check_input(T &num) {

	ifstream my_inp("CON");
	while (!(my_inp >> num)) {
		cout << "\nОшибка ввода! Повторите еще раз\n==>";
		my_inp.clear();
		while (my_inp.get() != '\n') continue;
	}

}

