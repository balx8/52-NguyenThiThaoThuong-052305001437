#include "EmployeeManager.h"
#include <iomanip>
using namespace std;

EmployeeManager::~EmployeeManager() {
    for (Employee* employee : danhSachNhanVien) {
        delete employee;
    }
}

void EmployeeManager::themNhanVien(Employee* employee) {
    for (const auto& nv : danhSachNhanVien) {
        if (nv->getMa() == employee->getMa()) {
            cerr << "Ma nhan vien da ton tai!" << endl;
            return;
        }
    }
    danhSachNhanVien.push_back(employee);
}

void EmployeeManager::themNhanVienMau() {
    danhSachNhanVien.push_back(new FullTimeEmployee("001", "Pham Thi Thanh Ngan", "2021-06-15", "0123456789", 1800000, 3.0, 5));
    danhSachNhanVien.push_back(new FullTimeEmployee("002", "Huynh Thanh Nhung", "2020-03-2", "0987654321", 1800000, 2.5, 3));
    danhSachNhanVien.push_back(new PartTimeEmployee("003", "Le Thanh Thanh", "2022-01-10", "0912345678", 1500000, 30, 50000));
    danhSachNhanVien.push_back(new PartTimeEmployee("004", "Hoang Van Thi", "2019-07-25", "0909876543", 1500000, 45, 50000));
    danhSachNhanVien.push_back(new FullTimeEmployee("005", "Le Thi Bich My", "2018-12-05", "0934567890", 1800000, 4.0, 7));
}


void EmployeeManager::nhapNhanVienTuBanPhim() {
    string ma, hoTen, ngayVaoLam, soDienThoai;
    double luongCanBan;
    cout << "Nhap Ma: ";
    cin >> ma;
    cout << "Nhap Ho Ten: ";
    cin.ignore();
    getline(cin, hoTen);
    cout << "Nhap Ngay Vao Lam (YYYY-MM-DD): ";
    cin >> ngayVaoLam;
    cout << "Nhap So Dien Thoai: ";
    cin >> soDienThoai;
    cout << "Nhap Luong Can Ban: ";
    cin >> luongCanBan;

    int loai;
    cout << "Nhap Loai Nhan Vien (1.FullTime - 2.PartTime): ";
    cin >> loai;

    if (loai == 1) {
        double heSoLuong;
        int soNamKinhNghiem;
        cout << "Nhap He So Luong: ";
        cin >> heSoLuong;
        cout << "Nhap So Nam Kinh Nghiem: ";
        cin >> soNamKinhNghiem;
        themNhanVien(new FullTimeEmployee(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan, heSoLuong, soNamKinhNghiem));
    }
    else if (loai == 2) {
        double soGioLamTuan, mucLuongMoiGio;
        cout << "Nhap So Gio Lam/Tuan: ";
        cin >> soGioLamTuan;
        cout << "Nhap Muc Luong Moi Gio: ";
        cin >> mucLuongMoiGio;
        themNhanVien(new PartTimeEmployee(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan, soGioLamTuan, mucLuongMoiGio));
    }
    else {
        cerr << "Loai nhan vien khong hop le!" << endl;
    }
}

double EmployeeManager::tinhTongLuong() const {
    double tongLuong = 0.0;
    for (const auto& employee : danhSachNhanVien) {
        tongLuong += employee->tinhLuong();
    }
    return tongLuong;
}

int EmployeeManager::demNhanVienTheoNam(int nam) const {
    int soLuong = 0;
    for (const auto& employee : danhSachNhanVien) {
        if (stoi(employee->getNgayVaoLam().substr(0, 4)) == nam) {
            soLuong++;
        }
    }
    return soLuong;
}

void EmployeeManager::capNhatGioLamChoNhanVien(const  string& ma, double soGio) {
    for (auto& employee : danhSachNhanVien) {
        PartTimeEmployee* ptNhanVien = dynamic_cast<PartTimeEmployee*>(employee);
        if (ptNhanVien && ptNhanVien->getMa() == ma) {
            ptNhanVien->setSoGioLamTuan(soGio);
            return;
        }
    }
    cerr << "Khong tim thay nhan vien voi ma: " << ma << endl;
}

void EmployeeManager::sapXepNhanVienTheoNgayVaoLam() {
    sort(danhSachNhanVien.begin(), danhSachNhanVien.end(), [](Employee* a, Employee* b) {
        return a->getNgayVaoLam() > b->getNgayVaoLam();
        });
}

void EmployeeManager::xoaNhanVien(const  string& ma) {
    auto it = remove_if(danhSachNhanVien.begin(), danhSachNhanVien.end(), [&ma](Employee* employee) {
        return employee->getMa() == ma;
        });
    if (it != danhSachNhanVien.end()) {
        delete* it;
        danhSachNhanVien.erase(it, danhSachNhanVien.end());
    }
    else {
        cerr << "Khong tim thay nhan vien voi ma: " << ma << endl;
    }
}

void EmployeeManager::hienThiFullTimeEmployee() const {
    cout << "=============================================Danh sach nhan vien Full Time============================================= " << endl;
    cout << endl;
    cout << setw(10) << left << "Ma"
        << setw(20) << left << "Ho Ten"
        << setw(15) << left << "Ngay Vao Lam"
        << setw(15) << left << "So Dien Thoai"
        << setw(15) << left << "Luong Can Ban"
        << setw(15) << left << "Luong"
        << setw(10) << left << "He So"
        << setw(10) << left << "Kinh Nghiem"
        << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    for (const auto& employee : danhSachNhanVien) {
        FullTimeEmployee* ftemployee = dynamic_cast<FullTimeEmployee*>(employee);
        if (ftemployee)
            /*if (dynamic_cast<FullTimeEmployee*>(employee))*/ {
            cout << setw(10) << left << employee->getMa()
                << setw(20) << left << employee->getHoTen()
                << setw(15) << left << employee->getNgayVaoLam()
                << setw(15) << left << employee->getSoDienThoai()
                << setw(15) << left << employee->getLuongCanBan()
                << setw(15) << left << employee->tinhLuong()
                << setw(15) << left << ftemployee->getHeSoLuong()
                << setw(10) << left << ftemployee->getSoNamKinhNghiem() << "\n";
        }
    }
}

void EmployeeManager::hienThiPartTimeEmployee() const {
    cout << "=============================================Danh sach nhan vien Part Time=============================================" << endl;
    cout << endl;
    cout << setw(10) << left << "Ma"
        << setw(20) << left << "Ho Ten"
        << setw(15) << left << "Ngay Vao Lam"
        << setw(15) << left << "So Dien Thoai"
        << setw(15) << left << "Luong Can Ban"
        << setw(15) << left << "Luong"
        << setw(10) << left << "Gio/Tuan"
        << setw(10) << left << "Luong/Gio"
        << endl;
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    for (const auto& employee : danhSachNhanVien) {
        PartTimeEmployee* ptemployee = dynamic_cast<PartTimeEmployee*>(employee);
        if (ptemployee)
            cout << setw(10) << left << employee->getMa()
            << setw(20) << left << employee->getHoTen()
            << setw(15) << left << employee->getNgayVaoLam()
            << setw(15) << left << employee->getSoDienThoai()
            << setw(15) << left << ptemployee->getLuongCanBan()
            << setw(15) << left << employee->tinhLuong()
            << setw(10) << left << ptemployee->getSoGioLamTuan()
            << setw(10) << left << ptemployee->getMucLuongMoiGio() << "\n";
    }
}


