#include<iostream>
#include<cstring>
#include<ctime>
#include<algorithm>
using namespace std;
//Pham Truong Son - DHTIN16A3

class HangHoa {
private:
    char maHang[20];
    char tenHang[15];
    float donGia;

public:
    HangHoa(const char* maHang = "", const char* tenHang = "", int donGia = 1) {
        strcpy(this->maHang, maHang);
        strcpy(this->tenHang, tenHang);
        this->donGia = donGia;
    }
    
    ~HangHoa() {}

    void nhap() {  
        cout << "Nhap ma hang: ";
        cin.ignore();
        cin.getline(maHang, 20);
        cout << "Nhap ten hang: ";
        cin.getline(tenHang, 15);
        cout << "Nhap don gia: ";
        cin >> donGia;
    }

    void in() const {
        cout << "- ma hang: " << maHang << endl;
        cout << "- ten hang: " << tenHang << endl;
        cout << "- don gia: " << donGia << endl;
    }

    float getDonGia() const {
        return donGia;
    }
    
    const char* getMaHang() const {
        return maHang;
    }
    
    const char* getTenHang() const {
        return tenHang;
    }   

    bool operator < (const HangHoa& hh) const {
        return strcmp(this->maHang, hh.getMaHang()) < 0;
    }
};

class MayTinh : public HangHoa {
private:
    float tocDo;
    int soLuongMay;

public:
    MayTinh(const char* maHang = "", const char* tenHang = "", int donGia = 1,float tocDo = 0.0, int soLuong = 0)
        : HangHoa(maHang, tenHang, donGia), tocDo(tocDo), soLuongMay(soLuong) {}

    ~MayTinh() {}

    friend istream& operator >> (istream& is, MayTinh& mt) {
        mt.nhap();
        cout << "- Nhap toc do: ";
        is >> mt.tocDo;
        cout << "- Nhap so luong: ";
        is >> mt.soLuongMay;
        return is;
    }
    
    float thanhTien(){
        return soLuongMay * getDonGia();
    }

    friend ostream& operator << (ostream& os, const MayTinh& mt) {
        mt.in();
        os << "toc do la: " << mt.tocDo << endl;
        os << "so luong: " << mt.soLuongMay << endl;
        return os;
    }
    
    int getSoLuong() const {
        return soLuongMay;
    }

    float getTocDo() const {
        return tocDo;
    }

    bool operator < (const MayTinh& mt) const {
        return this->getSoLuong() < mt.getSoLuong();
    }
};

class MayTinhXT : public MayTinh {
private:
    float trongLuong;
public:
    MayTinhXT(float trongLuong = 0.0,const char* maHang = "", const char* tenHang = "", int donGia = 1,float tocDo = 0.0, int soLuong = 0)
        : MayTinh(maHang, tenHang, donGia, tocDo, soLuong), trongLuong(trongLuong) {}

    ~MayTinhXT() {}

    friend istream& operator >> (istream& is, MayTinhXT& mtxt) {
    	//chuyen doi mtxt thanh mot tham chieu den doi tuong may tinh 
        is >> static_cast<MayTinh&>(mtxt);
        cout << "- Nhap trong luong: ";
        is >> mtxt.trongLuong;
        return is;
    }
    
    float phiBaoTri() const{
        return 0.05*getDonGia();
    }

    friend ostream& operator << (ostream& os, const MayTinhXT& mtxt) {
        mtxt.in();
        os << "Trong Luong: " << mtxt.trongLuong << endl;
        return os;
    }
};
void inputMTXT(MayTinhXT mtxt[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin may tinh xt thu" << i + 1 << " : " << endl;
        cin >> mtxt[i];
        cout << "---------------------------------------" << endl;
    }
}

void outputMTXT(MayTinhXT mtxt[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin may tinh xt thu " << i + 1 << " : " << endl;
        cout << mtxt[i];
        cout << "---------------------------------------" << endl;
    }
}

void timMayTinhXachTayTheoMa(const MayTinhXT mtxt[], int n) {
    char maTim[20];
    cout << "Nhap ma may can tim: ";
    cin.ignore();
    cin.getline(maTim, 20);
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(mtxt[i].getMaHang(), maTim) == 0) {
            cout << "Tim thay may tinh xach tay:\n";
            mtxt[i].in();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay may tinh xach tay voi ma " << maTim << endl;
}

void lietKeMayTinhXTTheoTen(const MayTinhXT mtxt[], int n) {
    char tenTim[15];
    cout << "Nhap ten can tim: ";
    cin.ignore();
    cin.getline(tenTim, 15);
    cout << "Cac may tinh xach tay co ten '" << tenTim << "':\n";
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(mtxt[i].getTenHang(), tenTim) == 0) {
            mtxt[i].in();
            found = true;
        }
    }
    if (!found)
        cout << "Khong tim thay may tinh xach tay voi ten " << tenTim << endl;
}

int tinhTongPhiBaoTri(const MayTinhXT mtxt[], int n) {
    float tongPhi = 0;
    for (int i = 0; i < n; ++i) {
        tongPhi += mtxt[i].phiBaoTri();
    }
    return tongPhi;
}

