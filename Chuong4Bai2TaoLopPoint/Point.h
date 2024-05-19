#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
class Point
{
private:
	float x;
	float y;
public:
	float getX() const;
	float getY() const;
	void nhap();
	void xuat() const;
	void ghiFile(ofstream& f) const;
	void docFile(ifstream& f);
	bool operator<(Point toaDo);


};

