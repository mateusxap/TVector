#pragma once
#include <iostream>
#include <ostream>
#include <istream>


template<typename T>
class TVector
{
protected:
	size_t size;
	T* pMem; //"������" ��� �������� �������
public:
	friend void swap(TVector& lhs, TVector& rhs) noexcept
	{
		std::swap(lhs.size, rhs.size);
		std::swap(lhs.pMem, rhs.pMem);
	}

	explicit TVector(size_t s = 1): size(s)// �����������
	{
		if (size == 0)
			throw std::out_of_range("Vector size should be greater than zero");
		pMem = new T[size];
		for (size_t i = 0; i < size; i++)
			//pMem[i] = {}; // ������������ �� ��������� ����� � ��� pMem[i] = T();
			pMem = new T[size]();
			//pMem[i] = T();
	}

	explicit TVector(int s, T* arr) : size(s)// �����������
	{
		try
		{
			if (arr == nullptr) throw 2;
			pMem = new T[size];
			std::copy(arr, arr + size, pMem);
		}
		catch (int x)
		{
			std::cout << "Error! TVector ctor requires non-nullptr arg"<< std::endl;
		}
		
		
	}

	TVector(const TVector& v): size(v.size)// ����������� �����������
	{
		pMem = new T[size];
		std::copy(v.pMem, v.pMem + size, pMem);
	}
		
	~TVector()
	{
		size = 0;
		delete[] pMem;
	}
	TVector& operator=(const TVector& v)
	{
		if (this == &v)
			return *this;
		TVector tmp(v);
		swap(*this, tmp);
		return *this;
	}
	//����������� ����������� � ������������ �������� ������������ (����� � ������ ������� ����� ������ �������� ������ �� �����)
	TVector(TVector&& v) noexcept
	{
		pMem = nullptr;
		swap(*this, v);
	}
	TVector& operator=(TVector&& v) noexcept
	{
		swap(*this, v);
		return *this;
	}


	T& operator[](int i)
	{
		if (i < size && i >= 0)
		{
			return pMem[i];
		}
		else {
			std::cout << "Error\n";
			static T dummy;  // ������� ��������� ������-��������
			return dummy;    // ���������� ������ �� ����
		}
	}

	const T& operator[](int i) const // ���������� ������ ��� ����������� �������
	{
		if (i < size && i >= 0)
		{
			return pMem[i];
		}
		else {
			std::cout << "Error\n";
			static T dummy;  // ������� ��������� ������-��������
			return dummy;    // ���������� ������ �� ����
		}
	}

	//const T& operator[](size_t ind) const; //????????????

	size_t GetSize() const { return size; } // ������ �������
	 //��������� �������� 
	TVector operator+(const TVector& v) const // �������� (+) 
	{
		T tTemp;
		TVector temp(size);
		if (size == v.size)
		{
			for (int i = 0; i < size; i++) {
				tTemp = pMem[i] + v[i];
				temp[i] = tTemp;

			}

		}
		else std::cout << "������� �� ���������\n";
		return temp;
	}
	TVector operator-(const TVector& v) const // ��������� (-) 
	{
		T tTemp;
		TVector temp(size);
		if (size == v.size)
		{
			for (int i = 0; i < size; i++) {
				tTemp = pMem[i] - v[i];
				temp[i] = tTemp;

			}

		}
		else std::cout << "������� �� ���������\n";
		return temp;
	}

	bool operator==(const TVector& v) const noexcept
	{
		if (size == v.size)
		{
			for (int i = 0; i < size; i++) {
				if (pMem[i] == v[i]) continue;
				else return false;
			}
			return true;
		}
		else
			return false;
	}
	
	TVector operator-() //������� �����
	{
		TVector tmp(size);
		for (int i = 0; i < size; i++)
			tmp[i] = (-1) * pMem[i];
		return tmp;
	}
	T  operator*(const TVector& v) const // ��������� ������. 
	{
		try
		{
			if (size != v.size) throw 1;
			T zero = T();  // ������� ������ ���� T �� ��������� ����
			//T zero();
			double x();
			T result = zero;
			for (int i = 0; i < size; i++) {
				result = result + (pMem[i] * v.pMem[i]);
			}
			return result;
		}
		catch (int x)
		{
			std::cout << "Error! Vectors must be one size" << std::endl;
		}
		
	}
	TVector operator*(double d) const //��������� �� ������
	{
		TVector temp(size);
		for (int i = 0; i < size; i++)
			temp.pMem[i] = pMem[i] * d;
		return temp;
	}
	void Print() const
	{
		for (int i = 0; i < size; i++)
		{
			std::cout.width(5);
			std::cout.setf(std::ios::left);
			std::cout << pMem[i] << "\n";
		}
			
		std::cout << "\n";
	}
	void  Input()
	{
		std::cout << "������� ������:\n";
		std::cin >> size;
		delete[] pMem;
		pMem = new T[size];
		std::cout << "������� ������:\n";
		for (int i = 0; i < size; i++)
			std::cin >> pMem[i]; //���������� ����� ���������� cin � ���� �������?
		std::cout << "\n";
	}

	friend std::ostream& operator<<(std::ostream& os, const TVector& ob)
	{
		size_t size = ob.GetSize();
		
		for (int i = 0; i < size; i++)
		{
			os.width(5);
			os.setf(std::ios::left);
			os << ob[i];
		}
		//os << for (int i = 0; i < size; i++) ob[i] << "\n";
		os << " ";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, TVector& ob)
	{

		for (int i = 0; i < ob.size; i++)
		{
			is >> ob[i];
		}
		return is;
	}
};

template <typename T>
TVector<T> operator*(double a, const TVector<T>& b) //���������� ���� �� ������� �������� ����� �� ������
{
	return (b * a);
}
