#pragma once
#include<iostream>
using namespace std;
class Fraction
{
private:
	int numerator;
	int denominator;
public:
	void taoDoiTuong();
	void setNumerator(int x);
	void setDenominator(int y);
	int getNumerator() const;
	int getDenominator() const;
	int tongTu(Fraction phanSo1, Fraction phanSo2);
	int tongMau(Fraction phanSo1, Fraction phanSo2);
};