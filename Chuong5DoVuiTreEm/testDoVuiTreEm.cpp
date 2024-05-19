#include<iostream>
#include<ctime>
#include<cstdlib>
#include"BieuThucSoHoc.h"
#include"BieuThucCong.h"
#include"BieuThucTru.h"
#include"BieuThucNhan.h"
#include"BieuThucPhucTap.h"
#include<vector>
#include"BieuThucPhanSo.h"
using namespace std;
void tuTaoDe()
{
	vector<BieuThucSoHoc> danhSachCauHoi;
	int soCauHoi;
	int dapAn;
	int soDapAnDung = 0;
	cout << "Nhap so cau hoi can tao: ";
	cin >> soCauHoi;
	for (int i = 0; i < soCauHoi; i++)
	{
		BieuThucSoHoc cauHoi;
		cout << i + 1 << ": -------------" << endl;
		cin >> cauHoi;
		danhSachCauHoi.push_back(cauHoi);
	}
	cout << " Kiem tra nhe _-_-_-_-_-_-_-_-_-_-_-_-" << endl;
	for (int i = 0; i < danhSachCauHoi.size(); i++)
	{
		cout << danhSachCauHoi[i] << endl;
		cout << "Nhap dap an: ";
		cin >> dapAn;
		if (danhSachCauHoi[i].kiemTra(dapAn))
		{
			soDapAnDung++;
			cout << "Cau tra loi cua ban dung!!" << endl;
		}
		else
		{
			cout << "Cau tra loi cua ban sai!!" << endl;
			cout << "Ket qua: " << danhSachCauHoi[i].ketQua() << endl;
		}
	}
	cout << "KET QUA: *BAN DUNG DUOC " << soDapAnDung << " TREN " << soCauHoi << " CAU*" << endl;
}
void taoDe()
{
	int questionNumber;// số câu hỏi
	int level = 1;
	int cauDungLienTiep = 0;
	int gioiHanSo = 10, gioiHanPhepTinh = 10;
	int soDapAnDung = 0;
	//cout << "Nhap so cau hoi: ";
	//cin >> questionNumber;
	questionNumber = 30;
	cout << "De gom co 10 cau hoi" << endl;
	cout << "Dung duoc 3 cau lien tiep thi level tang 1 neu sai 1 cau thi level giam 1" << endl;
	cout << "Level max la 9" << endl;
	srand(time(NULL));
	int dapAn;
	cout << "Kiem Tra_-_-_-_-_-_-_-_-_-" << endl;
	for (int i = 1; i <= questionNumber; i++)
	{

		cout << "Level " << level << ":" << endl;
		cout << "--------" << endl;
		if (level <= 5)
		{
			if (level >= 4)
			{
				gioiHanSo = 100;
			}
			if (level == 3 || level == 5)
			{
				gioiHanPhepTinh = 3;
			}
			if (level == 2 || level == 4)
			{
				gioiHanPhepTinh = 2;
			}
			if (level == 1)
			{
				gioiHanPhepTinh = 1;
			}
			BieuThucSoHoc questionNumber;
			questionNumber.taoBieuThuc(gioiHanSo, gioiHanPhepTinh);
			cout << "(" << i << ") " << questionNumber << endl;
			cout << "Nhap dap an: ";
			cin >> dapAn;
			if (questionNumber.kiemTra(dapAn))
			{
				cauDungLienTiep++;
				soDapAnDung++;
				cout << "Cau tra loi cua ban dung!!" << endl;
			}
			else
			{
				cauDungLienTiep = 0;
				if (level != 1)
				{
					level--;
				}
				cout << "Cau tra loi cua ban sai!!" << endl;
				cout << "Ket qua: " << questionNumber.ketQua() << endl;
			}
		}
		else if (level <= 7)
		{
			BieuThucPhucTap cauHoiPhucTap;
			if (level <= 6)
			{
				cauHoiPhucTap.taoBieuThuc(10, 1);
				cout << "(" << i << ") ";
				cauHoiPhucTap.xuatBieuThucPhucTap();

				cout << "Nhap dap an: ";
				cin >> dapAn;
				if (cauHoiPhucTap.kiemTraBieuThucPhucTap(dapAn))
				{
					cauDungLienTiep++;
					soDapAnDung++;
					cout << "Cau tra loi cua ban dung!!" << endl;
				}
				else
				{
					cauDungLienTiep = 0;
					if (level != 1)
					{
						level--;
					}
					cout << "Cau tra loi cua ban sai!!" << endl;
					cout << "Ket qua: " << cauHoiPhucTap.ketQuaBieuThucPhucTap() << endl;
				}
			}
			else
			{
				cauHoiPhucTap.taoBieuThuc(10, 2);
				cout << "(" << i << ") ";
				cauHoiPhucTap.xuatBieuThucPhucTap();
				cout << "Nhap dap an: ";
				cin >> dapAn;
				if (cauHoiPhucTap.kiemTraBieuThucPhucTap(dapAn))
				{
					cauDungLienTiep++;
					soDapAnDung++;
					cout << "Cau tra loi cua ban dung!!" << endl;
				}
				else
				{
					cauDungLienTiep = 0;
					if (level != 1)
					{
						level--;
					}
					cout << "Cau tra loi cua ban sai!!" << endl;
					cout << "Ket qua: " << cauHoiPhucTap.ketQuaBieuThucPhucTap() << endl;
				}

			}
		}
		else
		{
			BieuThucPhanSo phanSo, ketQua;
			BieuThucSoHoc soNguyen;
			BieuThucPhanSo dapAn;
			phanSo.setNumerator(rand() % 10 + 1);
			phanSo.setDenominator(rand() % 10 + 1);
			soNguyen.taoBieuThuc(10, 3);
			cout << "(" << i << ") " << phanSo << " " << soNguyen.getPhepToan() << " " << soNguyen.getA() << " = ?" << endl;
			cout << "Nhap dap an: " << endl;
			cin >> dapAn;
			if (phanSo.isKiemTra(soNguyen, dapAn))
			{
				cauDungLienTiep++;
				soDapAnDung++;
				cout << "Cau tra loi cua ban dung!!" << endl;
			}
			else
			{
				cauDungLienTiep = 0;
				if (level != 1)
				{
					level--;
				}
				ketQua = phanSo.ketQua(soNguyen);
				cout << "Cau tra loi cua ban sai!!" << endl;
				cout << "Ket qua: " << ketQua << endl;
			}
		}
		if (cauDungLienTiep == 3)
		{
			cauDungLienTiep = 0;
			level++;
			if (level >= 9)
			{
				level = 9;
			}
		}



	}
	cout << "KET QUA: *BAN DUNG DUOC " << soDapAnDung << " TREN " << questionNumber << " CAU*" << endl;

}

