#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include"SinhVien.h"

using namespace std;

void nhapDanhSachSV() {
    int soSinhVien;
    cout << "Nhap so sinh vien can nhap: ";
    cin >> soSinhVien;
   // vector<SinhVien> danhSachSinhVien;
    ofstream f;
    f.open("sinhVien.txt", ios_base::out);
    for (int i = 0; i < soSinhVien; i++) {
        SinhVien sv;
        cout << "Sinh vien so " << i + 1 << endl;
        sv.nhap();
    //    danhSachSinhVien.push_back(sv);
        sv.ghiFile(f);
        if (i < soSinhVien - 1) {
            f << endl;
        }
    }
    f.close();
}

void chuanHoaHoTen1(vector<SinhVien>& sv) {
    std::ofstream f("sinhVien.txt", ios_base::out | ios_base::trunc);
    if (!f.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    for (int i = 0; i < sv.size(); i++) {
        sv[i].chuanHoaTen();
        sv[i].ghiFile(f);
        if (i < sv.size() - 1) {
            f << endl;
        }
    }
    f.close();
}

void docFile1(vector<SinhVien>& sv) {
    ifstream f;
    f.open("sinhVien.txt", ios_base::in);
    while (!f.eof()) {
        SinhVien ojb;
        ojb.docFile(f);
        sv.push_back(ojb);
    }
    f.close();
}

void xuatDanhSach(vector<SinhVien> sv) {
    cout << setfill(' ');
    cout << setw(10) << left << "Ma so " << setw(20) << left << "Ho ten" << setw(20) << right << "So buoi vang" << setw(20) << right << "Diem thuc hanh" << setw(20) << right << "Diem giua ky" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    for (int i = 0; i < sv.size(); i++) {
        sv[i].xuat();
        cout << endl;
    }
}

void sinhVienDuDieuKien(vector<SinhVien> sv) {
    cout << setfill(' ');
    cout << setw(10) << left << "Ma so " << setw(20) << left << "Ho ten" << setw(20) << right << "So buoi vang" << setw(20) << right << "Diem thuc hanh" << setw(20) << right << "Diem giua ky" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    for (int i = 0; i < sv.size(); i++) {
        if (sv[i].diemQuaTrinh() >= 3) {
            sv[i].xuat();
            cout << endl;
        }
    }
}

void hoNguyen(vector<SinhVien> sv) {
    cout << setfill(' ');
    cout << setw(10) << left << "Ma so " << setw(20) << left << "Ho ten" << setw(20) << right << "So buoi vang" << setw(20) << right << "Diem thuc hanh" << setw(20) << right << "Diem giua ky" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    for (int i = 0; i < sv.size(); i++) {
        if (sv[i].danhSachHoNguyen() == true) {
            sv[i].xuat();
            cout << endl;
        }
    }
}

void sinhVienTenTrungNhau(vector <SinhVien> sv) {
    cout << setfill(' ');
    cout << setw(10) << left << "Ma so " << setw(20) << left << "Ho ten" << setw(20) << right << "So buoi vang" << setw(20) << right << "Diem thuc hanh" << setw(20) << right << "Diem giua ky" << endl;
    cout << setfill('-') << setw(90) << "-" << endl;
    int dem;
    for (int i = 0; i < sv.size(); i++) {
        dem = -1;
        for (int j = 0; j < sv.size(); j++) {
            if (j != i) {
                if (sv[j].tenSinhVien() == sv[i].tenSinhVien()) {
                    dem++;
                }
            }
        }
        if (dem != -1) {
            sv[i].xuat();
            cout << endl;
        }
    }
}

void menu() {
    cout << "=====================* MENU *===================" << endl;
    cout << "* 1. Nhap danh sach sinh vien " << endl;
    cout << "* 2. Xuat danh sach sinh vien " << endl;
    cout << "* 3. Xuat danh sinh vien ho Nguyen" << endl;
    cout << "* 4. Xuat danh sach sinh vien du dieu kien thi" << endl;
    cout << "* 5. Xuat danh sach cac ten trung nhau" << endl;
    cout << "* Nhap so bat ki de thoat *" << endl;
    cout << "================================================" << endl;
}

int main() {
    int luaChon;
    int nhap;

    do {
        menu();
        vector<SinhVien> sv;
        docFile1(sv);
        chuanHoaHoTen1(sv);
        sv.clear();
        docFile1(sv);
        cout << "Chon: ";
        cin >> luaChon;
        switch (luaChon) {
        case 1: {
            nhapDanhSachSV();
            docFile1(sv);
            break;
        }
        case 2: {
            xuatDanhSach(sv);
            break;
        }
        case 3: {
            hoNguyen(sv);
            break;
        }
        case 4: {
            sinhVienDuDieuKien(sv);
            break;
        }
        case 5: {
            sinhVienTenTrungNhau(sv);
            break;
        }
        default: {
            nhap = 0;
        }
        }
        if (luaChon == 1 || luaChon == 2 || luaChon == 3 || luaChon == 4 || luaChon == 5) {
            cout << endl;
            cout << "-------------------------" << endl;
            cout << "1. tiep tuc---- 0. thoat " << endl;
            cout << "Chon: ";
            cin >> nhap;
        }
    } while (nhap != 0);
    return 0;
}