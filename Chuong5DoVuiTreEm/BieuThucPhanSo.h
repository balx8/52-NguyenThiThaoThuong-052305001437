#pragma once
#include"BieuThucSoHoc.h"
class BieuThucPhanSo
{
private:
	int numerator;
	int denominator;
public:
	friend istream& operator>>(istream& in, BieuThucPhanSo& nhap);
	friend ostream& operator<<(ostream& out, BieuThucPhanSo& xuat);
	BieuThucPhanSo();
	BieuThucPhanSo(int tu, int mau);
	void setNumerator(int x);
	void setDenominator(int x);
	int getNumerator() const;
	int getDenominator() const;
	BieuThucPhanSo toiGian(int x, int y);
	BieuThucPhanSo operator+(const BieuThucPhanSo& phanSo);
	BieuThucPhanSo operator-(const BieuThucPhanSo& phanSo);
	BieuThucPhanSo operator*(const BieuThucPhanSo& phanSo);
	BieuThucPhanSo operator/(const BieuThucPhanSo& phanSo);
	BieuThucPhanSo operator+(const BieuThucSoHoc& soNguyen);
	BieuThucPhanSo operator-(const BieuThucSoHoc& SoNguyen);
	BieuThucPhanSo operator*(const BieuThucSoHoc& soNguyen);
	bool operator==(const BieuThucPhanSo& phanSo);
	bool operator!=(const BieuThucPhanSo& phanSo);
	bool operator>=(const BieuThucPhanSo& phanSo);
	bool operator<=(const BieuThucPhanSo& phanSo);
	bool isKiemTra(BieuThucSoHoc soNguyen, BieuThucPhanSo dapAn) const;
	BieuThucPhanSo ketQua(BieuThucSoHoc soNguyen) const;
};

