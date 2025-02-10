#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class SoPhuc {
	int pt,pa;
	
	public:
		SoPhuc(int pt =1 , int pa =1 ) {
			pt = pt;
			pa = pa;
		}
	~SoPhuc() {	
	}
	
	friend istream& operator >>(istream& in , SoPhuc &a) {
		cout<<"Nhap phan thuc la: ";
		in>>a.pt;
		cout<<"Nhap phan ao la: ";
		in>>a.pa;
		return in;
	}
	friend ostream& operator <<(ostream& out , SoPhuc a) {
		if(a.pa >= 0) {
			out<<a.pt <<" +j* "<<a.pa<<endl;
		}else
			out<<a.pt<<" -j* "<<a.pa<<endl;
	}
	
};

int main() {
	SoPhuc p1,p2;
	cout<<"Nhap he so cho so phuc p1 la: ";
	cout<<endl;
	cin>>p1;
	cout<<"Nhap he so cho so phuc p2 la: ";
	cout<<endl;
	cin>>p2;
	
	cout<<"\t\n SO Phuc p1 "<<p1;
	cout<<" \n Va so phuc p2  "<<p2<<endl;
	return 0;
}
