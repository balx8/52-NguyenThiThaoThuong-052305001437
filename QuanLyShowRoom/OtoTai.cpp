#include "OtoTai.h"

OtoTai::OtoTai()
{
	this->taiTrong = 0;
}

OtoTai::OtoTai(string ma, int namSX, double dungTichDongCo, long long int triGiaXe, float taiTrong)
	: Showroom(ma, namSX, dungTichDongCo, triGiaXe)
{
	if (taiTrong <= 0) {
		throw invalid_argument("Tai trong phai >= 0");
	}
	this->taiTrong = taiTrong;
}

void OtoTai::setTaiTrong(float taiTrong)
{
	if (taiTrong <= 0) {
		throw invalid_argument("Tai trong phai >= 0");
	}
	this->taiTrong = taiTrong;
}

float OtoTai::getTaiTrong() const
{
	return this->taiTrong;
}

long long int OtoTai::tinhThue() const
{
	float Thue = 0.1;
	if (taiTrong < 950) {
		return Thue * getTriGiaXe() + thueTruocBa();
	}
	else {
		return Thue * getTriGiaXe() + thueTruocBa();
	}
}
long int OtoTai::thueTruocBa() const
{
	if (taiTrong < 950) {
		return 0.02 * getTriGiaXe();

	}
	else {
		return 0.05 * getTriGiaXe();
	}
}
void OtoTai::toString() const
{
	Showroom::toString();
	cout << setfill(' ');
	cout << setw(12) << right << taiTrong << setw(6) << left << " " << setw(9) << right << (long long int)tinhThue() << endl;
}
ostream& operator<<(ostream& out, const OtoTai& f)
{
	f.toString();
	return out;
}
