#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class OTO {
	char mh[20],ten[30];
	int dongia,tl;
	float dt;
	
	public:
		OTO(const char* mh = " ",const char* ten = " ", int dongia = 1 ,int tl =1 , float dt = 1.0f) {
			strcpy(this->mh,mh);
			strcpy(this->ten,ten);
			this->dongia = dongia;
			this->tl = tl;
			this->dt = dt;
		}
		~OTO() {
		}
		
		friend istream& operator >>(istream& in , OTO &a) {
			cout<<"Nhap ma hang la: ";
			fflush(stdin);
			in.getline(a.mh,20);
			cout<<"Nhap ten hang san xuat la: ";
			fflush(stdin);
			in.getline(a.ten,30);
			cout<<"Nhap don gia la: ";
			in>>a.dongia;
			cout<<"Nhap trong luong la: ";
			in>>a.tl;
			cout<<"Nhap dung lich xi lanh la: ";
			in>>a.dt;
			
			return in;
		}
		float Tinh_tien() {
			if(tl > 2000) {
				return 100000;
			}else if(tl > 1000) {
				return 500000;
			}else
				return 30000;
		}
		
		bool operator ==(float a) {
			return this->dt == a;
		} 
		
		friend ostream& operator <<(ostream& out , OTO a) {
			out<<" MA HANG "<<a.mh<<endl
				<<" TEN HANG "<<a.ten<<endl
				<<" DON  GIA "<<a.dongia<<endl
				<<" TRONG LUONG "<<a.tl<<endl
				<<" DUNG TICH "<<a.dt<<endl
				<<" TIEN VAN CHUYEN "<<a.Tinh_tien()<<endl;
		}
		
		char* get_ten() {
			return this->ten;
		}
		
};


void nhapDS(OTO a[] ,int &n) {
	for(int i=0;i<n;i++) {
		cout<<"\t\nOTO thu "<<i+1<<endl;
		cin>>a[i];
	}
}

void xuatDS(OTO a[] ,int n) {
	for(int i=0;i<n;i++) {
		cout<<"\t\nOTO thu "<<i+1<<endl;
		cout<<a[i];
	}
}

void Dung_tich(OTO a[] ,int n) {
	cout<<"\t\nOto co dung tich 2.5 la: \n";
	for(int i=0;i<n;i++) {
		if(a[i] == 2.5) {
			cout<<a[i];
		}
	}
}

void Xoa(OTO a[], int &n) {
    bool kt = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(a[i].get_ten(), "toyota") == 0) {
            kt = true;
            cout << a[i];
            for (int j = i; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            n--;
        }
    }
    if (kt) {
        cout << "\t\t\n Hang toyota da dc xoa!!!!!! \n";
        cout << "\t\t\nDanh sach sau khi XOA:\n";
             xuatDS(a, n); 
    } else {
        cout << "Khong tim thay hang toyota trong danh sach." << endl;
    }
    
}

void Them(OTO a[], int &n) {
    OTO ot;
    cout<<"Nhap may tinh 'toyota new' can them:"<<endl;
    cin >> ot;

    for (int i = n; i > 0; i--) {
        a[i] = a[i - 1];
    }

    a[0] = ot;
    n++;
    
}
int main() {
	int n;
	cout<<"Nhap so luong oto la: ";
	cin>>n;
	
	OTO a[n+5];
	nhapDS(a,n);
	xuatDS(a,n);
	Dung_tich(a,n);
	Xoa(a,n);
	Them(a,n);
	cout << "\t\t\nDanh sach sau khi THEM:\n";
    xuatDS(a, n); 
	return 0;
}
