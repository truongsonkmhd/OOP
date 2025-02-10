#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class DT3 {
	int a,b,c,d;
	
	public:
		DT3() {
			this->a = a;
			this->b = b;
			this->c = c;
			this->d = d;
		}
		
		~DT3() {
		}
		
		friend istream& operator >> (istream& in , DT3 &a) {
			cout<<"Nhap he so a ";
			in>>a.a;
			cout<<"Nhap he so b ";
			in>>a.b;
			cout<<"Nhap he so c ";
			in>>a.c;
			cout<<"Nhap he so d ";
			in>>a.d;
			
			return in;
		}
		
		friend ostream& operator << (ostream& out , DT3 a) {
			out<<a.a<<"X^3 + "<<a.b<<"X^2 + "<<a.c<<"X + "<<a.d<<endl;
		}
		
		DT3 operator + (DT3 &p) {
			DT3 t;
			t.a = this->a + p.a;
			t.b = this->b + p.b;
			t.c = this->c + p.c;
			t.d = this->d + p.d;
			return t;
		}
		
		DT3 operator - (DT3 &p) {
			DT3 t;
			t.a = this->a - p.a;
			t.b = this->b - p.b;
			t.c = this->c - p.c;
			t.d = this->d - p.d;
			
			return t;
			
		}
};

int main() {
	DT3 dt,dt1,dt2;
	cout<<"Nhap he so da thuc 1 la: \n";
	cin>>dt1;
	cout<<"Nhap he so da thuc 2 la: \n";
	cin>>dt2;
	cout<<"Hien thi dathuc 1 la: \n"<<dt1;
	cout<<"Hien thu dathuc 2 la: \n"<<dt2;
	cout<<"Tong 2 da thuc la: "<<dt1 + dt2<<endl;
	cout<<" Hieu 2 da thuc la :"<<dt1 - dt2 <<endl;
	
	
	return 0;
}
