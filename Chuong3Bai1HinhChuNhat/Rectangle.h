#pragma once
#include<iostream>
using namespace std;
class Rectangle
{
private:
	int Height;
	int Width;
public:
	void taoDoiTuong();
	void setHeight(int x);
	void setWidth(int y);
	int getHeight() const;
	int getWidth() const;
	long area() const;
};

