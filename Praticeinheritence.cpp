#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Employee {
protected:
    string cccd;
    string sdt;
    string address;

public:
    Employee() : cccd(""), sdt(""), address("") {}

    Employee(string c, string s, string a) : cccd(c), sdt(s), address(a) {}

    virtual void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "SDT: " << sdt << endl;
        cout << "Address: " << address << endl;
    }

    virtual double tinhLuong() const {
        return 0;
    }

    string getCCCD() const { return cccd; }
    string getSDT() const { return sdt; }
    string getAddress() const { return address; }

    void setCCCD(string c) { cccd = c; }
    void setSDT(string s) { sdt = s; }
    void setAddress(string a) { address = a; }

    virtual ~Employee() {}
};

class HourlyEmployee : public Employee {
private:
    int soGioLamViec;
    double donGia;

public:
    HourlyEmployee() : Employee(), soGioLamViec(0), donGia(0) {}

    HourlyEmployee(string c, string s, string a, int soGio, double donGia)
        : Employee(c, s, a), soGioLamViec(soGio), donGia(donGia) {}

    double tinhLuong() const override {
        return soGioLamViec * donGia;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "So gio lam viec: " << soGioLamViec << endl;
        cout << "Don gia: " << fixed << setprecision(0) << donGia << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    int getSoGioLamViec() const { return soGioLamViec; }
    double getDonGia() const { return donGia; }

    void setSoGioLamViec(int g) { soGioLamViec = g; }
    void setDonGia(double dg) { donGia = dg; }
};

class MonthlyEmployee : public Employee {
private:
    double luongCoBan;
    double phuCap;
    double heSoThuong;

public:
    MonthlyEmployee() : Employee(), luongCoBan(0), phuCap(0), heSoThuong(0) {}

    MonthlyEmployee(string c, string s, string a, double lcb, double pc, double hs)
        : Employee(c, s, a), luongCoBan(lcb), phuCap(pc), heSoThuong(hs) {}

    double tinhLuong() const override {
        return luongCoBan + phuCap + (luongCoBan * heSoThuong);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << "Luong co ban: " << fixed << setprecision(0) << luongCoBan << endl;
        cout << "Phu cap: " << phuCap << endl;
        cout << "He so thuong: " << setprecision(1) << heSoThuong << endl;
        cout << "Luong: " << setprecision(0) << tinhLuong() << endl;
    }

    double getLuongCoBan() const { return luongCoBan; }
    double getPhuCap() const { return phuCap; }
    double getHeSoThuong() const { return heSoThuong; }

    void setLuongCoBan(double lcb) { luongCoBan = lcb; }
    void setPhuCap(double pc) { phuCap = pc; }
    void setHeSoThuong(double hs) { heSoThuong = hs; }
};

int main() {
    cout << "=== VÍ DỤ TRONG ĐỀ BÀI ===" << endl;
    Employee e1("079123456789", "079123456789", "Ho Chi Minh");
    HourlyEmployee h1("079876543210", "079876543210", "Ha Noi", 160, 50000);
    MonthlyEmployee m1("079987654321", "079987654321", "Da Nang", 15000000, 2000000, 1.2);

    cout << "--- Thong tin Employee ---" << endl;
    e1.displayInfo();

    cout << "\n--- Thong tin HourlyEmployee ---" << endl;
    h1.displayInfo();

    cout << "\n--- Thong tin MonthlyEmployee ---" << endl;
    m1.displayInfo();

    cout << "\n==========================================" << endl;
    cout << "=== THỰC HÀNH CÁC BÀI TẬP MỞ RỘNG ===" << endl;

    vector<Employee*> danhSach;
    danhSach.push_back(new HourlyEmployee("001", "0901111111", "Ha Noi", 160, 50000));
    danhSach.push_back(new MonthlyEmployee("002", "0902222222", "Da Nang", 15000000, 2000000, 1.2));
    danhSach.push_back(new HourlyEmployee("003", "0903333333", "TPHCM", 120, 60000));
    danhSach.push_back(new MonthlyEmployee("004", "0904444444", "Can Tho", 10000000, 1000000, 0.5));

    double tongLuong = 0;
    for (const auto& emp : danhSach) {
        tongLuong += emp->tinhLuong();
    }
    cout << "\n1. Tong quy luong cua tat ca nhan vien: " << fixed << setprecision(0) << tongLuong << " VND" << endl;

    if (!danhSach.empty()) {
        Employee* maxEmp = danhSach[0];
        Employee* minEmp = danhSach[0];

        for (const auto& emp : danhSach) {
            if (emp->tinhLuong() > maxEmp->tinhLuong()) maxEmp = emp;
            if (emp->tinhLuong() < minEmp->tinhLuong()) minEmp = emp;
        }

        cout << "\n2. Nhan vien co luong CAO NHAT (" << maxEmp->tinhLuong() << " VND):" << endl;
        maxEmp->displayInfo();

        cout << "\n3. Nhan vien co luong THẤP NHẤT (" << minEmp->tinhLuong() << " VND):" << endl;
        minEmp->displayInfo();
    }

    int countHourly = 0;
    int countMonthly = 0;
    for (const auto& emp : danhSach) {
        if (dynamic_cast<HourlyEmployee*>(emp) != nullptr) {
            countHourly++;
        } else if (dynamic_cast<MonthlyEmployee*>(emp) != nullptr) {
            countMonthly++;
        }
    }
    cout << "\n4. Thong ke so luong nhan vien:" << endl;
    cout << "   - So nhan vien theo gio (HourlyEmployee): " << countHourly << endl;
    cout << "   - So nhan vien theo thang (MonthlyEmployee): " << countMonthly << endl;

    double luongNguoiDungNhap = 10000000;
    cout << "\n5. Danh sach nhan vien co luong > " << luongNguoiDungNhap << " VND:" << endl;
    for (const auto& emp : danhSach) {
        if (emp->tinhLuong() > luongNguoiDungNhap) {
            cout << "------------------------------------------" << endl;
            emp->displayInfo();
        }
    }

    sort(danhSach.begin(), danhSach.end(), [](Employee* a, Employee* b) {
        return a->tinhLuong() > b->tinhLuong();
    });

    cout << "\n6. Danh sach nhan vien sau khi SAP XEP LUONG GIAM DAN:" << endl;
    for (size_t i = 0; i < danhSach.size(); ++i) {
        cout << "\n--- Nhan vien " << i + 1 << " (Luong: " << danhSach[i]->tinhLuong() << " VND) ---" << endl;
        danhSach[i]->displayInfo();
    }

    for (auto emp : danhSach) {
        delete emp;
    }
    danhSach.clear();

    return 0;
}