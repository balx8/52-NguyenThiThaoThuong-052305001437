#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
class CauHoiTN
{
private:
	string cauHoi;
	string dapAnA;
	string dapAnB;
	string cauTraLoi;
public:
	CauHoiTN();
	CauHoiTN(string, string, string, string);
	void nhap();
	void xuat() const;
	void ghiFile(ofstream& f) const;
	void docFile(ifstream& f);
	bool kiemTra() const;
	friend bool giongNhau(CauHoiTN cau1, CauHoiTN cau2);

};
