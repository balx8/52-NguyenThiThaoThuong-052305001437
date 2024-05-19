#include "FullTimeEmployee.h"
using namespace std;

// Constructor
FullTimeEmployee::FullTimeEmployee(const std::string& ma, const std::string& hoTen, const std::string& ngayVaoLam, const std::string& soDienThoai, double luongCanBan, double heSoLuong, int soNamKinhNghiem)
    : Employee(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan), heSoLuong(heSoLuong), soNamKinhNghiem(soNamKinhNghiem) {
    if (heSoLuong < 1.65 || heSoLuong > 8.00) {
        throw std::invalid_argument("He so luong phai tu 1.65 den 8.00");
    }
    if (soNamKinhNghiem < 0) {
        throw std::invalid_argument("So nam kinh nghiem phai >= 0");
    }
}

// Getters and Setters
double FullTimeEmployee::getHeSoLuong() const { return heSoLuong; }
void FullTimeEmployee::setHeSoLuong(double heSoLuong) {
    if (heSoLuong < 1.65 || heSoLuong > 8.00) {
        throw std::invalid_argument("He so luong phai tu 1.65 den 8.00");
    }
    this->heSoLuong = heSoLuong;
}

int FullTimeEmployee::getSoNamKinhNghiem() const { return soNamKinhNghiem; }
void FullTimeEmployee::setSoNamKinhNghiem(int soNamKinhNghiem) {
    if (soNamKinhNghiem < 0) {
        throw std::invalid_argument("So nam kinh nghiem phai >= 0");
    }
    this->soNamKinhNghiem = soNamKinhNghiem;
}

double FullTimeEmployee::tinhLuong() const {
    double luongTheoHeSo = luongCanBan * heSoLuong;
    return luongTheoHeSo + (soNamKinhNghiem * 0.05 * luongTheoHeSo);
}

