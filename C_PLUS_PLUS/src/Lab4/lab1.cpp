#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
//Pham Truong Son - DHTIN16A3
class BenhNhan {
private:
    char ten[20];
    char queQuan[15];
    int namSinh;

public:
    BenhNhan(const char* ten = "", const char* queQuan = "", int namSinh = 1) {
        strcpy(this->ten, ten);
        strcpy(this->queQuan, queQuan);
        this->namSinh = namSinh;
    }
    ~BenhNhan() {}

    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        cin.getline(ten, 20);
        cout << "Nhap que quan: ";
        cin.getline(queQuan, 15);
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
    }

    void in() {
        cout << "- Ho ten: " << ten << endl;
        cout << "- Que quan: " << queQuan << endl;
        cout << "- Nam sinh: " << namSinh << endl;
    }

    int getTuoi() {
        time_t bayGio = time(0);
        tm *ltm = localtime(&bayGio);
        int tuoi = 1900 + ltm->tm_year - namSinh;
        return tuoi;
    }

    bool operator < (BenhNhan bn) {
        return (getTuoi() < bn.getTuoi());
    }
};

class BenhAn : public BenhNhan {
private:
    char tenBenhAn[25];
    int tienVienPhi;

public:
    BenhAn(const char* tenBenhAn = "", int tienVienPhi = 1, const char* ten = "", const char* queQuan = "", int namSinh = 1)
        : BenhNhan(ten, queQuan, namSinh) {
        	this -> tienVienPhi = tienVienPhi;
        	strcpy(this->tenBenhAn, tenBenhAn);
    }

    ~BenhAn() {}

    friend istream& operator >> (istream& is, BenhAn& ba) {
        ba.nhap();
        cout << "- Nhap ten benh an: ";
        cin.ignore();
        is.getline(ba.tenBenhAn, 25);
        cout << "- Nhap so tien vien phi: ";
        is >> ba.tienVienPhi;
        return is;
    }

    friend ostream& operator << (ostream& os, BenhAn& ba) {
        ba.in();
        os << "Ten benh an: " << ba.tenBenhAn << endl;
        os << "So tien vien phi: " << ba.tienVienPhi << endl;
        return os;
    }

    int getTienVienPhi() const {
        return tienVienPhi;
    }
};

void nhapSoBenhAn(BenhAn ba[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin benh an thu " << i + 1 << " : " << endl;
        cin >> ba[i];
        cout << "---------------------------------------" << endl;
    }
}

void inSoBenhAn(BenhAn ba[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Thong tin benh an thu " << i + 1 << " : " << endl;
        cout << ba[i];
        cout << "---------------------------------------" << endl;
    }
}

void quickSort(BenhAn ba[], int left, int right) {
    int i = left, j = right;
    int pivot = ba[(left + right) / 2].getTuoi(); 
    while (i <= j) {
        while (ba[i].getTuoi() < pivot) i++;
        while (ba[j].getTuoi() > pivot) j--; 
        if (i <= j) {
            swap(ba[i], ba[j]);
            i++;
            j--;
        }
    }
  
    if (left < j) quickSort(ba, left, j);
    if (i < right) quickSort(ba, i, right);
}

void sapXepGiamDanSoTuoiBenhNhan(BenhAn ba[], int m) {
    quickSort(ba, 0, m - 1);
}

void benhAnBenhNhanLonHon50(BenhAn ba[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (ba[i].getTuoi() > 50)
            dem++;

    if (dem == 0)
        cout << "Khong co benh nhan nao tren 50 tuoi." << endl;
    else
        for (int i = 0; i < n; i++)
            if (ba[i].getTuoi() > 50)
               	cout<<ba[i];
}

void hienThiBenhAnVoiVienPhiCaoNhat(BenhAn ba[], int n) {
    int maxTienVienPhi = 0;
    int indexMax = -1;
    for (int i = 0; i < n; i++) {
        if (ba[i].getTienVienPhi() > maxTienVienPhi) {
            maxTienVienPhi = ba[i].getTienVienPhi();
            indexMax = i;
        }
    }

    if (indexMax != -1) {
        cout << "Benh an voi vien phi cao nhat la: " << endl;
        cout << ba[indexMax];
    } else {
        cout << "Khong co benh an nao trong danh sach." << endl;
    }
}

int main(){
	BenhAn ba[50];
	int n;
	do
	{
		cout << "Nhap so truong benh an n = ";
		cin  >> n;
		cin.ignore();
	}while(n <= 0);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "NHAP DANH SACH BENH AN:\n";
	nhapSoBenhAn(ba,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH BENH AN:\n";
	inSoBenhAn(ba,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH TRUONG DAI HOC THEO THU TU GIAM DAN SO TUOI:\n";
	sapXepGiamDanSoTuoiBenhNhan(ba,n);
	inSoBenhAn(ba,n);

	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH BENH AN CUA BENH NHAN TUOI > 50:\n";
	benhAnBenhNhanLonHon50(ba,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "HIEN THI BENH AN VOI VIEN PHI CAO NHAT:\n";
	hienThiBenhAnVoiVienPhiCaoNhat(ba, n);
		
	return 0;
	}
