#include "EmployeeManager.h"
#include <iostream>
#include<iomanip>
#include<iostream>
#include"Employee.h"
#include"FullTimeEmployee.h"
#include"PartTimeEmployee.h"
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

void hienThiMenu() {
    cout << "============================MENU==============================" << endl;
    cout << "| 1. Nhap Cung                                                |" << endl;
    cout << "| 2. Hien Thi Danh Sach Nhan Vien                             |" << endl;
    cout << "| 3. Them Nhan Vien Moi                                       |" << endl;
    cout << "| 4. Tinh Tong Luong                                          |" << endl;
    cout << "| 5. Dem So Nhan Vien Vao Lam Trong Nam                       |" << endl;
    cout << "| 6. Cap Nhat So Gio Lam Cho Nhan Vien                        |" << endl;
    cout << "| 7. Sap Xep Nhan Vien Theo Ngay Vao Lam                      |" << endl;
    cout << "| 8. Xoa Nhan Vien                                            |" << endl;
    cout << "| 0. Thoat                                                    |" << endl;
    cout << "*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl;
    cout << "Nhap lua chon: ";
}

int main() {
    EmployeeManager qlnv;
    int luaChon;

    do {
        hienThiMenu();
        cin >> luaChon;
        switch (luaChon) {
        case 1:
            qlnv.themNhanVienMau();
            qlnv.hienThiFullTimeEmployee();
            qlnv.hienThiPartTimeEmployee();
            qlnv.tinhTongLuong();
            break;
        case 2:
            qlnv.hienThiFullTimeEmployee();
            qlnv.hienThiPartTimeEmployee();
            qlnv.tinhTongLuong();
            break;
        case 3:
            qlnv.nhapNhanVienTuBanPhim();
            break;
        case 4:
            cout << "--------------------------" << endl;
            cout << "Tong luong: " << qlnv.tinhTongLuong() << endl;
            cout << "--------------------------" << endl;
            break;
        case 5: {
            int nam;
            cout << "Nhap nam: ";
            cin >> nam;
            cout << "So luong nhan vien vao lam trong nam " << nam << ": " << qlnv.demNhanVienTheoNam(nam) << endl;
            break;
        }
        case 6: {
            string ma;
            double soGio;
            cout << "Nhap ma nhan vien: ";
            cin >> ma;
            cout << "Nhap so gio lam moi: ";
            cin >> soGio;
            qlnv.capNhatGioLamChoNhanVien(ma, soGio);
            break;
        }
        case 7:
            qlnv.sapXepNhanVienTheoNgayVaoLam();
            cout << "===SAP XEP THANH CONG===" << endl;
            qlnv.hienThiFullTimeEmployee();
            qlnv.hienThiPartTimeEmployee();
            break;
        case 8: {
            string ma;
            int chon;
            qlnv.hienThiFullTimeEmployee();
            qlnv.hienThiPartTimeEmployee();
            cout << "Nhap ma nhan vien can xoa: ";
            cin >> ma;
            cout << "Ban co chac chan muon xoa khong?" << endl;
            cout << "1. Yes   ---   0.No" << endl;
            cin >> chon;
            if (chon == 1) {
                qlnv.xoaNhanVien(ma);
                cout << "Da xoa thanh cong!" << endl;
                cout << endl;
            }
            else
            {
                cout << "Khong muon xoa!!" << endl;
                cout << endl;
            }
            break;
        }
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cerr << "Lua chon khong hop le! Vui long thu lai.\n";
            break;
        }
    } while (luaChon != 0);

    return 0;
}
