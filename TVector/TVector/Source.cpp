#include "TVector.h"
#include "TComplex.h";
#include "TMatrix.h"
#include "TUppTrMatrix.h"


//using namespace std;
//void main()
//{
//	setlocale(LC_ALL, "Russian");
//	int i, j;
//
//	cin >> i;
//	cin >> j;
//
//	TMatrix<int> a(i);
//	cout << "������� ������� �" << endl;
//	a.Input();
//	cout << "������� a = " << endl;
//	a.Print();
//	cout << "������ ������� �[1][5]" << endl;
//	cout << a[1][5] << endl;////!!!!!
//	cout << "������ ������� �[1][1]" << endl;
//	cout << a[1][1] << endl;
//	a[4][5] = 544;
//	a.Print();
//	TMatrix<int> b(j);
//	cout << "������� ������� b" << endl;
//	b.Input();
//
//
//	cout << "������� b = " << endl;
//	b.Print();
//
//
//	TMatrix<int> c;
//	c = a + b;
//	cout << "������� c = a + b" << endl;
//	c.Print();
//
//
//	//c = a - b;
//	//cout << "������� c = a - b" << endl;
//	//c.Print();
//
//
//	c = a * b;
//	cout << "������� c = a * b" << endl;
//	c.Print();
//
//	int p;
//	cout << "������� ������" << endl;
//	cin >> p;
//	c = a * p;
//	cout << "������� c = a * p" << endl;
//	c.Print();
//
//	if (c == a)
//		cout << "�����" << endl;
//	else cout << "�� �����" << endl;

//	TMatrix<int> a(5), b(5), c(5);
//	int i, j;
//	setlocale(LC_ALL, "Russian");
//	cout << "������������ �������� ��������� ����������� ������" << endl;
//	for (i = 0; i < 5; i++)
//		for (j = i; j < 5; j++)
//		{
//			a[i][j] = i * 10 + j;
//			b[i][j] = (i * 10 + j) * 100;
//		}
//	c = a + b;
//	cout << "Matrix a = " << endl;
//	//a.Output();
//	cout << "Matrix b = " << endl;
//	//b.Output();
//	cout << "Matrix c = a + b" << endl;
////	c.Output();

int main() {
	setlocale(0, "");

	////�����
	//double valA[4] = {1, 2, 3, 4};
	//double valB[4] = { 1, 1, 1, 1 };
	//double valC[3] = {1.1, 1, 1};
	//

	//TVector<double> A(4,valA);
	//TVector<double> B(4, valB);
	//TVector<double> C(3, valC);

	//

	//A[0] = 88;
	//std::cout << A << std::endl;

	//std::cout << "\n|||||||||||||||||||||||||||||||||||||\n";
	//TVector<double> P;
	//std::cout << P; //������������� 0 �� ��������� 
	////P.Input();
	//std:: cin >> P;
	//std::cout << P * C;
	//const int size = 2;

	//TMatrix<TComplex> A(size);
	////A.Input();
	//std::cout << "\n";

	//TMatrix<TComplex> B(size);
	////B.Input();
	//A.Print();
	//std::cout << "\n";
	//B.Print();
	//std::cout << "\n";

	////TVector<TComplex> C(size);
	////std::cin >> C;

	////std::cout << (A == C) << "\n";
	////std::cout <<(A*C) << "\n";
	//TMatrix<TComplex> C = A + B;
	//std::cout << (A == B) << "\n";
	//std::cout << C << "\n";
	//std::cout << C[0][0] << "\n";

	TUppTrMatrix<double>ATr(3);
	TUppTrMatrix<double>BTr(3);
	std::cout << "����� ����������������� ������� ��������� �� ���������:\n";
	std::cout << ATr << "\n";
	std::cin >> ATr;
	std::cout << "\n";
	std::cin >> BTr;
	std::cout << "\n";




	TUppTrMatrix<double> CTr;
	CTr = ATr * BTr; //���������������� ���������  ���������������
	std::cout << "O��������������� ��������� ���������������:\n";
	std::cout << CTr;



	std::cout << "\n";
	CTr = CTr + BTr; //�������� ����������������
	std::cout << "C������� ����������������\n";
	std::cout << CTr;

	std::cout << "�������������� ���� � TMarix:\n";
	TMatrix<double> C = CTr;
	std::cout << C << "\n";
	std::cout << "��������� � ������� �������� ��� �������� [1][0] �� 17  :\n";
	C[1][0] = 17;
	std::cout << C << "\n";

	std::cout << "���������������� ��������� �� ������ �� ������� ������� (1, 1, 1):\n";
	const  int arrSize = 3; //���������������� ��������� �� ������
	double arr[arrSize] = { 1, 1 ,1 };
	TVector<double> V(arrSize, arr);
	std::cout << CTr* V;
	return 0;

}