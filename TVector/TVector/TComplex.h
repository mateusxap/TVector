#pragma once
#include <iostream>
#include <ostream>


class TComplex
{
	double re;
	double im;
public:
	void Input(double re, double im);
	TComplex(double re, double im);//�����������
	TComplex(); //����������� �� ���������
	TComplex(double x);//���������� ��������������
	TComplex(const TComplex& ob);
	~TComplex();// �����������
	void Print() const;



	TComplex operator+ (const TComplex& op2) const;
	TComplex& operator+= (const TComplex& op2);

	TComplex operator- (const TComplex& op2);
	TComplex& operator-= (const TComplex& op2);

	TComplex operator* (const TComplex& op2);
	TComplex& operator*= (const TComplex& op2);

	TComplex operator/ (const TComplex& op2);
	TComplex& operator/= (const TComplex& op2);

	TComplex operator^ (int deg); //���������� � ����� �������

	TComplex& operator= (const TComplex& op2);
	int operator==(const TComplex& op2);

	friend std::ostream& operator << (std::ostream& os, const TComplex& ob);
	friend std::istream& operator >> (std::istream& is, TComplex& ob);
	//�friend TComplex operator+(double x, const TComplex& op2);
};

TComplex operator+(double x, const TComplex& op2); //���������� ���� � �������� ����� ������������ �����������
TComplex operator-(double x, const TComplex& op2);
TComplex operator*(double x, const TComplex& op2);
TComplex operator/(double x, const TComplex& op2);


