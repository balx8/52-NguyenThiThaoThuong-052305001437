#include "Employee.h"
#include <regex>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

// Constructor
Employee::Employee(const  string& ma, const  string& hoTen, const  string& ngayVaoLam, const  string& soDienThoai, double luongCanBan)
    : ma(ma), hoTen(hoTen), ngayVaoLam(ngayVaoLam), soDienThoai(soDienThoai), luongCanBan(luongCanBan) {
    if (!kiemTraSoDienThoaiHopLe(soDienThoai)) {
        throw  invalid_argument("So dien thoai khong hop le");
    }
    if (!kiemTraNgayVaoLamHopLe(ngayVaoLam)) {
        throw  invalid_argument("Ngay vao lam khong hop le");
    }
    if (luongCanBan < 0) {
        throw  invalid_argument("Luong can ban phai >= 0");
    }
}

// Getters and Setters
string Employee::getMa() const { return ma; }
void Employee::setMa(const  string& ma) { this->ma = ma; }

string Employee::getHoTen() const { return hoTen; }
void Employee::setHoTen(const  string& hoTen) { this->hoTen = hoTen; }

string Employee::getNgayVaoLam() const { return ngayVaoLam; }
void Employee::setNgayVaoLam(const  string& ngayVaoLam) {
    if (!kiemTraNgayVaoLamHopLe(ngayVaoLam)) {
        throw  invalid_argument("Ngay vao lam khong hop le");
    }
    this->ngayVaoLam = ngayVaoLam;
}

string Employee::getSoDienThoai() const { return soDienThoai; }
void Employee::setSoDienThoai(const  string& soDienThoai) {
    if (!kiemTraSoDienThoaiHopLe(soDienThoai)) {
        throw  invalid_argument("So dien thoai khong hop le");
    }
    this->soDienThoai = soDienThoai;
}

double Employee::getLuongCanBan() const { return luongCanBan; }
void Employee::setLuongCanBan(double luongCanBan) {
    if (luongCanBan < 0) {
        throw  invalid_argument("Luong can ban phai >= 0");
    }
    this->luongCanBan = luongCanBan;
}

// Validation Methods
bool Employee::kiemTraNgayVaoLamHopLe(const  string& ngay) {
    tm tm = {};
    istringstream ss(ngay);
    ss >> get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        return false;
    }
    time_t start_time = mktime(&tm);
    time_t current_time = time(nullptr);
    return start_time <= current_time;
}

