#pragma once
#include "Employee.h"
#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class EmployeeManager {
private:
    vector<Employee*> danhSachNhanVien;

public:
    ~EmployeeManager();

    void themNhanVien(Employee* nhanVien);
    void themNhanVienMau();
    void nhapNhanVienTuBanPhim();
    double tinhTongLuong() const;
    int demNhanVienTheoNam(int nam) const;
    void capNhatGioLamChoNhanVien(const string& ma, double soGio);
    void sapXepNhanVienTheoNgayVaoLam();
    void xoaNhanVien(const string& ma);
    void hienThiFullTimeEmployee() const;
    void hienThiPartTimeEmployee() const;
};

