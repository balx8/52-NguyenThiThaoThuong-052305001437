#pragma once
#include "Employee.h"
using namespace std;

class FullTimeEmployee : public Employee {
private:
    double heSoLuong;
    int soNamKinhNghiem;

public:
    FullTimeEmployee(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCanBan, double heSoLuong, int soNamKinhNghiem);

    // Getters and Setters
    double getHeSoLuong() const;
    void setHeSoLuong(double heSoLuong);

    int getSoNamKinhNghiem() const;
    void setSoNamKinhNghiem(int soNamKinhNghiem);

    double tinhLuong() const override;
};



