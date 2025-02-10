#include <iostream>
#include <algorithm>

using namespace std;

// class : Lop
// thuoc tinh : attribute
// phuong thuc: method, behavior
//object: Doi tuong

// -Encapsulation: Dong goi( các thuoc tinh cua 1 class chi truy cap dc o trong lop do thoi, ben ngoai khong duoc )
//- Access modifier
//+private( thuoc tinh de private -> de giau data cua 1 class di) => the hien tinh dong goi( encapsulation)
//+public ( thuogn la phuong thuc vi no cho phep class khac truy cap den)
//+protected

//contructor: ham khoi tao

//destructor: ham huy ( khong co kieu tra ve, co ten trung voi ten class va có dau "~"

// setter getter

class SinhVien{
	private: // mac dinh la privatet
		string id, ten, ns;
		double gpa;
	public:
		SinhVien(); // contructor_1
		SinhVien(string,string,string,double); // contructor_2
		void nhap();
		void in();
		// lay ra gia tri
		double getGpa();
		string getId();
		string getName();
		string getNs();
		
		// thay doi 1 gia tri cua thuoc tinh
		void setGpa(double);
	//	~SinhVien(); // Ham huy
	};



//implementation

SinhVien::SinhVien(){
/*//	cout<< "Doi tuong mac dinh duoc tao o day!";
//	this->id = this->ten = this->ns = "";
//	this->gpa = 0;	*/
}

//SinhVien::SinhVien(string ma, string name,string birth, double diem){
//	cout<< "Ham khoi tao co tham so duoc goi !\n";
//	this->id = ma;
//	this->ten = name;
//	this->ns = birth;
//	this->gpa = diem;
//}

//SinhVien::~SinhVien(){
//		cout << "Doi tuong duoc huy tai day !\n";
//}

void SinhVien::nhap(){
	cout<< "Nhap id :"; cin>>this->id;
	cin.ignore();
	cout<<"Nhap ten :"; getline(cin,this->ten);
	cout<<"Nhap ns:"; cin>>this->ns;
	cout<<"Nhap diem: "; cin>>this->gpa;
}

void SinhVien::in(){
	cout<< this->id << " "<<this->ten << " " << this->ns << " " << this->gpa <<endl;
}

double SinhVien::getGpa(){
	return this -> gpa; // return gpa;
	}

bool cmp(SinhVien a, SinhVien b){
	return a.getGpa() > b.getGpa();
}

void SinhVien::setGpa(double gpa){
	this -> gpa = gpa;
}

int main() { 
//	SinhVien x;
//	SinhVien x("123", "pham truong son","01/07/2004",9);
//	x.nhap();
//	x.in();

	int n; cin>>n;
	SinhVien a[100];
	for(int i = 0; i < n; i++){
		a[i].nhap();
	}
	sort(a,a + n,cmp);
	for(int i = 0;  i < n; i++){
		a[i].in();
	}

// set gpa
//	SinhVien x;
//	x.setGpa(2.18); // => nó se sua gtri gpa trong khi gpa la private
//	return 0;
}