void phepCong(int soCauHoi, int& soDapAnDung)
{
	BieuThucCong cong;
	srand(time(NULL));
	int gioiHanSo = 10;
	int dapAn;
	int level = 1, cauDungLienTiep = 0;

	for (int i = 1; i <= soCauHoi; i++)
	{
		cout << "Level " << level << ":" << endl;
		cout << "--------" << endl;
		if (level >= 4)
		{
			gioiHanSo = 100;
		}
		cong.setA(rand() % gioiHanSo + 1);
		cong.setB(rand() % gioiHanSo + 1);
		cout << "(" << i << ") " << cong << endl;

		cout << "Nhap dap an: ";
		cin >> dapAn;
		if (cong.kiemTra(dapAn))
		{
			cauDungLienTiep++;
			soDapAnDung++;
			cout << "Cau tra loi cua ban dung!!" << endl;
		}
		else
		{
			cauDungLienTiep = 0;
			if (level != 1)
			{
				level--;
			}
			cout << "Cau tra loi cua ban sai!!" << endl;
			cout << "Ket qua: " << cong.ketQua() << endl;
		}
		if (cauDungLienTiep == 3)
		{
			cauDungLienTiep = 0;
			level++;
			if (level >= 5)
			{
				level = 5;
			}
		}
	}

}
void phepTru(int soCauHoi, int& soDapAnDung)
{
	BieuThucTru tru;
	srand(time(NULL));
	int gioiHanSo = 10;
	int dapAn;
	int level = 1, cauDungLienTiep = 0;
	for (int i = 1; i <= soCauHoi; i++)
	{
		cout << "Level " << level << ":" << endl;
		cout << "--------" << endl;
		if (level >= 4)
		{
			gioiHanSo = 100;
		}
		tru.setA(rand() % gioiHanSo + 1);
		tru.setB(rand() % gioiHanSo + 1);
		cout << "(" << i << ") " << tru << endl;
		cout << "Nhap dap an: ";
		cin >> dapAn;
		if (tru.kiemTra(dapAn))
		{
			cauDungLienTiep++;
			soDapAnDung++;
			cout << "Cau tra loi cua ban dung!!" << endl;
		}
		else
		{
			cauDungLienTiep = 0;
			if (level != 1)
			{
				level--;
			}
			cout << "Cau tra loi cua ban sai!!" << endl;
			cout << "Ket qua: " << tru.ketQua() << endl;

		}
		if (cauDungLienTiep == 3)
		{
			cauDungLienTiep = 0;
			level++;
			if (level >= 5)
			{
				level = 5;
			}
		}
	}

}
void  phepNhan(int soCauHoi, int& soDapAnDung)
{
	BieuThucNhan nhan;
	srand(time(NULL));
	int gioiHanSo = 10;
	int dapAn;
	int level = 1, cauDungLienTiep = 0;
	for (int i = 1; i <= soCauHoi; i++)
	{
		cout << "Level " << level << ":" << endl;
		cout << "--------" << endl;
		if (level >= 4)
		{
			gioiHanSo = 100;
		}
		nhan.setA(rand() % gioiHanSo + 1);
		nhan.setB(rand() % gioiHanSo + 1);
		cout << "(" << i << ") " << nhan << endl;
		cout << "Nhap dap an: ";
		cin >> dapAn;
		if (nhan.kiemTra(dapAn))
		{
			cauDungLienTiep++;
			soDapAnDung++;
			cout << "Cau tra loi cua ban dung!!" << endl;
		}
		else
		{
			cauDungLienTiep = 0;
			if (level != 1)
			{
				level--;
			}
			cout << "Cau tra loi cua ban sai!!" << endl;
			cout << "Ket qua: " << nhan.ketQua() << endl;
		}
		if (cauDungLienTiep == 3)
		{
			cauDungLienTiep = 0;
			level++;
			if (level >= 5)
			{
				level = 5;
			}
		}
	}

}
void deThi()
{
	int n1, n2, n3;
	int soDapAnDung1 = 0, soDapAnDung2 = 0, soDapAnDung3 = 0;
	cout << "Nhap so cau hoi phep cong: ";
	cin >> n1;
	cout << "Nhap so cau hoi phep tru: ";
	cin >> n2;
	cout << "Nhap so cau hoi phep nhan: ";
	cin >> n3;
	cout << "Kiem Tra_-_-_-_-_-_-_-_-_-" << endl;
	cout << "Phep cong :---------------\n\n";
	phepCong(n1, soDapAnDung1);
	cout << "Phep tru :---------------\n\n";
	phepTru(n2, soDapAnDung2);
	cout << "Phep nhan :---------------\n\n";
	phepNhan(n3, soDapAnDung3);
	cout << "Ket qua : " << endl;
	cout << "So phep cong dung: " << soDapAnDung1 << endl;
	cout << "So phep tru dung: " << soDapAnDung2 << endl;
	cout << "So phep nhan dung: " << soDapAnDung3 << endl;
	cout << "Tong cac cau dung: " << soDapAnDung1 + soDapAnDung2 + soDapAnDung3 << endl;
}
void menu()
{
	cout << "====================* Menu *========================" << endl;
	cout << "1. Tu tao de thi                                   *" << endl;
	cout << "2. De thi ngau nhien                               *" << endl;
	cout << "3. De thi bang cac phep (+ - *)                    *" << endl;
	cout << "====================================================" << endl;
}
int main()
{

	int luaChon;
	do
	{
		menu();
		int chon;
		cout << "Nhap lua chon:";
		cin >> chon;
		switch (chon)
		{
		case 0:
		{
			return 0;
		}
		case 1:// cau a
		{
			tuTaoDe();
			break;
		}
		case 2:// cau b,e,f
		{
			taoDe();
			break;
		}
		case 3:// cau c, d
		{
			deThi();
			break;
		}
		default:
		{
			cout << "Khong hop le!! " << endl;
		}
		}
		cout << "------------------------" << endl;
		cout << "1. Tiep tuc_-_-_0. Thoat" << endl;
		cout << "Chon:";
		cin >> luaChon;

	} while (luaChon != 0);

}
