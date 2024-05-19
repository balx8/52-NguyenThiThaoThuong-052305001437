#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;
class SinhVien
{
private:
	string maSoSinhVien;
	string hoTen;
	int soBuoiVang;
	float diemThucHanh;
	float diemGiuaKy;
public:
	SinhVien();
	SinhVien(string, string, int, float, float);
	void nhap();
	void ghiFile(ofstream& f) const;
	void docFile(ifstream& f);
	void xuat() const;
	double diemQuaTrinh() const;
	bool danhSachHoNguyen();
	void chuanHoaTen();
	string  tenSinhVien();

};
