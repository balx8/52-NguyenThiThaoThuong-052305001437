#include "BieuThucTru.h"
#include"BieuThucSoHoc.h"
BieuThucTru::BieuThucTru() :BieuThucSoHoc()
{
	BieuThucSoHoc::setPhepToan('-');
}

int BieuThucTru::ketQua() const
{
	return BieuThucSoHoc::ketQua();
}

bool BieuThucTru::kiemTra(int x) const
{
	return BieuThucSoHoc::kiemTra(x);
}



