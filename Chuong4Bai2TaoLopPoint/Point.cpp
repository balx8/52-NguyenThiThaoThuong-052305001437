#include"Point.h"
using namespace std;
float Point::getX() const
{
	return this->x;
}
float Point::getY() const
{
	return this->y;
}
void Point::nhap()
{
	cout << "Nhap diem x: ";
	cin >> this->x;
	cout << "Nhap diem y: ";
	cin >> this->y;
}
void Point::xuat() const
{
	cout << setfill(' ');
	cout << "(" << x << " ; " << y << ")";
}
void Point::ghiFile(ofstream& f) const
{
	f << setfill(' ') << setw(3) << left << x << " " << y;
}
void Point::docFile(ifstream& f)
{
	f >> this->x >> this->y;

}
bool Point::operator<(Point toaDo)
{
	float doDai1, doDai2;
	doDai1 = (float)sqrt(pow(this->x, 2) + pow(this->y, 2));
	doDai2 = (float)sqrt(pow(toaDo.x, 2) + pow(toaDo.y, 2));
	return doDai1 < doDai2;

}
