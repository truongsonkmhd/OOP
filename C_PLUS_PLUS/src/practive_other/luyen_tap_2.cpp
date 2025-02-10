#include <bits/stdc++.h>

using namespace std;

class SinhVien{
	private: // mac dinh la private
		string id, ten, ns;
		double gpa;
		static int dem; // bien static ( dung chung cho ca class )
	public:
		SinhVien(); // contructor_1
		SinhVien(string,string,string,double); // contructor_2
		void nhap();
		void in();
		void tangDem();
		double getGpa();
		int getDem();
		friend void inThongTin(SinhVien); // => se sd duoc thuoc tinh cua class SinhVien ke ca "private"
		
		friend void chuanHoa(SinhVien&);
	};
	
void chuanHoa(SinhVien &a){
	string res = "";
	stringstream ss(a.ten);
	string token;
	while(ss >> token){
		res += toupper(token[0]);
		for(int i = 1; i < token.length(); i++){
			res += tolower(token[i]);
		}
		res += " ";
	}
	res.erase(res.length() - 1);
	a.ten = res;
}

// test hàm friend
void inThongTin(SinhVien a){  // ham nay la ham ban  cua  class
	cout<<a.id << " " << a.ten <<endl;
}
// test static
int SinhVien::dem = 0;

//phai goi contructor ra
SinhVien::SinhVien(){
	this->id = this->ten = this->ns = "";
	this->gpa = 0;

}; // SinhVien x

SinhVien::SinhVien(string id, string ten,string ns,double gpa){ // SinhVien y
	this ->id = id;
	this ->ten = ten;
	this ->ns = ns;
	this ->gpa = gpa;
}

void SinhVien::tangDem(){ // ham nay la member cua class
	++dem;
}

int SinhVien::getDem(){ // ham nay la member cua class
	return dem;
}

void SinhVien::nhap(){ // ham nay la member cua class
	++dem; // dem =1->2->3->4
	this->id = "SV" + string(3-to_string(dem).length(),'0') + to_string(dem);
	//dem = 1 => "1"
	cout<< "Nhap ten :"; getline(cin,this->ten);
	cout<<"Nhap ns:"; cin>> this->ns;
	cout<<"Nhap diem:"; cin>> this->gpa;
	cin.ignore(); // Add this line to consume the newline character
}


void SinhVien::in(){ // ham nay la member cua class
	cout << this->id << " " << this->ten <<" "<< this->ns <<" "<< this->gpa <<endl;
}

//setter- getter
double SinhVien::getGpa(){ // ham nay la member cua class
	return this->gpa ; // return gpa
}

bool cmp(SinhVien a, SinhVien b){ // dây la ham khong phai member class
	return a.getGpa() > b.getGpa();
}

int main() { 
//==test setter - getter==
int n; cin>>n;
SinhVien a[n];
	for(int i = 0 ; i < n ; i++){
		a[i].nhap();
	}
	sort(a,a+n,cmp);
	for(int i = 0; i < n ; i++){
		a[i].in();
	}


//	SinhVien x;
//	x.tangDem();// dem = 1
//	x.tan	gDem(); // dem  = 2
//	SinhVien y;
//	cout<<y.getDem()<<endl;
//	y.tangDem();
//	SinhVien z;
//	cout<< x.getDem()<< " " << y.getDem()<< " " << x.getDem();

// test static
  	SinhVien x;
    char tiepTuc;
	do {	
        x.nhap();
        x.in();
        cout << "Ban co muon nhap tiep khong? (y/n): ";
        cin >> tiepTuc;
        cin.ignore(); // Consume newline character after 'cin >> tiepTuc;'
    } while(tiepTuc == 'y' || tiepTuc == 'Y');
    
//test ham friend
	 SinhVien z;
	 inThongTin(z);
	 
//=== hàm friend : chuanHoa
	SinhVien c;
	c.nhap();
	chuanHoa(c);
	c.in();
	//input: nguyeN VaN LoNg -> output: Nguyen Van Long
	return 0;
}

