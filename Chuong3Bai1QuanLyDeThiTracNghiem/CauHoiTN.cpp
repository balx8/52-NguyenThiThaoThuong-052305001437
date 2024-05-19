#include "CauHoiTN.h"
using namespace std;
CauHoiTN::CauHoiTN()
{
	this->cauHoi = "0";
	this->dapAnA = "0";
	this->dapAnB = "0";
	this->cauTraLoi = "0";
}

CauHoiTN::CauHoiTN(string cauHoi, string dapAnA, string dapAnB, string cauTraLoi)
{
	nhap();
}
void CauHoiTN::nhap()
{
	cout << "Nhap cau hoi: ";
	getline(cin, this->cauHoi);
	cout << "Nhap dap an A: ";
	getline(cin, this->dapAnA);
	cout << "Nhap dap an B: ";
	getline(cin, this->dapAnB);
	cout << "Nhap cau tra loi: ";
	getline(cin, this->cauTraLoi);
}

void CauHoiTN::xuat() const
{
	cout << this->cauHoi << endl;
	cout << "A: " << this->dapAnA << endl;
	cout << "B: " << this->dapAnB << endl;
	cout << "Dap an dung: " << this->cauTraLoi << endl;;
}

void CauHoiTN::ghiFile(ofstream& f) const
{
	f << this->cauHoi<<endl;
	f << this->dapAnA<<endl;
	f << this->dapAnB<<endl;
	f << this->cauTraLoi;
}

void CauHoiTN::docFile(ifstream& f)
{
	getline(f, this->cauHoi);
	getline(f, this->dapAnA);
	getline(f, this->dapAnB);
	getline(f, this->cauTraLoi);

}

bool CauHoiTN::kiemTra() const
{
	cout << this->cauHoi << endl;
	cout << "A: " << this->dapAnA << endl;
	cout << "B: " << this->dapAnB << endl;
	string cauTraLoiMy;
	cout << "Nhap dap an: ";
	getline(cin, cauTraLoiMy);
	if (this->cauTraLoi == cauTraLoiMy)
	{
		return true;
	}
	else
	{
		return false;
	}

}
