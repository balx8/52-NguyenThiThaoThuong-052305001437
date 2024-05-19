#include "Fraction.h"
using namespace std;
void Fraction::taoDoiTuong()
{
	cout << "Nhap tu so: ";
	cin >> this->numerator;
	cout << "Nhap mau so: ";
	cin >> this->denominator;
}
void Fraction::setNumerator(int x)
{
	this->numerator = x;
}
void Fraction::setDenominator(int y)
{
	this->denominator = y;
}
int Fraction::getNumerator() const
{
	return this->numerator;
}
int Fraction::getDenominator() const
{
	return this->denominator;
}

int Fraction::tongTu(Fraction phanSo1, Fraction phanSo2)
{
	return (phanSo1.getNumerator() * phanSo2.getDenominator()) + (phanSo1.getDenominator() * phanSo2.getNumerator());
}

int Fraction::tongMau(Fraction phanSo1, Fraction phanSo2)
{
	return phanSo1.getDenominator() * phanSo2.getDenominator();
}
