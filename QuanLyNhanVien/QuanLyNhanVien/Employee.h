#pragma once
#include <string>
#include <stdexcept>
#include <ctime>
using namespace std;

class Employee {
protected:
    string ma;
    string hoTen;
    string ngayVaoLam;
    string soDienThoai;
    double luongCanBan;

    bool kiemTraSoDienThoaiHopLe(const  string& sdt) {
        return sdt.length() == 10 && sdt[0] == '0';
    }

    bool kiemTraNgayVaoLamHopLe(const  string& ngay);

public:
    Employee(const  string& ma, const  string& hoTen, const  string& ngayVaoLam, const  string& soDienThoai, double luongCanBan);

    // Getters and Setters
    string getMa() const;
    void setMa(const  string& ma);

    string getHoTen() const;
    void setHoTen(const  string& hoTen);

    string getNgayVaoLam() const;
    void setNgayVaoLam(const  string& ngayVaoLam);

    string getSoDienThoai() const;
    void setSoDienThoai(const  string& soDienThoai);

    double getLuongCanBan() const;
    void setLuongCanBan(double luongCanBan);

    virtual double tinhLuong() const = 0;
};