void timMayTinhXachTayCoTocDoNhoNhat(const MayTinhXT mtxt[], int n) {
    float tocDoMin = mtxt[0].getTocDo();
    int indexMin = 0;
    for (int i = 1; i < n; ++i) {
        if (mtxt[i].getTocDo() < tocDoMin) {
            tocDoMin = mtxt[i].getTocDo();
            indexMin = i;
        }
    }
    cout << "May tinh xach tay co toc do nho nhat la:\n";
    mtxt[indexMin].in();
    cout<<"Toc do nho nhat la:"<<mtxt[indexMin].getTocDo();
}

void suaThongTinMayTinhXT(MayTinhXT mtxt[], int n) {
    char maSua[20];
    cout << "Nhap ma may tinh can sua: ";
    cin.ignore();
    cin.getline(maSua, 20);
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(mtxt[i].getMaHang(), maSua) == 0) {
            cout << "Thong tin hien tai cua may tinh:\n";
            mtxt[i].in();
            cout << "Nhap thong tin moi cho may tinh:\n";
            mtxt[i].nhap();
            found = true;
            cout << "Da sua thong tin thanh cong.\n";
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay may tinh xach tay voi ma " << maSua << endl;
}

void xoaMayTinhXTTheoMa(MayTinhXT mtxt[], int& n) {
    char maXoa[20];
    cout << "Nhap ma may tinh can xoa: ";
    cin.ignore();
    cin.getline(maXoa, 20);
    bool found = false;
    for (int i = 0; i < n; ++i) {
        if (strcmp(mtxt[i].getMaHang(), maXoa) == 0) {
            found = true;
            for (int j = i; j < n - 1; ++j) {
                mtxt[j] = mtxt[j + 1];
            }
            n--;
            cout << "Da xoa may tinh xach tay co ma " << maXoa << endl;
            break;
        }
    }
    if (!found)
        cout << "Khong tim thay may tinh xach tay voi ma " << maXoa << endl;
}

void chenMayTinhXT(MayTinhXT mtxt[], int& n, int k) {
    if (k < 0 || k > n) {
        cout << "Vi tri chen khong hop le.\n";
        return;
    }
    MayTinhXT newMTXT;
    cout << "Nhap thong tin may tinh xach tay moi:\n";
    newMTXT.nhap();
    for (int i = n; i > k; --i) {
        mtxt[i] = mtxt[i - 1];
    }
    mtxt[k] = newMTXT;
    n++;
    cout << "Da chen them may tinh xach tay tai vi tri " << k << endl;
}

void sapXepTheoMaMay(MayTinhXT mtxt[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(mtxt[i].getMaHang(), mtxt[j].getMaHang()) > 0) {
                swap(mtxt[i], mtxt[j]);
            }
        }
    }
    cout << "Da sap xep danh sach theo chieu tang dan cua ma may.\n";
}

int main() {
    int n;
    do {
        cout << "Nhap so may tinh xach tay n = ";
        cin >> n;
        cin.ignore();
    } while (n <= 0);
    
    MayTinhXT mayTinhXTs[n+5];

    int choice;
    do {
        cout << "\n1. Nhap danh sach may tinh xt, hien thi danh sach\n";
        cout << "2. Tim Thong tin may tinh xach tay theo ma may nhap vao tu ban phim\n";
        cout << "3. Liet ke may tinh xach tay theo ten\n";
        cout << "4. Tinh Tong phi bao tri cua may tinh\n";
        cout << "5. Tim may tinh xach tay co toc do nho nhat\n";
        cout << "6. Sua thong tin mot may tinh xach tay\n";
        cout << "7. Xoa mot may tinh xach tay theo ma cho truoc\n";
        cout << "8. Chen them mot may tinh xach tay tai vi tri k\n";
        cout << "9. Sap xep danh sach theo chieu tang dan cua ma may\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "NHAP DANH SACH MAY TINH XT:\n";
                inputMTXT(mayTinhXTs, n);
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "IN DANH SACH MAY TINH XT:\n";
                outputMTXT(mayTinhXTs, n);
                break;
            case 2:
                timMayTinhXachTayTheoMa(mayTinhXTs, n);
                break;
            case 3:
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                lietKeMayTinhXTTheoTen(mayTinhXTs, n);
                break;
            case 4:
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "Tong phi bao tri cua cac may tinh la: " << tinhTongPhiBaoTri(mayTinhXTs, n) << endl;
                break;
            case 5:
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                timMayTinhXachTayCoTocDoNhoNhat(mayTinhXTs, n);
                break;
            case 6:
                cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                suaThongTinMayTinhXT(mayTinhXTs, n);
                cout<< "\n========= DANH SACH MAY TINH SAU KHI SUA LA: =========\n";
                break;
            case 7:
                xoaMayTinhXTTheoMa(mayTinhXTs, n);
                cout<<"\n========= DANH SACH MAY TINH SAU KHI XOA LA :========= \n";
                inputMTXT(mayTinhXTs, n);
                break;
            case 8:
                int vitriChen;
                cout << "Nhap vi tri can chen: ";
                cin >> vitriChen;
                chenMayTinhXT(mayTinhXTs, n, vitriChen);
                cout<<"\n========= DANH SACH SAU KHI CHEN LA :============ \n";
                inputMTXT(mayTinhXTs, n);
                break;
            case 9:
                sapXepTheoMaMay(mayTinhXTs, n);
                cout<<"\n========= DANH SACH MAY TINH SAU KHI SAP XEP LA :========= \n";
                inputMTXT(mayTinhXTs, n);
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long nhap lai.\n";
        }

    } while (choice != 0);

    return 0;
}
// Pham Truong Son - Dhti16a3

