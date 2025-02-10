#include <iostream>
#include <cstring>
using namespace std;

class DUOCPHAM {
	private:
		char maSP[30], tenSP[30];
		float giaChuaThue;
	public:
	DUOCPHAM(const char* maSP = "", const char* tenSP = "", float giaChuaThue = 0) {
			strcpy(this->maSP, maSP);
			strcpy(this->tenSP, tenSP);
			this->giaChuaThue = giaChuaThue;
		}
		
		~DUOCPHAM() {}
		
		void nhap() {
			cout << "Nhap ma san pham: ";
			fflush(stdin);
			cin.getline(maSP, 30);
			cout << "Nhap ten san pham: ";
			cin.getline(tenSP, 30);
			cout << "Nhap gia chua thue: ";
			cin >> giaChuaThue;
		}
		
		void in() {
			cout << "- Ma san pham: " << maSP << endl;
			cout << "- Ten san pham: " << tenSP << endl;
			cout << "- Gia chua thue: " << giaChuaThue << endl;
		}
		
		float getGiaChuaThue() {
			return giaChuaThue;
		}
		
		char* getMaSP() {
			return maSP;
		}
};

class THUOC: public	DUOCPHAM {
	private:
		char loaiThuoc[30], hsd[30], thanhPhan[255];
	public:
		THUOC(const char* maSP = "",const char* tenSP = "", float giaChuaThue = 0,const char* loaiThuoc = "",const char* hsd = "",const char* thanhPhan = ""): DUOCPHAM(maSP, tenSP, giaChuaThue) {
			strcpy(this->loaiThuoc, loaiThuoc);
			strcpy(this->hsd, hsd);
			strcpy(this->thanhPhan, thanhPhan);
		}
		
		~THUOC() {}
		
		friend istream &operator >> (istream &is, THUOC &t) {
			t.DUOCPHAM::nhap();
			cout << "Nhap loai thuoc: ";
			cin.ignore();
			is.getline(t.loaiThuoc, 30);
			cout << "Nhap han su dung: ";
			is.getline(t.hsd, 30);
			cout << "Nhap thanh phan thuoc: ";
			is.getline(t.thanhPhan, 255);
			
			return is;
		}
		
		float giaSauThue() {
			return getGiaChuaThue() + getGiaChuaThue()*0.1;
		}
		
		friend bool operator > (THUOC &t1, THUOC &t2) {
			return strcmp(t1.getMaSP(), t2.getMaSP())> 0;
		}
		
		friend ostream &operator << (ostream &os, THUOC &t) {
			t.DUOCPHAM::in();
			os << "- Loai thuoc: " << t.loaiThuoc << endl;
			os << "- Han su dung: " << t.hsd << endl;
			os << "- Thanh phan thuoc: " << t.thanhPhan << endl;
			
			return os;
		}
};

void nhapDuocPham(DUOCPHAM dp[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "Nhap thuoc tin duoc pham thu " << i + 1 << " :" << endl;
		dp[i].nhap();
		cout << "--------------------------------" << endl;
	}
}

void inDuocPham(DUOCPHAM dp[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "==> Thong tin duoc pham thu " << i + 1 << " : " << endl;
		dp[i].in();
		cout << "--------------------------------" << endl;
	}
}

void nhapThuoc(THUOC thuoc[], int m) {
	for(int i = 0; i < m; i++) {
		cout << "Nhap thong tin thuoc thu " << i + 1 << " : " << endl;
		cin >> thuoc[i];
	}
}

void inThuoc(THUOC thuoc[], int m) {
	for(int i = 0; i < m; i++) {
		cout << "Thong tin thuoc thu " << i + 1 << " : " << endl;
		cout << thuoc[i] << endl;
	}
}

void sortThuocByMaSP(THUOC thuoc[], int m) {
	for(int i = 0; i < m; i++) {
		for(int j = i + 1; j < m; j++) {
			if(thuoc[i] > thuoc[j]) {
				swap(thuoc[i], thuoc[j]);
			}
		}
	}
}

void xoa(THUOC thuoc[], int m, int k) {
	if(k >= 1 && k <= m) {
		for(int i = k - 1; i < m; i++) {
			thuoc[i] = thuoc[i+1];
		}
		--m;
		cout << endl << "Danh sach thuoc sau khi xoa la: " << endl;
		inThuoc(thuoc, m);
	}else {
		cout << "Vi tri can xoa khong hop le!!!" << endl;
	}
}

int main() {
	int n;
	cout << "Nhap so luong duoc pham: ";
	cin >> n;
	DUOCPHAM dp[n];
	nhapDuocPham(dp, n);
	inDuocPham(dp, n);
	
	int m;
	cout << "Nhap so luong thuoc: ";
	cin >> m;
	THUOC thuoc[m];
	nhapThuoc(thuoc, m);
	inThuoc(thuoc, m);
	
	cout << endl << "Danh sach thuoc theo thu tu tang dan cua ma san pham: " << endl;
	for(int i = 0; i < m; i++) {
		cout << thuoc[i] << endl;
	}
	
	int k;
	cout << endl << "Nhap vi tri can xoa: ";
	cin >> k;
	xoa(thuoc, m, k);
	return 0;
}
