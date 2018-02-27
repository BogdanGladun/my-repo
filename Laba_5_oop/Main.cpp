#include<iostream>
#include<time.h>
#include<iomanip>
#include"MyClass.h"
#include"MyInput.h"
#include"MyComplex.h"




using namespace std;

char* message = "\n������� ����� ������� ��� �����������,��� ESC ��� ������";
char* res = "";



template <typename T>
void Input_arrays(MyClass<T> object_1, MyClass<T>object_2) {
	cin >> object_1;

	cout << object_1;

	cin >> object_2;
	cout << object_2;
	//cout << object_1 * object_2;
	Calculate(object_1, object_2);
}

template <typename T>
void Calculate(MyClass <T>mas_a, MyClass <T>mas_b) {

	MyClass <T>mas_x(Set_size(mas_a.Get_size(), mas_b.Get_size()));
	MyClass<T> mas_prom_res(Set_size(mas_a.Get_size(), mas_b.Get_size()));

	if (mas_a == mas_b)
	{
		res = "\t\t\t\t-51";






#ifdef _DEBUG
		cout << "\t\t\t\t������ � == ������ B\n";
		cout << res << endl;
#endif // _DEBUG
		mas_x = -51;



	}
	else {
		if (mas_a < mas_b)
		{
			res = "\t\t\t\t(A/B)+10";

#ifdef _DEBUG
			cout << "\t\t\t\t������ � < ������� B\n";
			cout << res << endl;
#endif // _DEBUG

			
			res = "\t\t\t\t(A/B)+10";
#ifdef _DEBUG
			cout << "\t\t\t\t������������� ����������\n";	
			mas_prom_res = mas_a / mas_b;
			cout << "A/B==>" << mas_prom_res <<"\n\n";
			


#endif // _DEBUG
			mas_x = mas_prom_res + 10;
		}
		else
		{
			res = "\t\t\t\t(A*B-4)/A";




#ifdef _DEBUG
			cout << "\t\t\t������ � > ������� B\n";
			cout << res << endl;
#endif // _DEBUG


			
				cout<<"\n\n";



#ifdef _DEBUG
			cout << "\t\t\t\t������������� ����������\n";
			mas_prom_res = mas_a * mas_b;
			cout << "A*B==>" <<mas_prom_res;
			mas_prom_res = mas_prom_res - 4;
			cout << "A*B-4==>" << mas_prom_res;
			cout << "\n\n";
#endif // _DEBUG

			mas_x = mas_prom_res / mas_a;
		}


	}

	cout << "���������==> " << res;
	cout << "\n������ ������� �==>  " << mas_x.Get_size()<<"\n\n";
	cout << mas_x;


}





int Result() {
	int size_a;
	int size_b;
	int type_num;




	try
	{
		
		


		cout << "������� ������ ������� �==> ";
		InputSize(size_a);
		cout << "�� ����� ������ � �������� ==>" << size_a << endl;
		cout << "������� ������ ������� �==> ";
		InputSize(size_b);
		cout << "�� ����� ������ � �������� ==> " << size_b << endl;


		cout << "�������� ��� ��������� ��������:\n\t 1 - int\n\t 2 - double\n\t 3 - complex\n==> ";

		do {
			switch (type_num = InputType()) {

			case 1:
			{
				cout << "��� ���������  �������� - int\n";

				MyClass<int> mas_a(size_a);
				MyClass<int> mas_b(size_b);
				Input_arrays(mas_a, mas_b);
				break;


			}
			case 2:
			{
				cout << "��� ���������  �������� - double\n";
				MyClass<double> mas_a(size_a);
				MyClass<double> mas_b(size_b);
				Input_arrays(mas_a, mas_b);
				break;

			}
			case 3: {
				cout << "��� ���������  �������� - complex\n";
				MyClass<MyComplex> mas_a(size_a);
				MyClass<MyComplex> mas_b(size_b);
				Input_arrays(mas_a, mas_b);
				break;

			}

			default: cout << "������ ������ ����! �������� ��� ��� ��� :";


			}
		} while (type_num < 1 || type_num > 3);

	}
	catch (char* ex) {
		
		cout << ex << endl;
	
		
	}

	cout << message;

	return (_getch());
}



int main()

{
	
	setlocale(LC_ALL, "");
	srand((unsigned)time(NULL));
	int test_num = 0;
	const int ESC = 27;
	int exit_;


	do {

		if (test_num != 0) {
			cout << "\n����� ��������� ������� - Enter ";
			if (_getch() == 13)
				system("cls");
		}


#ifdef _DEBUG
		cout << "\n\t\t\t\t��������� �������� � ������ DEBUG\n";
#endif // _DEBUG
		
		cout << "\n\t\t\t\t���� #" << ++test_num << "\n";
		cout << "\t\t\t\t���������\n\n"
			<< "\t\t\t\ta/b+10, ���� a<b;\n" <<
			"\t\t\tX =\t-51, ���� a=b;\n"
			<< "\t\t\t\t(a*b-4)/a, e��� �>b;\n\n";
		

		cout << setprecision(6);
		exit_ = Result();
	} while (exit_ != ESC);


	return 0;
}