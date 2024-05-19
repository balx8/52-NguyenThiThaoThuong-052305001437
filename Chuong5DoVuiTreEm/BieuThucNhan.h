#pragma once
#include"BieuThucSoHoc.h"
class BieuThucNhan :public BieuThucSoHoc
{
public:
	BieuThucNhan();
	int ketQua() const;
	bool kiemTra(int x) const;
};

