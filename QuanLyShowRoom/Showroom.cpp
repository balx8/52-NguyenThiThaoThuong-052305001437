#include "Showroom.h"

Showroom::Showroom()
{
	this->ma = "###";
	this->namSX = 0;
	this->dungTichDongCo = 0;
	this->triGiaXe = 0;
}

Showroom::Showroom(string ma, int namSX, double dungTichDongCo, long long int triGiaXe)
{
	if (ma.empty()) {
		throw invalid_argument("Ma khong duoc rong");
	}
	this->ma = ma;
	time_t t = time(nullptr);
	struct tm tm;
	localtime_s(&tm, &t);
	int namHienTai = 1900 + tm.tm_year;
	if (this->namSX > namHienTai) {
		throw invalid_argument("Nam khong hop le.");
	}
	this->namSX = namSX;
	if (dungTichDongCo <= 0) {
		throw invalid_argument("Dung tich dong co phai > 0");
	}
	this->dungTichDongCo = dungTichDongCo;
	if (triGiaXe <= 0) {
		throw invalid_argument("Tri gia xe phai > 0");
	}
	this->triGiaXe = triGiaXe;
}

Showroom::~Showroom()
{
}

void Showroom::setMa(string ma)
{
	if (ma.empty()) {
		throw invalid_argument("Ma khong duoc rong");
	}
	this->ma = ma;
}

void Showroom::setNamSX(int namSX)
{
	time_t t = time(nullptr);
	struct tm tm;
	localtime_s(&tm, &t);
	int namHienTai = 1900 + tm.tm_year;
	if (this->namSX > namHienTai) {
		throw invalid_argument("Nam khong hop le.");
	}
	this->namSX = namSX;
}

void Showroom::setDungTichDongCo(double dungTichDongCo)
{
	if (dungTichDongCo <= 0) {
		throw invalid_argument("Dung tich dong co phai > 0");
	}
	this->dungTichDongCo = dungTichDongCo;
}

void Showroom::setTriGiaXe(long long int triGiaXe)
{
	if (triGiaXe <= 0) {
		throw invalid_argument("Tri gia xe phai > 0");
	}
	this->triGiaXe = triGiaXe;
}

string Showroom::getMa() const
{
	return this->ma;
}

int Showroom::getNamSX() const
{
	return this->namSX;
}

double Showroom::getDungTichDongCo() const
{
	return this->dungTichDongCo;
}

long long int Showroom::getTriGiaXe() const
{
	return 	this->triGiaXe;
}

void Showroom::toString() const
{
	cout << setfill(' ');
	cout << setw(9) << left << ma << setw(18) << left << namSX;
	cout << setw(14) << left << dungTichDongCo << setw(11) << right << triGiaXe;
}

ostream& operator<<(ostream& out, const Showroom& f)
{
	f.toString();
	return out;
}
