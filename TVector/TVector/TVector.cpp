//#include "TVector.h"
//
//TVector:: TVector(int s = 1)
//{
//	size = s;
//	val = new double[s];
//	for (int i = 0; i < s; i++) 
//		val[i] = 0; 
//}
//
//TVector::TVector(int s, T *p)
//{
//	size = s;
//	val = new double[size];
//	for (int i = 0; i < s; i++)
//		val[i] = p[i];
//}
//
//double& TVector::operator[](int i)
//{
//	
//	if (i < size && i >= 0)
//	{
//		return val[i];
//	}
//	else {
//		std::cout << "Error\n";
//		return val[0];
//	}
//}
//
//double TVector::operator[](int i) const
//{
//	//std::cout << "rvalue\n";
//	if (i < size && i >= 0)
//	{
//		return val[i];
//	}
//	else {
//		std::cout << "Error\n";
//		// возвращаем ссылку на первый элемент вектора
//		return val[0];
//	}
//}
//
//
//
//TVector::TVector(const TVector& v) {
//	size = v.GetSize();
//	val = new double[size];
//	for (int i = 0; i < size; i++)
//		val[i] = v[i];             
//		
//}
//
//TVector::~TVector() {
//	delete[] val;
//	size = 0;
//}
//
//
//TVector TVector::operator+(const TVector& v) const {
//	double dTemp; 
//	TVector temp(size);   
//	if (size == v.size)
//	{
//		for (int i = 0; i < size; i++) {
//			dTemp = val[i] + v[i];
//			temp[i] = dTemp;
//		
//		}
//
//	}
//	else std::cout << "Размеры не совпадают\n";
//	return temp;
//}
//
//
//TVector TVector::operator-(const TVector& v) const {
//	double dTemp;
//	TVector temp(size);
//	if (size == v.size)
//	{
//		for (int i = 0; i < size; i++) {
//			dTemp = val[i] - v[i];
//			temp[i] = dTemp;
//			//temp.SetValue(i, dTemp);
//		}
//
//	}
//	else std::cout << "Размеры не совпадают\n";
//	return temp;
//}
//
//TVector & TVector :: operator=(const TVector & v) 
//{
//	if (this != &v)
//	{
//		if (size != v.size)
//		{
//			delete[] val;
//			size = v.size;
//			val = new double[size];
//		}
//		for (int i = 0; i < size; i++)
//			val[i] = v.val[i];
//	}
//	return *this;
//}
//
//TVector TVector::operator-() {
//	TVector tmp(size);
//	for (int i = 0; i < size; i++)
//		tmp[i] = (-1) * val[i];
//		//tmp.SetValue(i,((-1) * val[i]) );
//	return tmp;
//}
//
//// ++v 
//TVector& TVector::operator++() {
//	for (int i = 0; i < size; i++)
//		++val[i];
//	return *this;
//} 
//// v++ 
//TVector TVector::operator++(int) {
//	TVector temp(*this); // Копируем объект
//	operator++();       // Операция ++ для текущего
//	return temp;        // возвращаем старое значение } 
//}
//
//double  TVector::operator*(const TVector& v) const {
//	double p = 0;
//	for (int i = 0; i < size; i++)
//		p = p + val[i] * v[i];
//	return p;
//}
//
//TVector TVector::operator*(double d) const {
//	TVector temp(size);
//	for (int i = 0; i < size; i++)
//		temp.val[i] = val[i] * d;
//	return temp;
//}
//
//TVector operator*(double a, const TVector& b)
//{
//	return(b * a);
//}
//
//void  TVector::Print() const {
//	for (int i = 0; i < size; i++)
//		std::cout << val[i] << "\n";
//	std::cout << "\n";
//}
//
//void TVector::Input() { //
//	std::cout << "Введите размер:\n";
//	std::cin >> size;
//	std::cout << "Введите вектор:\n";
//	for (int i = 0; i < size; i++)
//		std::cin >> val[i];
//	std::cout << "\n";
//}
//
//std::ostream& operator << (std::ostream& os, const TVector& ob)
//{
//	int size = ob.GetSize();
//	for (int i = 0; i < size; i++) os << ob[i]<< "\n";
//	//os << for (int i = 0; i < size; i++) ob[i] << "\n";
//	os << "\n";
//	return os;
//
//}
//
//
//std::istream& operator >> (std::istream& is, TVector& ob)
//{
//	int size;
//	std::cout << "Введите размер:\n";
//	std::cin >> size;
//	ob.size = size;
//	std::cout << "Введите вектор:\n";
//	//int size = ob.GetSize();
//	for (int i = 0; i < size; i++)
//	{
//		is >> ob[i];
//	}
//	return is;
//}