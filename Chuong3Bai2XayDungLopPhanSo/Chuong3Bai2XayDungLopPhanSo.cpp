#include<iostream>
#include"Fraction.h"
using namespace std;
int  rutGon(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return rutGon(b, a % b);
	}
}
void menu()
{
	cout << "================MENU==============" << endl;
	cout << "1. Nhap cung: " << endl;
	cout << "2. Nhap mem: " << endl;
	cout << "nhan 1 so bat ki de ket thuc " << endl;
	cout << "==================================" << endl;

 }
int main()
{
	int luaChon, nhan;
	do
	{
		menu();
		cout << "chon: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1:
		{
			Fraction phanSo1, phanSo2, phanSo;
			cout << "Nhap phan so 1: " << endl;
			phanSo1.setNumerator(1);
			cout << "Tu so: " << phanSo1.getNumerator() << endl;
			phanSo1.setDenominator(2);
			cout << "Mau so: " << phanSo1.getDenominator() << endl;
			cout << "Nhap phan so 2: " << endl;
			phanSo2.setNumerator(3);
			cout << "Tu so: " << phanSo2.getNumerator() << endl;
			phanSo2.setDenominator(4);
			cout << "Mau so: " << phanSo2.getDenominator() << endl;
			cout << "Tong 2 phan so la: ";
			int x = rutGon(phanSo.tongTu(phanSo1, phanSo2), phanSo.tongMau(phanSo1, phanSo2));
			cout << 1.0 * phanSo.tongTu(phanSo1, phanSo2) / x << "/" << 1.0 * phanSo.tongMau(phanSo1, phanSo2) / x << endl;
			break;
		}
		case 2:
		{
			Fraction phanSo1, phanSo2, phanSo;
			cout << "Nhap phan so 1: " << endl;
			phanSo1.taoDoiTuong();
			cout << "Nhap phan so 2: " << endl;
			phanSo2.taoDoiTuong();
			cout << "Tong 2 phan so la: ";
			if (phanSo.tongTu(phanSo1, phanSo2) == phanSo.tongMau(phanSo1, phanSo2))
			{
				cout << 1 << endl;
			}
			else
			{
				int x = rutGon(phanSo.tongTu(phanSo1, phanSo2), phanSo.tongMau(phanSo1, phanSo2));
				cout << 1.0 * phanSo.tongTu(phanSo1, phanSo2) / x << "/" << 1.0 * phanSo.tongMau(phanSo1, phanSo2) / x << endl;
			}
			break;
		}
		default:
		{
			nhan = 0;
		}
		}
		if (luaChon == 1 || luaChon == 2) 
		{
			cout << "------------" << endl;
			cout << "1. tiep tuc " << endl;
			cout << "0. thoat " << endl;
			cin >> nhan;
		}
	} while (nhan != 0);
	return 0;
}
