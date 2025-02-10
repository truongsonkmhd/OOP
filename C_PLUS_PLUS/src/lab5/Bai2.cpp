#include <iostream>
#include <cstring>
using namespace std;

class Nguoi {
	private:
		char hoTen[30];
		int ns;
	public:
	    Nguoi() {
	        strcpy(hoTen, "");
	        ns = 0;
	    }
	    
	    ~Nguoi() {}
	    
	    Nguoi(char h[], int a) {
			strcpy(hoTen, h);
			ns = a;
		}
		
		friend istream& operator>>(istream& is, Nguoi& ng) {
	        cout << "Nhap ho ten: ";
	        is.getline(ng.hoTen, 50);
	        cout << "Nhap nam sinh: ";
	        is >> ng.ns;
	        is.ignore();
	        
	        return is;
    	}
    	
    	friend ostream& operator<<(ostream& os, Nguoi& ng) {
	        os << "Ho ten: " << ng.hoTen << ", Nam sinh: " << ng.ns << endl;
	        
	        return os;
	    }
};

class SinhVien {
	protected:
		char hanhKiem[20];
    	float diem;
 	public:
 		SinhVien() {
	        strcpy(hanhKiem, "");
	        diem = 0.0;
	    }
	    
	    ~SinhVien(){}
	    
	    friend istream& operator>>(istream& is, SinhVien& sv) {
	        cout << "Nhap hanh kiem: ";
	        is.getline(sv.hanhKiem, 20);
	        cout << "Nhap diem: ";
	        is >> sv.diem;
	        is.ignore();
	        
	        return is;
	    }
	    
	    friend ostream& operator<<(ostream& os, SinhVien& sv) {
	        os << "Hanh kiem: " << sv.hanhKiem << ", Diem: " << sv.diem << endl;
	        
	        return os;
	    }
};

class SVTC: public Nguoi, public SinhVien {
	private:
    	long hocPhi;
	public:
	    friend istream& operator>>(istream& is, SVTC& svtc) {
	        is >> static_cast<Nguoi&>(svtc);
	        is >> static_cast<SinhVien&>(svtc);
	        cout << "Nhap hoc phi: ";
	        is >> svtc.hocPhi;
	        is.ignore();
	        
	        return is;
	    }
	    
	    friend ostream& operator<<(ostream& os, SVTC& svtc) {
	        os << static_cast<Nguoi&>(svtc);
	        os << static_cast<SinhVien&>(svtc);
	        os << "Hoc phi: " << svtc.hocPhi << endl;
	        
	        return os;
	    }
	    
	    long tinhHocBong() {
		    if (strcmp(hanhKiem, "Tot") == 0 && diem >= 8.0) return 5000000;
		    if ((strcmp(hanhKiem, "Tot") == 0 || strcmp(hanhKiem, "Kha") == 0) && diem >= 7.0 && diem < 8.0) return 3000000;
		    if (diem >= 7.0) return 2000000;
		    return 0;
		}
};

void nhapDanhSachSVTC(SVTC svtc[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Nhap sinh vien thu " << i + 1 << ": " << endl;
        cin >> svtc[i];
    }
}

void xuatDanhSachSVTC(SVTC svtc[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Thong tin sinh vien thu " << i + 1 << ": " << endl;
        cout << svtc[i] << endl;
    }
}

int main() {
	int n;
    cout << "Nhap so luong sinh vien tai chuc: ";
    cin >> n;
    cin.ignore();
	
	SVTC* svtc = new SVTC[n];
	nhapDanhSachSVTC(svtc, n);
	xuatDanhSachSVTC(svtc, n);
	
	delete[] svtc;
	return 0;
}