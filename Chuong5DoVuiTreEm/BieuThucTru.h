#pragma once
#include"BieuThucSoHoc.h"
class BieuThucTru : public BieuThucSoHoc
{
private:
public:
	BieuThucTru();
	int ketQua() const;
	bool kiemTra(int x) const;
};

