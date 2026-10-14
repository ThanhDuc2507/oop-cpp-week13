
#include <iostream>
#include <string>
using namespace std;

class People {
private:
    string cccd;
    string name;
    string address;

public:
    People() {
        cccd = "000000000000";
        name = "Unknown";
        address = "Unknown";
    }

    People(string c, string n, string a) {
        cccd = c;
        name = n;
        address = a;
    }

    void displayInfo() const {
        cout << "CCCD: " << cccd << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
    }
};

class Student : public People {
private:
    string mssv;
    int yearEntrance;

public:
    Student() : People() {
        mssv = "N/A";
        yearEntrance = 0;
    }

    Student(string c, string n, string a, string m, int y)
        : People(c, n, a) {
        mssv = m;
        yearEntrance = y;
    }

    void displayInfo() const {
        People::displayInfo();
        cout << "MSSV: " << mssv << endl;
        cout << "Year Entrance: " << yearEntrance << endl;
    }
};

class FIEStudent : public Student {
private:
    int credits;

public:
    FIEStudent() : Student() {
        credits = 0;
    }

    FIEStudent(string c, string n, string a,
               string m, int y, int cr)
        : Student(c, n, a, m, y) {
        credits = cr;
    }

    void displayInfo() const {
        Student::displayInfo();
        cout << "Credits: " << credits << endl;
    }
};

int main() {
    People p1;
    cout << "--- Thong tin doi tuong p1 (People - mac dinh) ---" << endl;
    p1.displayInfo();
    cout << endl;

    People p2("079123456789", "Nguyen Van A", "Ho Chi Minh");
    cout << "--- Thong tin doi tuong p2 (People - co tham so) ---" << endl;
    p2.displayInfo();
    cout << endl;

    Student s1;
    cout << "--- Thong tin doi tuong s1 (Student - mac dinh) ---" << endl;
    s1.displayInfo();
    cout << endl;

    Student s2("079123456789", "Tran Thi B", "Ha Noi", "SV001", 2023);
    cout << "--- Thong tin doi tuong s2 (Student - co tham so) ---" << endl;
    s2.displayInfo();
    cout << endl;

    FIEStudent f1;
    cout << "--- Thong tin doi tuong f1 (FIEStudent - mac dinh) ---" << endl;
    f1.displayInfo();
    cout << endl;

    FIEStudent f2("079987654321", "Le Minh C", "Da Nang",
                  "FIE2023001", 2023, 120);
    cout << "--- Thong tin doi tuong f2 (FIEStudent - co tham so) ---" << endl;
    f2.displayInfo();
    cout << endl;

    return 0;
}
