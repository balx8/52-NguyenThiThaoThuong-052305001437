#include "PartTimeEmployee.h"

// Constructor
PartTimeEmployee::PartTimeEmployee(const std::string& ma, const std::string& hoTen, const std::string& ngayVaoLam, const std::string& soDienThoai, double luongCanBan, double soGioLamTuan, double mucLuongMoiGio)
    : Employee(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan), soGioLamTuan(soGioLamTuan), mucLuongMoiGio(mucLuongMoiGio) {
    if (soGioLamTuan < 0 || mucLuongMoiGio < 0) {
        throw std::invalid_argument("So gio lam tuan va muc luong moi gio phai >= 0");
    }
}

// Getters and Setters
double PartTimeEmployee::getSoGioLamTuan() const { return soGioLamTuan; }
void PartTimeEmployee::setSoGioLamTuan(double soGioLamTuan) {
    if (soGioLamTuan < 0) {
        throw std::invalid_argument("So gio lam tuan phai >= 0");
    }
    this->soGioLamTuan = soGioLamTuan;
}

double PartTimeEmployee::getMucLuongMoiGio() const { return mucLuongMoiGio; }
void PartTimeEmployee::setMucLuongMoiGio(double mucLuongMoiGio) {
    if (mucLuongMoiGio < 0) {
        throw std::invalid_argument("Muc luong moi gio phai >= 0");
    }
    this->mucLuongMoiGio = mucLuongMoiGio;
}

double PartTimeEmployee::tinhLuong() const {
    double luongSanPham = soGioLamTuan * mucLuongMoiGio;
    if (soGioLamTuan > 40) {
        luongSanPham += (soGioLamTuan - 40) * mucLuongMoiGio * 0.5;
    }
    return luongCanBan * 0.3 + luongSanPham;
}

