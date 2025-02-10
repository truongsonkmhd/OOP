#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class MayTinh {
	char mh[15],ten[30];
	int dongia;
	int dlram,tl;
	
	public:
		MayTinh(const char mh[] = " " , const char *ten = "", int dongia = 0, int dlram = 1 , int tl = 1) {
			strcpy(this->mh,mh);
			strcpy(this->ten,ten);
			this->dongia = dongia;
			this->dlram = dlram;
			this->tl = tl;
		}
		~MayTinh() {
		}
		
		friend istream& operator >> (istream& in , MayTinh &a) {
			cout<<"Nhap ma hang la: ";
			fflush(stdin);
			in.getline(a.mh,15);
			cout<<"Nhap ten hang la: ";
			fflush(stdin);
			in.getline(a.ten,30);
			cout<<"Nhap don gia la: ";
			in>>a.dongia;
			cout<<"Nhap dung luong ram la: ";
			in>>a.dlram;
			cout<<"Nhap trong luong la: ";
			in>>a.tl;
			
			return in;
		}
		
		float Tinh_tien() {
			if(tl > 2) {
				return 100000;
			}else if(tl > 1) {
				return 50000;
			}else
				return 300000;
		}
		
		friend ostream& operator << (ostream& out , MayTinh a) {
			out<<" MA HANG "<<a.mh<<endl
				<<" TEN HANG "<<a.ten<<endl
				<<" DON GIA "<<a.dongia<<endl
				<<" DUNG LUONG RAM "<<a.dlram<<endl
				<<" TRONG LUONG "<<a.tl<<endl
				<< " TIEN VAN CHUYEN "<<a.Tinh_tien()<<endl;
		}
		
		int get_dlram() {
			return dlram;
		}
		
		char* get_ten() {
			return ten;
		}
		
};


void nhapDS(MayTinh a[] ,int &n) {
	for(int i=0;i<n;i++) {
		cout<<"\t\nMay tinh thu "<<i+1<<endl;
		cin>>a[i];
	}
}

void xuatDS(MayTinh a[] ,int n) {
	for(int i=0;i<n;i++) {
		cout<<"\t\nMay tinh thu "<<i+1<<endl;
		cout<<a[i];
	}
}

void Hien_thi(MayTinh a[] , int n) {
	cout<<"\t\t\n-Hien thi dung luong ram == 16: \n";
	for(int i=0;i<n;i++) {
		if(a[i].get_dlram() == 16) {
			cout<<a[i]<<endl;
		} 
	}
}

void Xoa(MayTinh a[], int &n) {
    bool kt = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].get_ten(), "sony") == 0) {
            kt = true;
            cout << a[i];
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
        }
    }
    if (kt) {
        cout << "\t\t\n Hang sony da dc xoa!!!!!! \n";
        cout << "\t\t\nDanh sach sau khi XOA:\n";
             xuatDS(a, n); 
    } else {
        cout << "Khong tim thay hang Sony trong danh sach." << endl;
    }
    
}

void Them(MayTinh a[], int &n) {
    MayTinh hang_them;
    cout<<"Nhap may tinh 'sonny new'  can them:"<<endl;
    cin >> hang_them;

    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }

    a[0] = hang_them;
    n++;
    
}

int main() {
    int n;
    cout << "Nhap so luong hang may tinh la: ";
    cin >> n;

    MayTinh a[n];
    nhapDS(a, n);
    xuatDS(a, n);
    Hien_thi(a, n);
    Xoa(a, n);
    Them(a, n);
    cout << "\t\t\nDanh sach sau khi THEM:\n";
    xuatDS(a, n); 
    return 0;
}
