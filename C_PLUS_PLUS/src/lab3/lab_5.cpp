#include<iostream>
#include<string.h>
#include<iomanip>
#include<math.h>
using namespace std;

int UCLN(int a, int b) {
	a = abs(a);
	b = abs(b);
	while(a != b) {
		if(a>b) {
			a = a - b;
		}else
			b = b - a;
	}
	return a;
}

class PS {
	float ts,ms;
	public:
		PS(float ts =0, float ms = 1) {
			this->ts = ts;
			this->ms = ms;
		}
		~PS() {
		}
		
		friend istream& operator >>(istream& in , PS &a) {
			cout<<"Nhap tu so la: ";
			in>>a.ts;
			do{
				cout<<"Nhap mau so la: ";
				cin>>a.ms;
				if(a.ms == 0) {
					cout<<"Nhap lai !";
					cin>>a.ms;
				}
			}while(a.ms == 0);
				return in;
		}
		
		
		friend ostream& operator <<(ostream& out , PS a) {
			out<<a.ts<< " / "<<a.ms<<endl;
		}
		
		PS rutgon() {
			PS p;
			p.ts = ts / UCLN(ts,ms);
			p.ms = ms / UCLN(ts,ms);
			
			return p;
		}
		
		PS operator + (PS &a) {
			PS p;
			p.ts = this->ts * a.ms + a.ts * this->ms;
			p.ms = this->ms * a.ms;
			
			return p.rutgon();
		}
		
			PS operator - (PS &a) {
			PS p;
			p.ts = (this->ts * a.ms)- (a.ts * this->ms);
			p.ms = this->ms * a.ms;
			
			return p.rutgon();
		}
		
			PS operator * (PS &a) {
			PS p;
			p.ts = this->ts * a.ts;
			p.ms = this->ms * a.ms;
			
			return p.rutgon();
		}
		
			PS operator / (PS &a) {
			PS p;
			p.ts = this->ts * a.ms;
			p.ms = this->ms * a.ts;
			
			return p.rutgon();
		}
};


int main() {
	PS ps,p1,p2;
	cout<<"\t\nNhap he so cua p1 la: \n";
	cin>>p1;
	cout<<"\t\nNhap he so cua p2 la: \n";
	cin>>p2;
	cout<<endl;
	ps=p1+p2;
	cout<<"Tong la: ";
	cout<<ps;


	ps=p1-p2;
	cout<<"Hieu la: ";
	cout<<ps;
	
	
	ps=p1*p2;
	cout<<"Tich la: ";
	cout<<ps;
	
	ps=p1/p2;
	cout<<"Thuong la: ";
	cout<<ps;
	
	return 0;
}
