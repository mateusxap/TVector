#pragma once
#include "TVector.h"
#include "TMatrix.h"

struct Indexes
{
	size_t i;
	size_t j;
};

template <typename T>
class TUppTrMatrix : private  TVector<TVector<T>>//если наследовать от TMatrix<T> то нельзя в конструкторе с списке инициализации использовать TVector<TVector<T>>(s)
{
    using TVector<TVector<T>>::pMem;
    using TVector<TVector<T>>::size;
	static Indexes RightIndexes (size_t I, size_t J)
	{
		Indexes ind;
		ind.i = I; 
		ind.j = J - I;
		return ind;
	}
public:
	TUppTrMatrix(const TUppTrMatrix& m) : size(m.size)// конструктор копирования
	{
		pMem = new TVector<T>[size];
		for (size_t i = 0; i < size; i++)
		{
			pMem[i] = m.pMem[i];
		}
	}
	

    TUppTrMatrix(size_t s = 1) : TVector<TVector<T>>(s)//конструктор  список инициализации наследуется только с базового класса
    {
        for (size_t i = 0; i < size; i++)
            pMem[i] = TVector<T>(size-i);
    }

    TUppTrMatrix operator*(const TUppTrMatrix& m) // нужно сделать пересчет индексов 
    {
        TUppTrMatrix tmp(size);
		Indexes indC;
		Indexes indA;
		Indexes indB;

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                for (size_t k = i; k <= j; k++)
                {
					indC = RightIndexes(i, j);
					indA = RightIndexes(i, k);
					indB = RightIndexes(k, j);
                    tmp.pMem[indC.i][indC.j] += (*this)[indA.i][indA.j] * m[indB.i][indB.j];
                }
            }
        }
        return tmp;
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
	friend std::ostream& operator<<(std::ostream& os, const TUppTrMatrix& ob)
	{

		size_t size = ob.GetSize();
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < i; j++)
			{
				os.width(5);
				os.setf(std::ios::left);
				os << "0";
			}
			/*os.width(5);
			os.setf(std::ios::left);*/
			os << ob[i] << "\n";
		}
		//os << for (int i = 0; i < size; i++) ob[i] << "\n";
		os << "\n";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, TUppTrMatrix& ob)
	{
		std::cout << "Введите верхнетреугольную марицу:\n";
		for (size_t i = 0; i < ob.size; i++)
		{
			is >> ob[i];
			for (int j = 0; j <= i; j++)
			{

				std::cout << "  ";
			}

		}
		return is;
	}
	TUppTrMatrix operator+(const TUppTrMatrix& m)
	{
		TUppTrMatrix tmp(size);
		for (size_t i = 0; i < size; i++)
			tmp.pMem[i] = pMem[i] + m.pMem[i];
		return tmp;
	}

	TUppTrMatrix& operator=(const TUppTrMatrix& matr)//<><><><><><><><<><>
	{
		if (this == &matr)
			return *this;
		TUppTrMatrix tmp(matr);
		swap(*this, tmp);
		return *this;
	}
	bool operator==(const TUppTrMatrix& m) const noexcept
	{
		//return ((*this) == m);
		return TVector<TVector<T>>::operator==(m);
	}
	TUppTrMatrix<T> operator*(const T& val)
	{
		TUppTrMatrix<T> tmp(size);
		for (size_t i = 0; i < size; i++)
			tmp.pMem[i] = pMem[i] * val;
		return tmp;
	}
	TVector<T> operator*(const TVector<T>& v)
	{
		TVector<T> tmp(size);
		Indexes indA;
		size_t j = 0;
		for (size_t i = 0; i < size; i++)
		{
				for (size_t k = i; k < size; k++)
				{
					indA = RightIndexes(i, k);
					tmp[i] += (*this)[indA.i][indA.j] * v[i];
				}
		}
		return tmp;
		/*TVector<T> tmp(size);
		for (size_t i = 0; i < size; i++)
			tmp[i] = pMem[i] * v;
		return tmp;*/
	}
	operator TMatrix<T>()
	{
		TMatrix<T> res(size);
		Indexes indTr;
		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = i; j < size; j++)
			{
				indTr = RightIndexes(i, j);
				res[i][j] = (*this)[indTr.i][indTr.j];
			}
		}
		return res;
	}
};


