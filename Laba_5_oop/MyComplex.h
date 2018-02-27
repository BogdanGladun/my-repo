#pragma once

#include <iostream> 
#include<limits>


using namespace std;

class MyComplex
{
private:



	double real;
	double image;

	
public:


	MyComplex()

	{
		real = 0;
		image = 0;
	}


	MyComplex(double r, double i) {
		real = r; 
		image = i; 
	}


	MyComplex(const MyComplex &ob)
	{
		real = ob.real; image = ob.image;
	};


	friend ostream &operator<<(ostream &, MyComplex &); 
	friend istream &operator >> (istream &, MyComplex &);



	MyComplex& operator = (MyComplex);
	MyComplex& operator = (int);



	friend MyComplex operator + (MyComplex&,MyComplex&);
	friend MyComplex operator + (MyComplex&,int);



	friend MyComplex operator - (MyComplex&,MyComplex&);
	friend MyComplex operator - (MyComplex&,int);



	friend MyComplex operator * (MyComplex&,MyComplex&);
	friend MyComplex operator * (MyComplex&,int);


	friend MyComplex operator / (MyComplex&,MyComplex&);


	bool operator != (MyComplex& com);


	bool operator > (int num);
	bool operator < (int num);

	bool operator > (MyComplex);
	bool operator < (MyComplex);

	operator double();
};

