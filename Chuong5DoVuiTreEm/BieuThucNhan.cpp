#include "BieuThucNhan.h"
#include"BieuThucSoHoc.h"

BieuThucNhan::BieuThucNhan() :BieuThucSoHoc()
{
	BieuThucSoHoc::setPhepToan('*');
}

int BieuThucNhan::ketQua() const
{
	return BieuThucSoHoc::ketQua();;
}

bool BieuThucNhan::kiemTra(int x) const
{
	return BieuThucSoHoc::kiemTra(x);
}


