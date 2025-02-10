#include<iostream>
#include<cstring>
using namespace std;

class Tau{
	private:
		char hangSX[30];
		float vanTocTD;
		int namSX;
	
	public:
		Tau(const char* hangSX = " ", float vanTocTD = 0.0, int namSX =0){
			strcpy(this->hangSX, hangSX);
			this->vanTocTD = vanTocTD;
			this->namSX = namSX;
		}
	
		~Tau(){
		}
	
	const char* getHangSX() {
		return hangSX;
	}
		
	int getNamSx(){
		return namSX;
	}
		
	void nhapTT(){
		cout<<"Nhap tt hang sx :";
		fflush(stdin);
		cin.getline(hangSX,30);
		cout<<"Nhap van toc td: ";
		cin>>vanTocTD;
		cout<<"Nhap namSX: ";
		cin>>namSX;
	}
	
	void inTT(){
		cout<<"+ Hang sx la: "<< hangSX << endl;
		cout<<"+ Van toc td la: "<< vanTocTD << endl;
		cout<<"+ Nam sx la: "<< namSX << endl;
	}
	
};

class TauChien : public Tau
{
	private :
		char loaiTau[30];
		float trongTai;	
		
	public :
		TauChien(const char* hangSX = " ", float vanTocTD = 0.0, int namSX =0, const char* loaiTau = " ", float trongTai = 0.0){
			strcpy(this->loaiTau , loaiTau);
			this->trongTai = trongTai;
		}
		
	~TauChien(){
	}
	
	float getTrongTai(){
		return trongTai;
	}
	
	friend istream &operator >>(istream &is, TauChien &tc){
		tc.Tau::nhapTT();
		cout<<"+ Nhap loai tau :";
		fflush(stdin);
		is.getline(tc.loaiTau, 30);
		cout<<"+ Nhap trong tai :";
		is>>tc.trongTai;
		
		return is;
	}
	
	friend ostream &operator <<(ostream &os, TauChien &tc){
		tc.Tau::inTT();
		os<<"Loai tau la: "<< tc.loaiTau << endl;
		os<<"Trong tai la: "<< tc.trongTai << endl;
		
		return os;
	}
	
	friend bool operator > (TauChien &tc1, TauChien &tc2){
		return tc1.trongTai > tc2.trongTai;
	}
	
	friend bool operator > (TauChien &tc1, int value){
		return tc1.trongTai > value;
	}
	
	int tienSuaChua(){
		if(getNamSx() > 1990){
			return 50000000;
		} else if(getNamSx() > 1990 & getNamSx() < 2000){
			return 30000000;
		} else{
			return 10000000;
		}
	}
};

void nhapTau(Tau t[], int m){
	for(int i = 0; i < m; i++){
		cout<<"Nhap tau thu "<< i + 1 << ":"<< endl;
		t[i].nhapTT();
		cout<<"---------------------------------------------------"<<endl;
	}
}

void inTau(Tau t[], int m){
	for(int i = 0; i < m; i++){
		cout<<"[+] TT tau thu "<< i + 1 << ":"<< endl;
		t[i].inTT();
		cout<<"---------------------------------------------------"<<endl;
	}
}

void nhapTauChien(TauChien tc[], int n){
	for(int i = 0; i < n; i++){
		cout<<"Nhap tau thu "<< i + 1 << ":"<< endl;
		cin >> tc[i];
		cout<<"---------------------------------------------------"<<endl;
	}
}

void inTauChien(TauChien tc[], int n){
	for(int i = 0; i < n; i++){
		cout<<"[+] TT tau thu "<< i + 1 << ":"<< endl;
		cout << tc[i];
		cout<<"---------------------------------------------------"<<endl;
	}
}

void ttLonHon10000(TauChien tc[], int n) {
	for(int i = 0; i < n; i++) {
		if(tc[i] > 10000) {
			cout << tc[i] << endl;
		}else{
			cout<<"null"<<endl;
		}
	}
}

void sapXep(TauChien tc[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(tc[i] > tc[j]) {
				swap(tc[i], tc[j]);
			}
		}
	}
}

void timKiem(TauChien tc[], int n, char* a) {
	for(int i = 0; i < n; i++) {
		if(strcmpi(tc[i].getHangSX(), a) == 0) {
			cout << tc[i] << endl;
		}
	}
}

void themTC(TauChien tc[], int n, int k) {
	if(k >= 1 && k <= n + 1) {
		TauChien tcCanThem;
		cout << "Nhap thong tin tau chien can them: " << endl;
		cin >> tcCanThem;
		for(int i = n; i >= k; i--) {
			tc[i] = tc[i-1];
		}
		tc[k-1] = tcCanThem;
		++n;
		
		cout << "[=] Danh sach tau chien sau khi them: " << endl;
		inTauChien(tc, n);
	} else {
		cout << "Vi tri can them khong hop le !!" << endl;
	}
}

void xoaTC(TauChien	tc[], int n, int k2) {
	if(k2 >= 1 && k2 <= n) {
		for(int i = k2 - 1; i < n; i++) {
			tc[i] = tc[i + 1];
		}
		--n;
 	} else {
	 	cout << "Vi tri can xoa khong hop le !!" << endl;	
 	}
}

int main(){
	int n; 
	do{
		cout<<"Nhap so luong Tau: ";
		cin>>n;
		cin.ignore();
	}while(n <= 0);
	
	TauChien tc[n];
	nhapTauChien(tc, n);
	cout << "[=] Danh sach tau chien sau khi nhap: " << endl;
	inTauChien(tc, n);
	
	int m; 
	do{
		cout<<"Nhap so luong Tau Chien : ";
		cin>>m;
		cin.ignore();
	}while(m <= 0);
	
	Tau t[m];
	nhapTau(t, m);
	cout << "[=] Danh sach tau chien sau khi nhap: " << endl;
	inTau(t, m);
	
	cout << endl << "[=] Danh sach tau chien chong trong tai > 10000: " << endl;
	ttLonHon10000(tc, n);
	
	cout << endl << "[=] Danh sach tau chien theo thu tu tang dan cua trong tai: " << endl;
	sapXep(tc, n);
	inTauChien(tc, n);
	
	cout << endl;
	char a[30];
	cout << "Nhap vao hang san xuat cua tau chien can tim: ";
	fflush(stdin);
	cin.getline(a, 30);
	timKiem(tc, n, a);
	
	cout << endl;
	int k;
	cout << "Nhap vi tri can them vao danh sach tau chien: ";
	cin >> k;
	themTC(tc, n, k);
	
	cout << endl;
	int k2;
	cout << "Nhap vi tri can xoa trong danh sach tau chien: ";
	cin >> k2;
	xoaTC(tc, n, k2);
	cout << "[=] Danh sach tau chien sau khi xoa la: " << endl;
	inTauChien(tc, n);
	
	return 0;
}
