#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;

class GiaoVien{
	char ht [30] , bc[15], cn[20];
	int tuoi;
	float bl;
	
	public:
		GiaoVien(const char* ht = " " ,const char* bc =" ",const char* cn = " ", int tuoi =1 ,float bl = 1.0f) {
			strcpy(this->ht,ht);
			strcpy(this->bc,bc);
			strcpy(this->cn,cn);
			this->tuoi = tuoi;
			this->bl = bl;
		}
		
		~GiaoVien() {
		}
		
		friend istream& operator >> (istream& in , GiaoVien &a) {
			cout<<"Nhap ho ten la: ";
			fflush(stdin);
			in.getline(a.ht,30);
			cout<<"Nhap bang cap la: ";
			in.getline(a.bc,15);
			cout<<"Nhap chuyen nganh la: ";
			in.getline(a.cn,20);
			fflush(stdin);
			cout<<"Nhap tuoi la: ";
			in>>a.tuoi;
			cout<<"Nhap bac luong la: ";
			in>>a.bl;
			
			return in;
		} 
		
		
		float get_tienluong() {
			return this->bl *610;
		}
		
		friend ostream& operator <<(ostream& out , GiaoVien a) {
			out<<"-Ho ten: "<<a.ht<<endl
				<<"-Bang cap: "<<a.bc<<endl
				<<"-Chuyen nganh: "<<a.cn<<endl
				<<"-Tuoi: "<<a.tuoi<<endl
				<<"-Bac Luong: "<<a.bl<<endl
				<<"-Luong Co ban: "<<a.get_tienluong()<<endl;
		}
		
		char* get_ht() {
			return ht;
		}
};

void nhapDS(GiaoVien a[] , int& n) {
	for(int i=0;i<n;i++) {
		cout<<"\t\nGiao vien thu "<<i+1<<endl;
		cin>>a[i];
	}
}

void xuatDS(GiaoVien a[] ,int n) {
	for(int i=0;i<n;i++) {
		cout<<"\t\nGiao vien thu "<<i+1<<endl;
		cout<<a[i];
	}
}

void Tienluong_nho(GiaoVien a[] ,int &n) {
	cout<<"\t\nDanh sach nguoi co tien luong < 2000 \n";
	for(int i=0;i<n;i++) {
		if(a[i].get_tienluong() < 2000) {
			cout<<a[i]<<endl;
		}else {
			cout<<"Empty"<<endl;
		}
	}
	
} 

void Tim_GV(GiaoVien a[] ,int &n) {
	GiaoVien gvm;
	cin>>gvm;
	int vt;
	bool kt = false;
	for(int i=0;i<n;i++) {
		if(strcmp(a[i].get_ht(),gvm.get_ht()) == 0) {
			kt = true;
			vt = i;
		}
	}
	if(kt) {
		cout<<"\t\nGiao vien co trong danh sach va co luong "<<a[vt].get_tienluong();
	}else
		cout<<"\t\nGiao vien nay k co trong danh sach ";
		n++;
		a[n] = gvm;
}

int main() {
	int n;
	cout<<"Nhap so luong giao vien la: ";
	cin>>n;
	
	GiaoVien a[n];
	nhapDS(a,n);
	xuatDS(a,n);
	Tienluong_nho(a,n);
	Tim_GV(a,n);
	return 0;
}
