#include "BieuThucPhanSo.h"
#include"BieuThucSoHoc.h"
#include<iostream>
#include<istream>
using namespace std;
int rutGon(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return rutGon(b, a % b);
	}
}

istream& operator>>(istream& in, BieuThucPhanSo& nhap)
{
	//cin.ignore();
	cout << "Nhap tu so: ";
	in >> nhap.numerator;
	cout << "Nhap mau so: ";
	in >> nhap.denominator;
	return in;
}

ostream& operator<<(ostream& out, BieuThucPhanSo& xuat)
{
	cout << xuat.numerator << "/" << xuat.denominator;
	return out;
}
BieuThucPhanSo::BieuThucPhanSo()
{
	this->numerator = 0;
	this->denominator = 1;
}

BieuThucPhanSo::BieuThucPhanSo(int tu, int mau)
{
	setNumerator(tu);
	setDenominator(mau);
}

void BieuThucPhanSo::setNumerator(int x)
{
	this->numerator = x;
}
void BieuThucPhanSo::setDenominator(int x)
{
	this->denominator = x;
}
int BieuThucPhanSo::getNumerator() const
{
	return this->numerator;
}
int BieuThucPhanSo::getDenominator() const
{
	return this->denominator;
}
BieuThucPhanSo BieuThucPhanSo::toiGian(int x, int y)
{
	int ucln;
	ucln = rutGon(x, y);
	if (ucln < 0)
	{
		ucln = -ucln;
	}
	x = x / ucln;
	y = y / ucln;

	return BieuThucPhanSo(x, y);
}
BieuThucPhanSo BieuThucPhanSo::operator+(const BieuThucPhanSo& phanSo)
{
	int tu, mau;
	tu = (this->numerator * phanSo.denominator) + (this->denominator * phanSo.numerator);
	mau = this->denominator * phanSo.denominator;

	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}
BieuThucPhanSo BieuThucPhanSo::operator-(const BieuThucPhanSo& phanSo)
{
	int tu, mau;
	tu = (this->numerator * phanSo.denominator) - (this->denominator * phanSo.numerator);
	mau = this->denominator * phanSo.denominator;
	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}

BieuThucPhanSo BieuThucPhanSo::operator*(const BieuThucPhanSo& phanSo)
{
	int tu, mau;
	tu = this->numerator * phanSo.numerator;
	mau = this->denominator * phanSo.denominator;
	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}
BieuThucPhanSo BieuThucPhanSo::operator/(const BieuThucPhanSo& phanSo)
{
	int tu, mau;
	tu = this->numerator * phanSo.denominator;
	mau = this->denominator * phanSo.numerator;
	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}

BieuThucPhanSo BieuThucPhanSo::operator+(const BieuThucSoHoc& soNguyen)
{
	int tu = numerator + (soNguyen.getA() * denominator);
	int mau = denominator;
	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}

BieuThucPhanSo BieuThucPhanSo::operator-(const BieuThucSoHoc& soNguyen)
{
	int tu = numerator - (soNguyen.getA() * denominator);
	int mau = denominator;
	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}

BieuThucPhanSo BieuThucPhanSo::operator*(const BieuThucSoHoc& soNguyen)
{
	int tu = numerator * soNguyen.getA();
	int mau = denominator;
	return BieuThucPhanSo(tu, mau) = toiGian(tu, mau);
}

bool BieuThucPhanSo::operator==(const BieuThucPhanSo& phanSo)
{
	BieuThucPhanSo phanSo1 = *this, phanSo2 = phanSo;
	phanSo1 = toiGian(phanSo1.numerator, phanSo1.denominator);
	phanSo2 = toiGian(phanSo2.numerator, phanSo2.denominator);
	return (phanSo1.numerator == phanSo2.numerator) && (phanSo1.denominator == phanSo2.denominator);
}

bool BieuThucPhanSo::operator!=(const BieuThucPhanSo& phanSo)
{
	BieuThucPhanSo phanSo1 = *this, phanSo2 = phanSo;
	phanSo1 = toiGian(phanSo1.numerator, phanSo1.denominator);
	phanSo2 = toiGian(phanSo2.numerator, phanSo2.denominator);
	return (phanSo1.numerator != phanSo2.numerator) || (phanSo1.denominator != phanSo2.denominator);
}

bool BieuThucPhanSo::operator>=(const BieuThucPhanSo& phanSo)
{
	BieuThucPhanSo phanSo1, phanSo2;
	phanSo1.numerator = this->numerator * phanSo.denominator;
	phanSo2.numerator = this->denominator * phanSo.numerator;
	return (phanSo1.numerator >= phanSo2.numerator);
}
bool BieuThucPhanSo::operator<=(const BieuThucPhanSo& phanSo)
{
	BieuThucPhanSo phanSo1, phanSo2;
	phanSo1.numerator = this->numerator * phanSo.denominator;
	phanSo2.numerator = this->denominator * phanSo.numerator;
	return (phanSo1.numerator <= phanSo2.numerator);
}

bool BieuThucPhanSo::isKiemTra(BieuThucSoHoc soNguyen, BieuThucPhanSo dapAn) const
{
	BieuThucPhanSo phanSoHienTai = *this;
	switch (soNguyen.getPhepToan())
	{
	case '+':
	{
		if (dapAn == phanSoHienTai + soNguyen)
		{
			return true;
		}
	}
	case '-':
	{
		if (dapAn == phanSoHienTai - soNguyen)
		{
			return true;
		}
	}
	case '*':
	{
		if (dapAn == phanSoHienTai * soNguyen)
		{
			return true;
		}
	}
	}
	return false;
}

BieuThucPhanSo BieuThucPhanSo::ketQua(BieuThucSoHoc soNguyen) const
{
	BieuThucPhanSo phanSoHienTai = *this;
	switch (soNguyen.getPhepToan())
	{
	case '+':
	{
		return phanSoHienTai + soNguyen;
	}
	case '-':
	{
		return phanSoHienTai - soNguyen;
	}
	case '*':
	{
		return phanSoHienTai * soNguyen;
	}
	}

}


