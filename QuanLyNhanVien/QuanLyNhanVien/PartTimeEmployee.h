#pragma once
#include "Employee.h"
using namespace std;
class PartTimeEmployee : public Employee {
private:
    double soGioLamTuan;
    double mucLuongMoiGio;

public:
    PartTimeEmployee(const  string& ma, const  string& hoTen, const  string& ngayVaoLam, const  string& soDienThoai, double luongCanBan, double soGioLamTuan, double mucLuongMoiGio);

    // Getters and Setters
    double getSoGioLamTuan() const;
    void setSoGioLamTuan(double soGioLamTuan);

    double getMucLuongMoiGio() const;
    void setMucLuongMoiGio(double mucLuongMoiGio);

    double tinhLuong() const override;
};



