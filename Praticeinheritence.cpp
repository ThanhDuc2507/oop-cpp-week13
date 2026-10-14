
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string cccd;
    string sdt;
    string address;

public:
    Employee() {
        cccd = "";
        sdt = "";
        address = "";
    }

    Employee(string c, string p, string a) {
        cccd = c;
        sdt = p;
        address = a;
    }

    string getCCCD() const {
        return cccd;
    }

    string getSDT() const {
        return sdt;
    }

    string getAddress() const {
        return address;
    }

    void setCCCD(string c) {
        cccd = c;
    }

    void setSDT(string p) {
        sdt = p;
    }

    void setAddress(string a) {
        address = a;
    }
};

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee() : Employee() {
        soGioLamViec = 0;
        donGia = 0.0;
    }

    HourlyEmployee(string c, string p, string a,
                   int soGio, double dg)
        : Employee(c, p, a) {
        soGioLamViec = soGio;
        donGia = dg;
    }

    int getSoGioLamViec() const {
        return soGioLamViec;
    }

    double getDonGia() const {
        return donGia;
    }

    void setSoGioLamViec(int g) {
        soGioLamViec = g;
    }

    void setDonGia(double dg) {
        donGia = dg;
    }
};

class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee() : Employee() {
        luongCoBan = 0.0;
        phuCap = 0.0;
        heSoThuong = 0.0;
    }

    MonthlyEmployee(string c, string p, string a,
                    double lcb, double pc, double hs)
        : Employee(c, p, a) {
        luongCoBan = lcb;
        phuCap = pc;
        heSoThuong = hs;
    }

    double getLuongCoBan() const {
        return luongCoBan;
    }

    double getPhuCap() const {
        return phuCap;
    }

    double getHeSoThuong() const {
        return heSoThuong;
    }

    void setLuongCoBan(double lcb) {
        luongCoBan = lcb;
    }

    void setPhuCap(double pc) {
        phuCap = pc;
    }

    void setHeSoThuong(double hs) {
        heSoThuong = hs;
    }
};

int main() {
    Employee e1;

    HourlyEmployee h1(
        "079123456789",
        "0901002003",
        "Ha Noi",
        160,
        50000
    );

    MonthlyEmployee m1(
        "079987654321",
        "0903004005",
        "Da Nang",
        15000000,
        2000000,
        1.2
    );

    cout << "--- Employee e1 ---" << endl;
    cout << "CCCD: " << e1.getCCCD() << endl;
    cout << "SDT: " << e1.getSDT() << endl;
    cout << "Address: " << e1.getAddress() << endl;
    cout << endl;

    cout << "--- HourlyEmployee h1 ---" << endl;
    cout << "CCCD: " << h1.getCCCD() << endl;
    cout << "SDT: " << h1.getSDT() << endl;
    cout << "Address: " << h1.getAddress() << endl;
    cout << "So gio lam viec: " << h1.getSoGioLamViec() << endl;
    cout << "Don gia: " << h1.getDonGia() << endl;
    cout << endl;

    cout << "--- MonthlyEmployee m1 ---" << endl;
    cout << "CCCD: " << m1.getCCCD() << endl;
    cout << "SDT: " << m1.getSDT() << endl;
    cout << "Address: " << m1.getAddress() << endl;
    cout << "Luong co ban: " << m1.getLuongCoBan() << endl;
    cout << "Phu cap: " << m1.getPhuCap() << endl;
    cout << "He so thuong: " << m1.getHeSoThuong() << endl;

    return 0;
}
