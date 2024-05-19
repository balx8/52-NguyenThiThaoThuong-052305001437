#include "SinhVien.h"
using namespace std;

SinhVien::SinhVien()
{
	this->maSoSinhVien = "####";
	this->hoTen = "####";
	this->soBuoiVang = 0;
	this->diemGiuaKy = 0;
	this->diemThucHanh = 0;
}

SinhVien::SinhVien(string, string, int, float, float)
{
	nhap();
}

void SinhVien::nhap()
{
	cin.ignore();
	cout << "Nhap ma so         : ";
	getline(cin, this->maSoSinhVien);
	cout << "Nhap ten           : ";
	getline(cin, this->hoTen);
	cout << "Nhap so buoi vang  : ";
	cin >> this->soBuoiVang;
	cout << "Nhap diem thuc hanh: ";
	cin >> this->diemThucHanh;
	cout << "Nhap diem giua ky  : ";
	cin >> this->diemGiuaKy;
}

void SinhVien::ghiFile(ofstream& f) const
{
	f << this->maSoSinhVien << ",";
	f << this->hoTen << ",";
	f << this->soBuoiVang << ",";
	f << this->diemThucHanh << ",";
	f << this->diemGiuaKy;
}

void SinhVien::docFile(ifstream& f)
{
	getline(f, this->maSoSinhVien, ',');
	getline(f, this->hoTen, ',');
	f >> this->soBuoiVang;
	f.ignore();
	f >> this->diemThucHanh;
	f.ignore();
	f >> this->diemGiuaKy;
	f.ignore();

}

void SinhVien::xuat() const
{

	cout << setfill(' ');
	cout << setw(10) << left << this->maSoSinhVien;
	cout << setw(20) << left << this->hoTen;
	cout << setw(20) << right << this->soBuoiVang;
	cout << setw(20) << right << this->diemThucHanh;
	cout << setw(20) << right << this->diemGiuaKy << endl;
}

double SinhVien::diemQuaTrinh() const
{
	double diemQT;
	if (soBuoiVang <= 5)
	{
		diemQT = ((10 - soBuoiVang * 2) * 0.2) + (diemThucHanh * 0.3) + (diemGiuaKy * 0.5);
	}
	else
	{
		diemQT = 0;
	}
	return diemQT;
}

bool SinhVien::danhSachHoNguyen()
{
	if (
		(hoTen[0] == 'N') &&
		(hoTen[1] == 'g') &&
		(hoTen[2] == 'u') &&
		(hoTen[3] == 'y') &&
		(hoTen[4] == 'e') &&
		(hoTen[5] == 'n')
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SinhVien::chuanHoaTen()
{
	while (hoTen[hoTen.size() - 1] == ' ')
	{
		hoTen.erase(hoTen.begin() + (hoTen.size() - 1));
	}
	while (hoTen[0] == ' ')
	{
		hoTen.erase(hoTen.begin() + 0);
	}
	hoTen[0] = toupper(hoTen[0]);
	for (int i = 1; i < hoTen.size(); i++)
	{
		hoTen[i] = tolower(hoTen[i]);
		if (hoTen[i - 1] == ' ')
		{
			hoTen[i] = toupper(hoTen[i]);
		}
	}
}

string SinhVien::tenSinhVien()
{
	long long soKyTu = hoTen.size();
	long long x = soKyTu;
	string ten = "";
	while (hoTen[soKyTu] != ' ')// Dinh Quoc Dat  
	{
		soKyTu--;
	}
	for (long long i = soKyTu + 1; i < x; i++)
	{
		ten = ten + hoTen[i]; //Dat
	}
	return ten;
}

