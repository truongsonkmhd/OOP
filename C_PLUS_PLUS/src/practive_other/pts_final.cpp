#include<iostream>
#include<cstring>
using namespace std;

class Truong{
	private:
		char ma_truong[20];
		char ma_lop[15];
		int so_lop;
		int so_sinh_vien;
	public:
		Truong(const char* ma_truong = "", const char* ma_lop = "", int so_lop = 1, int so_sinh_vien = 1)
		{
			strcpy(this->ma_truong , ma_truong);
			strcpy(this->ma_lop , ma_lop);
			this->so_lop = so_lop;
			this->so_sinh_vien = so_sinh_vien;
		}
		~Truong(){
		}
		void nhap() {
			cout << "Nhap ma truong: ";
			fflush(stdin);
			cin.getline(ma_truong, 30);
			cout << "Nhap ma lop: ";
			cin.getline(ma_lop, 30);
			cout << "Nhap so lop: ";
			cin >> so_lop;
			cout << "Nhap so sinh vien: ";
			cin >> so_sinh_vien;
		}
		
		void in() {
			cout << "- Ma truong: " << ma_truong << endl;
			cout << "- Ma lop: " << ma_lop << endl;
			cout << "- So lop: " << so_lop << endl;
			cout << "- So sinh vien: " << so_sinh_vien << endl;
		}
		
		int getSoSinhVien(){
			return so_sinh_vien;
		}
		const char* getMaTruong(){
			return ma_truong;
		}
		int getSoLop(){
			return so_lop;
		}
		
		bool operator < (Truong t){
			return (getSoSinhVien(), t.getSoSinhVien()) < 0;
		}
};

class TruongDaiHoc : public Truong{
	private:
		char ten_truong[25];
		int so_chuyen_nganh;
	public :
	    TruongDaiHoc(const char* ma_truong = "", const char* ma_lop = "", int so_lop = 1, int so_sinh_vien = 1,
		             const char* ten_truong = "", int so_chuyen_nganh = 1):Truong(ma_truong,ma_lop,so_lop, so_sinh_vien)
					 {
					 	strcpy(this->ten_truong , ten_truong);
					 	this->so_chuyen_nganh = so_chuyen_nganh;
					  }
					  
	    ~TruongDaiHoc(){}	
					
		friend istream& operator >> (istream& is, TruongDaiHoc &tdh){
		tdh.Truong::nhap();
			cout << "-Nhap ten truong: ";
			fflush(stdin);
			is.getline(tdh.ten_truong, 30);;
			cout << "-Nhap so chuyen nghanh: ";
			is >> tdh.so_chuyen_nganh;
			return is;
		}
		const char* noiHocQuanSu()
		{
			if(getSoSinhVien() > 1000)
			  return "Co so 1 ";
			else if(getSoSinhVien() >= 600)
			  return "Co so 2";
			else 
			  return "Co so 3";  
		}
		friend ostream& operator << (ostream& os , TruongDaiHoc &tdh){
			tdh.Truong::in();
			os << "Ten Truong la : " << tdh.ten_truong << endl;
			os << "So Chuyen Nganh la : "<< tdh.so_chuyen_nganh << endl;
			return os;
		}
		int getSoChuyenNganh(){
			return so_chuyen_nganh;
		}
		bool operator < (TruongDaiHoc tdh){
			return (getSoChuyenNganh(), tdh.getSoChuyenNganh()) < 0;
		}
			
	
};
void nhapDanhSachTruong(Truong t[], int m) {
	for(int i = 0; i < m; i++) {
		cout << "Nhap thong tin truong thu " << i + 1 << " : " << endl;
		t[i].nhap();
		cout << "------------------------------" << endl;
	}
}

void inDanhSachTruong(Truong t[], int m) {
	for(int i = 0; i < m; i++) {
		cout << "Thong tin truong thu " << i + 1 << " : " << endl;
		t[i].in();
		cout << "------------------------------" << endl;
	}
}

void nhapDanhSachTruongDaiHoc(TruongDaiHoc tdh[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "Nhap thong tin truong dai hoc thu " << i + 1 << " : " << endl;
		cin >> tdh[i];
		cout << "---------------------------------------" << endl;
	}
}

