#include<iostream>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
//Pham Truong Son - DHTIN16A3

class MyDate {
private:
    int day;
    int month;
    int year;

public:
    MyDate(int day = 0, int month = 0, int year = 0) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    ~MyDate() {}

    void nhap() {
        cout << "Nhap day: ";
        cin >> day;
        cout << "Nhap month: ";
        cin >> month;
        cout << "Nhap year: ";
        cin >> year;
    }

    void in() {
        cout << "- day: " << day << endl;
        cout << "- month: " << month << endl;
        cout << "- year: " << year << endl;
    }

    int getYear() {
        return year;
    }

    bool operator > (MyDate md) {
        return (year > md.getYear());
    }
};

class Person {
private:
    char name[50];
    char address[50];
    long int phone;
    MyDate birthdate;

public:
    Person(const char* name = "", const char* address = "", long int phone = 1, MyDate birthdate = MyDate())
        : birthdate(birthdate) {
        strcpy(this->name, name);
        strcpy(this->address, address);
        this->phone = phone;
    }

    ~Person() {}

    friend istream& operator >> (istream& is, Person& ps) {
        ps.birthdate.nhap();
        cout << "- Nhap name: ";
        cin.ignore();
        is.getline(ps.name, 50);
        cout << "- Nhap address: ";
        is.getline(ps.address, 50);
        cout << "- Nhap phone: ";
        is >> ps.phone;
        return is;
    }

    friend ostream& operator << (ostream& os, Person& ps) {
        ps.birthdate.in();
        os << "Name: " << ps.name << endl;
        os << "Address: " << ps.address << endl;
        os << "Phone: " << ps.phone << endl;
        return os;
    }

    bool operator > (Person& p) {
        return (birthdate > p.birthdate);
    }
};

void inputPerson(Person ps[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin person " << i + 1 << " : " << endl;
        cin >> ps[i];
        cout << "---------------------------------------" << endl;
    }
}

void outputPerson(Person ps[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin benh an thu " << i + 1 << " : " << endl;
        cout << ps[i];
        cout << "---------------------------------------" << endl;
    }
}

void sapXepTangDan(Person ps[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (ps[i] > ps[j])
                swap(ps[i], ps[j]);
}

int main() {
    Person ps[50];
    int n;
    do {
        cout << "Nhap so person n = ";
        cin >> n;
        cin.ignore();
    } while (n <= 0);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "NHAP DANH SACH PERSON:\n";
    inputPerson(ps, n);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "IN DANH SACH BENH AN:\n";
    outputPerson(ps, n);

    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << "IN DANH SACH TRUONG DAI HOC THEO THU TU GIAM DAN SO TUOI:\n";
    sapXepTangDan(ps, n);
    outputPerson(ps, n);

    return 0;
}

