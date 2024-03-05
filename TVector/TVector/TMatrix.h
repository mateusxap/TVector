#pragma once
#include "TVector.h"

template <typename T>
class TMatrix : private TVector<TVector<T>>
{
protected:
	using TVector<TVector<T>>::pMem;
	using TVector<TVector<T>>::size;
public:
	TMatrix(size_t s = 1) : TVector<TVector<T>>(s)//конструктор
	{
		for (size_t i = 0; i < size; i++)
			pMem[i] = TVector<T>(size);
	}
	TMatrix(const TVector<TVector<T>> &matr):size(matr.size)
	{
		pMem = new TVector<T>[size];
		for (size_t i = 0; i < size; i++)
		{
			pMem[i] = matr[i];
		}
	}
	/*operator TVector<TVector<T>>
	{
		
	}*/
	TMatrix(const TMatrix& matr) //: size(matr.size)// конструктор копирования
	{
		size = matr.size;
		pMem = new TVector<T>[size];
		for (size_t i = 0; i < size; i++)
		{
			pMem[i] = matr.pMem[i];
		}
	}

	TMatrix& operator=(const TMatrix &matr)//<><><><><><><><<><>
	{
		if (this == &matr)
			return *this;
		TMatrix tmp(matr);
		swap(*this, tmp);
		return *this;
	}
	bool operator==(const TMatrix& m) const noexcept
	{
		//return ((*this) == m);
		return TVector<TVector<T>>::operator==(m);
	}
	TMatrix<T> operator*(const T& val)
	{
		TMatrix tmp(size);
		for (size_t i = 0; i < size; i++)
			tmp.pMem[i] = pMem[i] * val;
		return tmp;
	}
	TVector<T> operator*(const TVector<T>& v)
	{
		TVector<T> tmp(size);
		for (size_t i = 0; i < size; i++)
			tmp[i] = pMem[i] * v;
		return tmp;
	}
	TMatrix operator+(const TMatrix& m)
	{
		TMatrix tmp(size);
		for (size_t i = 0; i < size; i++)
			tmp.pMem[i] = pMem[i] + m.pMem[i];
		return tmp;
	}
	TMatrix operator*(const TMatrix& m) //<><><><><><><><
	{
		TMatrix tmp(size);
		for (size_t i = 0; i < size; i++)
			for (size_t j = 0; j < size; j++)
				for (size_t k = 0; k < size; k++)
					tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
		return tmp;
	}

	//TVector<T>& operator[](int i)  // перегрузка скобок
	//{

	//	if (i < size && i >= 0)
	//	{
	//		return pMem[i];
	//	}
	//	else {
	//		std::cout << "Error\n";
	//		return pMem[0];
	//	}
	//}
	//TVector<T> operator[](int i) const // перегрузка скобок для провостоящего присваивания
	//{
	//	if (i < size && i >= 0)
	//	{
	//		return pMem[i];
	//	}
	//	else {
	//		std::cout << "Error\n";
	//		return pMem[0];
	//	}
	//}

	TVector<T>& operator[](int i)
	{
		if (i < size && i >= 0)
		{
			return pMem[i];
		}
		else {
			std::cout << "Error\n";
			static  TVector<T> dummy;  // Создаем временный объект-заглушку
			return dummy;    // Возвращаем ссылку на него
		}
	}

	const TVector<T> operator[](int i) const // перегрузка скобок для постоянного объекта
	{
		if (i < size && i >= 0)
		{
			return pMem[i];
		}
		else {
			std::cout << "Error\n";
			static  TVector<T> dummy;  // Создаем временный объект-заглушку
			return dummy;    // Возвращаем ссылку на него
		}
	}

	void Input()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cin >> pMem[i];
		}
	}

	void Print()
	{
		for (size_t i = 0; i < size; i++)
		{
			std::cout << pMem[i];
			std::cout << "\n";
		}
	}
	friend std::ostream& operator<<(std::ostream& os, const TMatrix& ob)
	{
		size_t size = ob.GetSize();
		for (size_t i = 0; i < size; i++) os << ob[i] << "\n";
		//os << for (int i = 0; i < size; i++) ob[i] << "\n";
		os << "\n";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, TMatrix& ob)
	{

		for (size_t i = 0; i < ob.size; i++)
		{
			is >> ob[i];
		}
		return is;
	}
};

