#include "BieuThucCong.h"
#include"BieuThucSoHoc.h"

BieuThucCong::BieuThucCong() :BieuThucSoHoc()
{
	BieuThucSoHoc::setPhepToan('+');
}

int BieuThucCong::ketQua() const
{
	return BieuThucSoHoc::ketQua();
}

bool BieuThucCong::kiemTra(int x) const
{
	return BieuThucSoHoc::kiemTra(x);
}

