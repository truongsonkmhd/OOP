#include <iostream>
using namespace std;
//Pham Truong Son - Dhti16a3
class PS {
private:
    int tuSo, mauSo;

public:
    PS(int tuSo = 0, int mauSo = 1) {
        this->tuSo = tuSo;
        this->mauSo = mauSo;
    }

    ~PS() {}

    int getMauSo() { return mauSo; }\

    int getTuSo() { return mauSo; }

    void nhap() {
        cout << "Nhap tu so: ";
        cin >> tuSo;
        do {
            cout << "Nhap mau so: ";
            cin >> mauSo;
            if (mauSo == 0)
                cout << "Mau so phai khac 0. Vui long nhap lai!!" << endl;
        } while (mauSo == 0);
    }

    void in() {
        cout << tuSo << "/" << mauSo << endl;
    }


    int timUCLN(int a, int b) {
        if (b == 0) {
            return a;
        }
        return timUCLN(b, a % b);
    }

    void rutGon() {
        int gcd = timUCLN(tuSo, mauSo);
        tuSo /= gcd;
        mauSo /= gcd;
    }

/* 
// cách 2
void rutGon() {
        int a = tuSo, b = mauSo;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        tuSo /= a;
        mauSo /= a;
    }
*/

    PS operator+(const PS& ps) {
        PS tong;
        tong.tuSo = this->tuSo * ps.mauSo + ps.tuSo * this->mauSo;
        tong.mauSo = this->mauSo * ps.mauSo;
        tong.rutGon();
        return tong;
    }

    PS operator*(const PS& ps) {
        PS tich;
        tich.tuSo = this->tuSo * ps.tuSo;
        tich.mauSo = this->mauSo * ps.mauSo;
        tich.rutGon();
        return tich;
    }
};

void nhap(int n, PS ps[]) {
    for (int i = 0; i < n; i++) {
        ps[i].nhap();
    }
}

void xuat(int n, PS ps[]) {
    for (int i = 0; i < n; i++) {
        cout << "Phan so thu " << i + 1 << " la: ";
        ps[i].in();
    }
}

PS tong(int n, PS ps[]) {
    PS sum = ps[0];
    for (int i = 1; i < n; i++) {
        sum = sum + ps[i];
    }
    return sum;
}

PS nhan(int n, PS ps[]) {
    PS multi = ps[0];
    for (int i = 1; i < n; i++) {
        multi = multi * ps[i];
    }
    return multi;
}


int main() {
    int n;
    cout << "Nhap so luong phan so can tinh toan: ";
    cin >> n;
    PS ps[n];

    nhap(n, ps);
    cout << endl;

    xuat(n, ps);
    cout << endl;

    cout << "Tong phan so la: ";

    PS sum = tong(n, ps);
    if (sum.getMauSo() == 1)
    {
        cout<<sum.getTuSo()<<endl;
    } else {
        sum.in();
    }
    
    cout << "Tich phan so la: ";
    PS multi = nhan(n, ps);
     if (multi.getMauSo() == 1)
    {
        cout<<multi.getTuSo()<<endl;
    } else {
        multi.in();
    }

    return 0;
}

