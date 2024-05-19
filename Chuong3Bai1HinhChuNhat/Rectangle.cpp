#include "Rectangle.h"
using namespace std;
void Rectangle::taoDoiTuong()
{
	cout << "Nhap Height: ";
	cin >> Height;
	cout << "Nhap Width: ";
	cin >> Width;
}
void Rectangle::setHeight(int x)
{
	this->Height = x;
}
void Rectangle::setWidth(int y)
{
	this->Width = y;
}
int  Rectangle::getHeight() const
{
	return this->Height;
}
int Rectangle::getWidth() const
{
	return this->Width;
}
long Rectangle::area() const
{
	int x, y;
	x = getHeight();
	y = this->getWidth();
	return x * y;
}