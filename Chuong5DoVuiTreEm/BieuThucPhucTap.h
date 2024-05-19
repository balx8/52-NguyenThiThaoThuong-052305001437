#pragma once
#include"BieuThucSoHoc.h"
class BieuThucPhucTap :public BieuThucSoHoc
{
public:
	void taoBieuThuc(int gioiHanSo, int gioiHanPhepTinh);
	void xuatBieuThucPhucTap() const;
	bool kiemTraBieuThucPhucTap(int dapAn) const;
	int ketQuaBieuThucPhucTap() const;

};
