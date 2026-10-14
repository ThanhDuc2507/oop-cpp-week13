
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
        cccd = "";
        name = "";
        address = "";
    }

    People(string c, string n, string a) {
        cccd = c;
        name = n;
        address = a;
    }

    string getCccd() const {
        return cccd;
    }

    string getName() const {
        return name;
    }

    string getAddress() const {
        return address;
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
        mssv = "";
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
    cout << "--- People p1 (default) ---" << endl;
    p1.displayInfo();
    cout << endl;

    People p2("079123456789", "Nguyen Van A", "Ho Chi Minh");
    cout << "--- People p2 (parameterized) ---" << endl;
    p2.displayInfo();
    cout << endl;

    Student s1("079123456789", "Tran Thi B",
               "Ha Noi", "SV001", 2023);
    cout << "--- Student s1 ---" << endl;
    s1.displayInfo();
    cout << endl;

    FIEStudent f1("079987654321", "Le Minh C",
                  "Da Nang", "FIE2023001", 2023, 120);
    cout << "--- FIEStudent f1 ---" << endl;
    f1.displayInfo();

    return 0;
}
