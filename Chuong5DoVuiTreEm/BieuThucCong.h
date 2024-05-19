#pragma once
#include"BieuThucSoHoc.h"
class BieuThucCong : public BieuThucSoHoc
{
public:
	BieuThucCong();
	int ketQua() const;
	bool kiemTra(int x) const;

};