void inDanhSachTruongDaiHoc(TruongDaiHoc tdh[], int n) {
	for(int i = 0; i < n; i++) {
		cout << "Thong tin truong dai hoc thu " << i + 1 << " : " << endl;
		cout << tdh[i];
		cout << "---------------------------------------" << endl;
	}
}
void sapXepGiamDanSoChuyenNganh(TruongDaiHoc tdh[], int n)
{
	for(int i=0;i<n-1;i++)
	  for(int j= i+1; j<n;j++)
	     if(tdh[i] < tdh[j])
	     swap(tdh[i],tdh[j]);
}

void sapXepGiamDanSoSinhVien(Truong t[], int m)
{
	for(int i=0;i<m-1;i++)
	  for(int j= i+1; j<m;j++)
	     if(t[i] < t[j])
	     swap(t[i],t[j]);
}

void SoSinhVien900(TruongDaiHoc tdh[], int n){
	int dem = 0;
    for(int i=0;i<n;i++)
    if(tdh[i].getSoSinhVien() < 900)
    dem++;
    
    if(dem == 0)
       cout << "null\n";
    else 
       for(int i=0;i<n;i++)
       if(tdh[i].getSoSinhVien() < 900)
       tdh[i].in();
}

void SoLop22(TruongDaiHoc tdh[], int n){
	int dem = 0;
    for(int i=0;i<n;i++)
    if(tdh[i].getSoLop() == 22)
    dem++;
    
    if(dem == 0)
       cout << "null\n";
    else 
       for(int i=0;i<n;i++)
       if(tdh[i].getSoLop() < 900)
       inDanhSachTruongDaiHoc(tdh,n);
}
void ThemTruongDaiHoc(TruongDaiHoc tdh[], int n, int k1){
	if(k1 >= 1 && k1 <= n + 1) {
		TruongDaiHoc tdhCanThem;
		cout << "Nhap thong tin truong dai hoc can them: " << endl;
		cin >> tdhCanThem;
		for(int i = n; i >= k1; i--) {
			tdh[i] = tdh[i-1];
		}
		tdh[k1 - 1] = tdhCanThem;
		++n;
		
		cout << endl << "Danh sach cac truong dai hoc sau khi them: " << endl;
		inDanhSachTruong(tdh, n);
	} else {
		cout << "Vi tri can them khong hop le!!";
	}
} 
void XoaTruongDaiHoc(TruongDaiHoc tdh[], int n){
	int vi_tri;
	do{
		cout << "\nNhap vi tri can xoa :";
		cin  >> vi_tri;
	    cin.ignore();
	} while (vi_tri <= 0|| vi_tri > n);

	int k = vi_tri - 1;
	
	for(int j=k; j< n-1; j++)
	   tdh[j] = tdh[j+1];
	n--;
}

int main(){
	Truong tr[50];
	int m;
	do
	{
		cout << "Nhap so luong truong m = ";
		cin  >> m;
		cin.ignore();
	}while(m <= 0);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "NHAP DANH SACH TRUONG :\n";
	nhapDanhSachTruong(tr,m);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH TRUONG :\n";
	inDanhSachTruong(tr,m);
	
	TruongDaiHoc tdh[50];
	int n;
	do
	{
		cout << "Nhap so truong dai hoc n = ";
		cin  >> n;
		cin.ignore();
	}while(n <= 0);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "NHAP DANH SACH TRUONG DAI HOC :\n";
	nhapDanhSachTruongDaiHoc(tdh,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH TRUONG DAI HOC:\n";
	inDanhSachTruongDaiHoc(tdh,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH TRUONG DAI HOC THEO THU TU GIAM DAN SO CHUYEN NGANH:\n";
	sapXepGiamDanSoChuyenNganh(tdh,n);
	inDanhSachTruongDaiHoc(tdh,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH TRUONG DAI HOC THEO THU TU GIAM DAN SO SINH VIEN:\n";
	sapXepGiamDanSoSinhVien(tdh,n);
	inDanhSachTruongDaiHoc(tdh,n);
	 
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	int k1;
	cout << endl << "Nhap vi tri can them vào danh sach truong dai hoc: ";
	cin >> k1;
	ThemTruongDaiHoc(tdh,n,k1);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "XOA TRUONG DAI HOC KHOI DANH SACH:\n";
	XoaTruongDaiHoc(tdh,n);
	inDanhSachTruongDaiHoc(tdh,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH CAC TRUONG DAI HOC CO SO SINH VIEN < 900:\n";
	SoSinhVien900(tdh,n);
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "IN DANH SACH CAC TRUONG DAI HOC CO SO LOP  = 22:\n";
	SoLop22(tdh,n);
	
	return 0;
}
