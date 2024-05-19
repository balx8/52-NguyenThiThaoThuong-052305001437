#include "BieuThucPhucTap.h"
#include"BieuThucSoHoc.h";
void BieuThucPhucTap::taoBieuThuc(int gioiHanSo, int gioiHanPhepTinh)
{
	BieuThucSoHoc::taoBieuThuc(gioiHanSo, gioiHanPhepTinh);
}

void BieuThucPhucTap::xuatBieuThucPhucTap() const
{
	cout << "(" << BieuThucSoHoc::getA() << " " << BieuThucSoHoc::getPhepToan() << " " << BieuThucSoHoc::getB() << ")";
	cout << "*" << "(" << BieuThucSoHoc::getA() << " " << BieuThucSoHoc::getPhepToan() << " " << BieuThucSoHoc::getB() << ")" << endl;
}

bool BieuThucPhucTap::kiemTraBieuThucPhucTap(int dapAn) const
{

	switch (BieuThucSoHoc::getPhepToan())
	{
	case '+':
	{
		if (dapAn == (BieuThucSoHoc::getA() + BieuThucSoHoc::getB()) * (BieuThucSoHoc::getA() + BieuThucSoHoc::getB()))
		{
			return true;
		}
	}
	case '-':
	{
		if (dapAn == (BieuThucSoHoc::getA() - BieuThucSoHoc::getB()) * (BieuThucSoHoc::getA() - BieuThucSoHoc::getB()))
		{
			return true;
		}
	}
	case '*':
	{
		if (dapAn == (BieuThucSoHoc::getA() * BieuThucSoHoc::getB()) * (BieuThucSoHoc::getA() * BieuThucSoHoc::getB()))
		{
			return true;
		}
	}
	}
	return false;
}

int BieuThucPhucTap::ketQuaBieuThucPhucTap() const
{
	switch (BieuThucSoHoc::getPhepToan())
	{
	case '+':
	{
		return (BieuThucSoHoc::getA() + BieuThucSoHoc::getB()) * (BieuThucSoHoc::getA() + BieuThucSoHoc::getB());

	}
	case '-':
	{
		return (BieuThucSoHoc::getA() - BieuThucSoHoc::getB()) * (BieuThucSoHoc::getA() - BieuThucSoHoc::getB());

	}
	case '*':
	{
		return  (BieuThucSoHoc::getA() * BieuThucSoHoc::getB()) * (BieuThucSoHoc::getA() * BieuThucSoHoc::getB());

	}
	}

}

