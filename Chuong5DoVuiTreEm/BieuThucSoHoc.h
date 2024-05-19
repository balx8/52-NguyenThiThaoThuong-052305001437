#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
class BieuThucSoHoc
{
private:
	int a;
	int b;
	char phepToan;
public:
	void taoBieuThuc(int gioiHanSo, int gioiHanPhepTinh);
	void setA(int a);
	void setB(int b);
	void setPhepToan(char phepToan);
	int getA() const;
	int getB() const;
	char getPhepToan() const;
	int ketQua() const;
	friend ostream& operator<<(ostream& out, const BieuThucSoHoc xuat);
	friend istream& operator>>(istream& in, BieuThucSoHoc& nhap);
	bool kiemTra(int x) const;
};

