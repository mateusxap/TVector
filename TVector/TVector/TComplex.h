#pragma once
#include <iostream>
#include <ostream>


class TComplex
{
	double re;
	double im;
public:
	void Input(double re, double im);
	TComplex(double re, double im);//конструктор
	TComplex(); //конструктор по умолчанию
	TComplex(double x);//контруктор преобразования
	TComplex(const TComplex& ob);
	~TComplex();// декструктор
	void Print() const;



	TComplex operator+ (const TComplex& op2) const;
	TComplex& operator+= (const TComplex& op2);

	TComplex operator- (const TComplex& op2);
	TComplex& operator-= (const TComplex& op2);

	TComplex operator* (const TComplex& op2);
	TComplex& operator*= (const TComplex& op2);

	TComplex operator/ (const TComplex& op2);
	TComplex& operator/= (const TComplex& op2);

	TComplex operator^ (int deg); //возведение в целую степень

	TComplex& operator= (const TComplex& op2);
	int operator==(const TComplex& op2);

	friend std::ostream& operator << (std::ostream& os, const TComplex& ob);
	friend std::istream& operator >> (std::istream& is, TComplex& ob);
	//йfriend TComplex operator+(double x, const TComplex& op2);
};

TComplex operator+(double x, const TComplex& op2); //вызываются если к обычному числу прибавляется комплексное
TComplex operator-(double x, const TComplex& op2);
TComplex operator*(double x, const TComplex& op2);
TComplex operator/(double x, const TComplex& op2);


