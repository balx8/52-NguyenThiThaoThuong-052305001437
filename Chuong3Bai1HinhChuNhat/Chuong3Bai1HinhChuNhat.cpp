#include<iostream>
#include"Rectangle.h"
using namespace std;

void menu() {
	cout << "================MENU==============" << endl;
	cout << "1. Nhap cung: " << endl;
	cout << "2. Nhap mem: " << endl;
	cout << "nhan 1 so bat ki de ket thuc " << endl;
	cout << "==================================" << endl;

}
int main()
{
	int luaChon;
	int nhan;
	do
	{
		menu();
		cout << "chon: ";
		cin >> luaChon;
		switch (luaChon)
		{
		case 1: {
			Rectangle rect1, * rect2;
			rect1.setHeight(3);
			rect1.setWidth(4);
			cout << "Height1: " << rect1.getHeight() << endl;
			cout << "Width1: " << rect1.getWidth() << endl;
			cout << "S1 = " << rect1.area() << endl;
			cout << endl;
			rect2 = new Rectangle();
			rect2->setHeight(4);
			rect2->setWidth(5);
			cout << "Height2: " << rect2->getHeight() << endl;
			cout << "Width2: " << rect2->getWidth() << endl;
			cout << "S2 = " << rect2->area() << endl;
			delete rect2;
			break;
		}
		case 2: {
			Rectangle rect1, rect2;
			cout << "nhap hinh thu nhat: " << endl;
			rect1.taoDoiTuong();
			cout << "S1 = " << rect1.area() << endl;
			cout << "nhap hinh thu hai: " << endl;
			rect2.taoDoiTuong();
			cout << "S2 = " << rect2.area() << endl;
			break;
		}
		default:
		{
			nhan = 0;
		}
		}
		if (luaChon == 1 || luaChon == 2) {
			cout << "------------" << endl;
			cout << "1. tiep tuc " << endl;
			cout << "0. thoat " << endl;
			cin >> nhan;
		}
	} while (nhan != 0);
	return 0;

}