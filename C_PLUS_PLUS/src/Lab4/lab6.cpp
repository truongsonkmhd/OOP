#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//Pham Truong Son - DHTIN16A3

using namespace std;

class PET
{
private:
    int tuoi;
    float canNang;

public:
    PET(int tuoi = 0, float canNang = 0.0) : tuoi(tuoi), canNang(canNang) {}

    virtual ~PET() {}

    virtual void nhap()
    {
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap can nang: ";
        cin >> canNang;
    }

    virtual void xuat() const
    {
        cout << "Tuoi: " << tuoi << endl;
        cout << "Can nang: " << canNang << " kg" << endl;
    }

    float getCanNang() const
    {
        return canNang;
    }

    int getTuoi() const
    {
        return tuoi;
    }
};

class Dog : public PET
{
private:
    string mauMat;
    string soThich;

public:
    Dog(int tuoi = 0, float canNang = 0.0, string mauMat = "", string soThich = "")
        : PET(tuoi, canNang), mauMat(mauMat), soThich(soThich) {}

    void nhap() override
    {
        PET::nhap();
        cout << "Nhap mau mat: ";
        cin.ignore();
        getline(cin, mauMat);
        cout << "Nhap so thich: ";
        getline(cin, soThich);
    }

    void xuat() const override
    {
        PET::xuat();
        cout << "Mau mat: " << mauMat << endl;
        cout << "So thich: " << soThich << endl;
    }
};

void nhapDanhSachDog(Dog dogs[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << "Nhap thong tin cho con Dog thu " << i + 1 << endl;
        dogs[i].nhap();
    }
}

void xuatDanhSachDog(const Dog dogs[], int n)
{
    cout << "Danh sach cac con Dog:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << "Thong tin cho con Dog thu " << i + 1 << ":" << endl;
        dogs[i].xuat();
        cout << endl;
    }
}

void sapXepTheoCanNang(Dog dogs[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (dogs[i].getCanNang() > dogs[j].getCanNang())
                swap(dogs[i], dogs[j]);
}

void timDogTheoTuoi(const Dog dogs[], int n, int a, int b)
{
    cout << "Cac con Dog co tuoi tu " << a << " den " << b << " la:\n";
    for (int i = 0; i < n; ++i)
    {
        int tuoi = dogs[i].getTuoi();
        if (tuoi >= a && tuoi <= b)
        {
            dogs[i].xuat();
            cout << endl;
        }
    }
}

float tinhTongCanNang(const Dog dogs[], int n)
{
    float tongCanNang = 0;
    for (int i = 0; i < n; ++i)
    {
        tongCanNang += dogs[i].getCanNang();
    }
    return tongCanNang;
}

int main()
{
    int n;
    cout << "Nhap so luong con Dog: ";
    cin >> n;
    Dog dogs[n+4];

    nhapDanhSachDog(dogs, n);
    xuatDanhSachDog(dogs, n);

    sapXepTheoCanNang(dogs, n);
    cout << "Danh sach Dog sau khi sap xep theo can nang tang dan:\n";
    xuatDanhSachDog(dogs, n);

    int a, b;
    cout << "Nhap do tuoi bat dau: ";
    cin >> a;
    cout << "Nhap do tuoi ket thuc: ";
    cin >> b;
    timDogTheoTuoi(dogs, n, a, b);

    cout << "Tong can nang cua cac con Dog: " << tinhTongCanNang(dogs, n) << " kg" << endl;

    return 0;
}

