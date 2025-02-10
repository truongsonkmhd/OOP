#include <iostream>
#include <cstring>
//Pham Truong Son - DHTI16A3
using namespace std;

class MatHang {
private:
    char mahang[10];
    char tenhang[20];
    float dongia;
public:
    MatHang() {}

    MatHang(char* mahang="", char* tenhang="", float dongia=0) {
        strcpy(this->mahang, mahang);
        strcpy(this->tenhang, tenhang);
        this->dongia = dongia;
    }

    friend istream& operator >> (istream& is, MatHang& mh) {
        cout << "Nhap mat hang:";
        is.getline(mh.mahang, 10);
        cout << "Nhap ten hang:";
        is.getline(mh.tenhang, 20);
        cout << "Nhap don gia:";
        is >> mh.dongia;
        cin.ignore();
        return is;
    }

    float GetDonGia() const {
        return dongia;
    }

    const char* GetMaHang() const {
        return mahang;
    }

    const char* GetTenHang() const {
        return tenhang;
    }
};

class BanhKeo : public MatHang {
private:
    char nsx[30];
public:
    BanhKeo(char* mahang="", char* tenhang="", float dongia=0, char* nsx="") :
        MatHang(mahang, tenhang, dongia) {
        strcpy(this->nsx, nsx);
    }

    float chietKhau() const {
        return GetDonGia() * 1 / 100;
    }

    friend istream& operator >> (istream& is, BanhKeo& bk) {
        MatHang& mh = bk;
        is >> mh;
        cout << "Nhap noi san xuat:";
        is.getline(bk.nsx, 30);
        return is;
    }

    friend ostream& operator << (ostream& os, const BanhKeo& bk) {
        os << "Ma hang:" << bk.GetMaHang() << endl;
        os << "Ten hang:" << bk.GetTenHang() << endl;
        os << "Don gia:" << bk.GetDonGia() << endl;
        os << "Noi san xuat:" << bk.nsx << endl;
        return os;
    }

    const char* GetNSX() const {
        return nsx;
    }
};

void NhapTT(int n, BanhKeo bk[]) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin mat hang [" << i << "]:" << endl;
        cin >> bk[i];
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
}

void XuatTT(int n, const BanhKeo bk[]) {
    for (int i = 0; i < n; i++) {
        cout << "Xuat thong tin mat hang [" << i << "]:" << endl;
        cout << bk[i];
        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    }
}

void MaMO1(int n, const BanhKeo bk[]) {
    cout << "Danh sach mat hang co ma khac MO1 la:\n";
    for (int i = 0; i < n; i++) {
        if (strcmp(bk[i].GetMaHang(), "MO1") != 0) {
            cout << bk[i];
        }
    }
}

void TimKiem(int n, const BanhKeo bk[]) {
    string k;
    cout << "Nhap ma mat hang muon tim:" << endl;
    cin >> k;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(bk[i].GetMaHang(), k.c_str()) == 0) {
            cout << "Ma hang can tim la:" << endl;
            cout << bk[i];
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay!!" << endl;
    }
}

void Dem(int n, const BanhKeo bk[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(bk[i].GetTenHang(), "Banh Ngot") == 0 && strcmp(bk[i].GetNSX(), "Bac Ninh") == 0) {
            count++;
        }
    }
    cout << "So luong mat hang co ten 'banh ngot' va noi san xuat la 'Bac Ninh':" << count << endl;
}

void Sort(int n, BanhKeo bk[]) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (bk[j].GetDonGia() > bk[minIndex].GetDonGia()) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(bk[i], bk[minIndex]);
        }
    }
    cout <<"Sau khi sap xep"<<endl;
    XuatTT(n, bk);
}

int main() {
    int n;
    cout << "Nhap so luong banh keo:";
    cin >> n;
    cin.ignore();
    BanhKeo bk[n];
    NhapTT(n, bk);
    XuatTT(n, bk);
    MaMO1(n, bk);
    TimKiem(n, bk);
    Dem(n, bk);
    Sort(n, bk);
}
