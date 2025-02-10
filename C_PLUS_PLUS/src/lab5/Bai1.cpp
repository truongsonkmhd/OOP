#include <iostream>
#include <cstring>
using namespace std;

class MonHoc {
private:
    char *tenMonHoc;
    int soTiet;

public:
    MonHoc() {
        tenMonHoc = NULL;
		soTiet = 0;
    }

    MonHoc(char* ten, int st) {
        int n = strlen(ten);
        tenMonHoc = new char[n+1];
        strcpy(tenMonHoc, ten);
        soTiet = st;
    }

    ~MonHoc() {
        if(tenMonHoc != NULL) {
			delete tenMonHoc;
			soTiet = 0;
		}
    }

    void hienThiMonHoc() {
        cout << "Ten mon hoc: " << tenMonHoc << endl;
        cout << "So tiet: " << soTiet << endl;
    }
};

class Nguoi {
private:
    char *hoTen;
    int namSinh;

public:
    Nguoi() {
    }

    Nguoi(char* ten, int ns) {
        int n = strlen(ten);
        hoTen = new char[n+1];
        strcpy(hoTen, ten);
        namSinh = ns;
    }

    ~Nguoi() {
    }

    void hienThiNguoi() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;
    }
};

class GiaoVien : public MonHoc, public Nguoi {
private:
    char *boMon;
public:
    GiaoVien(): MonHoc(), Nguoi() {
        boMon = NULL;
    }

    GiaoVien(char* ten, int ns, char* tenMH, int st, char* bm) : Nguoi(ten, ns), MonHoc(tenMH, st) {
        int n = strlen(bm);
        boMon = new char[n+1];
        strcpy(boMon, bm);
    }

    ~GiaoVien() {
        if(boMon != NULL) {
			delete boMon;
		}
    }

    void hienThiGiaoVien() {
        Nguoi::hienThiNguoi();
        MonHoc::hienThiMonHoc();
        cout << "Bo mon: " << boMon << endl;
    }
};

int main() {
    GiaoVien *gv;
    gv = new GiaoVien("Nguyen Van A", 1970, "CNTT", 40, "Tin hoc");
    gv->hienThiGiaoVien();
    delete gv;
    return 0;
}
