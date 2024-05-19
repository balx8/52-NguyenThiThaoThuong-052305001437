#include "BieuThucSoHoc.h"

void BieuThucSoHoc::taoBieuThuc(int gioiHanSo, int gioiHanPhepTinh)
{

	setA(rand() % gioiHanSo + 1);
	setB(rand() % gioiHanSo + 1);
	int c = rand() % gioiHanPhepTinh + 1;
	if (c == 1)
	{
		setPhepToan('+');
	}
	else if (c == 2)
	{
		setPhepToan('-');
	}
	else if (c == 3)
	{
		setPhepToan('*');
	}
}

void BieuThucSoHoc::setA(int a)
{
	this->a = a;
}

void BieuThucSoHoc::setB(int b)
{
	this->b = b;
}

void BieuThucSoHoc::setPhepToan(char phepToan)
{
	this->phepToan = phepToan;
}

int BieuThucSoHoc::getA() const
{
	return a;
}

int BieuThucSoHoc::getB() const
{
	return b;
}

char BieuThucSoHoc::getPhepToan() const
{
	return phepToan;
}

int BieuThucSoHoc::ketQua() const
{
	switch (phepToan)
	{
	case '+':
	{
		return a + b;
		break;
	}
	case '-':
	{
		return a - b;
		break;
	}
	case '*':
	{
		return a * b;
		break;
	}
	}
	return false;
}


bool BieuThucSoHoc::kiemTra(int x) const
{
	switch (phepToan)
	{
	case '+':
	{
		if (x == (a + b))
		{
			return true;
		}
		break;
	}
	case '-':
	{
		if (x == (a - b))
		{
			return true;
		}
		break;
	}
	case '*':
	{
		if (x == (a * b))
		{
			return true;
		}
		break;
	}
	}
	return false;

}

ostream& operator<<(ostream& out, const BieuThucSoHoc xuat)
{
	cout << xuat.a << " " << xuat.phepToan << " " << xuat.b << " = ?";
	return out;
}
istream& operator>>(istream& in, BieuThucSoHoc& nhap)
{
	cout << "Nhap bieu thuc: " << endl;
	cout << "Nhap a: ";
	cin >> nhap.a;
	cout << "Nhap phep tinh: ";
	cin >> nhap.phepToan;
	cout << "Nhap b: ";
	cin >> nhap.b;
	return in;

}