#include"Point.h"
#include<iostream>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
void ghiToaDo()
{

	int soToaDo;
	cout << "Nhap so toa do: ";
	cin >> soToaDo;
	ofstream f;
	f.open("toaDo.txt", ios_base::out);
	f << soToaDo << endl;
	for (int i = 0; i < soToaDo; i++)
	{
		cout << "Toa do " << i + 1 << ": " << endl;
		Point toaDo;
		toaDo.nhap();
		toaDo.ghiFile(f);
		if (i < soToaDo - 1)
		{
			f << endl;
		}
	}
	f.close();
}
void docToaDo(vector<Point>& diem, int& soToaDo)
{
	Point toaDo;
	ifstream f;
	f.open("toaDo.txt", ios_base::in);
	f >> soToaDo;
	while (!f.eof())
	{
		toaDo.docFile(f);
		diem.push_back(toaDo);
	}
	f.close();
}
void xuatToaDo(vector<Point> diem)
{
	for (int i = 0; i < diem.size(); i++)
	{
		diem[i].xuat();
		cout << endl;
	}
}
/*
bool kiemTra(Point diem1, Point diem2)
{
	if (diem1 < diem2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
*/
void sapXep(vector<Point> diem)
{
	sort(diem.begin(), diem.end());
	xuatToaDo(diem);
}
void menu()
{
	cout << "=====================* MENU *=====================" << endl;
	cout << "* 1.Ghi toa do " << endl;
	cout << "* 2.Doc va xuat toa do" << endl;
	cout << "* 3.Xuat khoang cach tang dan tu diem den goc toa do" << endl;
	cout << "* Nhap so bat ki de thoat" << endl;
	cout << "*================================================*" << endl;
}
int main()
{
	int nhan;
	do
	{
		menu();
		vector<Point>diem;
		int soToaDo;
		docToaDo(diem, soToaDo);
		cout << "Moi chon: ";
		int chon;
		cin >> chon;
		cin.ignore();
		switch (chon)
		{
		case 1:
		{
			ghiToaDo();
			break;
		}
		case 2:
		{   cout << soToaDo << endl;
		xuatToaDo(diem);
		break;
		}
		case 3:
		{
			cout << soToaDo << endl;
			sapXep(diem);
			break;

		}
		default:
		{
			nhan = 0;
		}
		}
		if (chon == 1 || chon == 2 || chon == 3)
		{
			cout << "-------------------------------" << endl;
			cout << "1. Tiep tuc   0.Thoat" << endl;
			cout << "Chon: ";
			cin >> nhan;
		}
	} while (nhan != 0);
	return 0;
}
