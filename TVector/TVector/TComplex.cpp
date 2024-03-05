#include "TComplex.h"



TComplex::TComplex(double re_, double im_)
{
	//std::cout << "\nВызов конструктора инициализации \n";
	re = re_;
	im = im_;
}

TComplex::TComplex()
{
	//std::cout << "\nВызов конструктора по умолчанию\n";
	re = 0;
	im = 0;
}

TComplex::TComplex(double x)
{
	//std::cout << "\nВызов конструктора преобразования\n";
	re = x;
	im = 0;
}


TComplex::TComplex(const TComplex& ob)
{
	//std::cout << "\nВызов конструктора копирования\n";
	re = ob.re;
	im = ob.im;
}

void TComplex::Input(double re_, double im_)
{
	re = re_;
	im = im_;
}

TComplex::~TComplex()
{
	//std::cout << "\nВызов вызов деструктора\n";
}



void TComplex::Print() const
{
	if (im == 0)
		std::cout << re << '\n';
	else if (re == 0)
		std::cout << im << 'i' << '\n';
	else
	{
		if (im < 0)
			std::cout << re << im << 'i' << '\n';
		else
			std::cout << re << '+' << im << 'i' << '\n';
	}
}
//
//void TComplex::Set(double _re, double _im) {
//	re = _re;
//	im = _im;
//}

//операции над комплексными числами

TComplex TComplex :: operator+ (const TComplex& op2) const
{
	TComplex res;
	res.re = re + op2.re;
	res.im = im + op2.im;
	return res;
}


//TComplex TComplex :: operator+ (double x)
//{
//	TComplex res(*this);
//	res.re += x;
//	return res;
//}

//TComplex operator+ (double x, const TComplex& op2) {
//	return TComplex(x + op2.re, op2.im);
//}

TComplex operator+(double x, const TComplex& op2)
{
	TComplex res(x);
	res = op2;
	return res;
	//return (op2 + x);
}



TComplex& TComplex :: operator+= (const TComplex& op2)
{
	re += op2.re;
	im += op2.im;
	return *this;
}

TComplex TComplex :: operator- (const TComplex& op2)
{
	TComplex res;
	res.re = re - op2.re;
	res.im = im - op2.im;
	return res;
}

TComplex& TComplex :: operator-= (const TComplex& op2)
{
	re -= op2.re;
	im -= op2.im;
	return *this;
}


TComplex TComplex :: operator* (const TComplex& op2)
{
	TComplex res;
	res.re = re * op2.re - (im * op2.im);
	res.im = re * op2.im + (op2.re * im);
	return res;
}

TComplex& TComplex :: operator*= (const TComplex& op2)//по другому так как иначе в процессе подсчета будут использоваться уже изменные данные
{
	double r = re * op2.re - (im * op2.im);
	double i = re * op2.im + (op2.re * im);
	re = r;
	im = i;
	return *this;
}

TComplex TComplex :: operator/ (const TComplex& op2)
{
	TComplex res;
	try//ловим ошибку при делении на ноль
	{
		if (op2.re * op2.re + op2.im * op2.im == 0)
			throw 123;
		res.re = (re * op2.re + im * op2.im) / (op2.re * op2.re + op2.im * op2.im);
		res.im = (op2.re * im - re * op2.im) / (op2.re * op2.re + op2.im * op2.im);
	}
	catch (int i) {
		std::cout << "\nErorr №" << i << " - devide by 0" << std::endl;
	}

	return res;
}

TComplex& TComplex :: operator/= (const TComplex& op2)
{
	try
	{
		if (op2.re * op2.re + op2.im * op2.im == 0)
			throw 123;
		double r = (re * op2.re + im * op2.im) / (op2.re * op2.re + op2.im * op2.im);
		double i = (op2.re * im - re * op2.im) / (op2.re * op2.re + op2.im * op2.im);
		re = r;
		im = i;
	}
	catch (int i) {
		std::cout << "\nErorr №" << i << " - devide by 0" << std::endl;
	}


	return *this;
}

TComplex TComplex :: operator^ (int deg)//возведение в степень
{
	TComplex res(*this);
	if (deg == 0)
	{
		res.re = 1;
		res.im = 0;
		return res;
	}
	else if (deg < 0)
	{
		TComplex One(1, 0);
		for (int i = 1; i < -deg; i++)
			res *= (*this);
		return (One / res);
	}
	else
	{
		for (int i = 1; i < deg; i++)
			res *= (*this);
		return res;
	}
}

TComplex& TComplex :: operator= (const TComplex& op2)
{
	re = op2.re;
	im = op2.im;
	return *this;
}

int TComplex :: operator== (const TComplex& op2)
{
	return ((re == op2.re) && (im == op2.im));
}


std::ostream& operator << (std::ostream& os, const TComplex& ob)
{
	//перегрузка потока вывода
	if (ob.im == 0)
		os << ob.re << ' ';
	else if (ob.re == 0)
		os << ob.im << 'i' << ' ';
	else
	{
		if (ob.im < 0)
			os << ob.re << ob.im << 'i' << ' ';
		else
			os << ob.re << '+' << ob.im << 'i' << ' ';
	}
	return os;
}

std::istream& operator >> (std::istream& is, TComplex& ob)
{
	//перегрузка потока ввода

	//double i, r;
	std::cout << "Введите действительную часть: " << std::endl;
	is >> ob.re;
	std::cout << "Введите мнимую часть: " << std::endl;
	is >> ob.im;
	//ob.Set(r, i);
	return is;
}

TComplex operator-(double x, const TComplex& op2)
{
	TComplex res(x);
	res = res - op2;
	return (res);
}

TComplex operator*(double x, const TComplex& op2)
{
	TComplex res(x);
	res = res * op2;
	return (res);
}

TComplex operator/(double x, const TComplex& op2)
{
	TComplex res(x);
	res = res / op2;
	return (res);
}