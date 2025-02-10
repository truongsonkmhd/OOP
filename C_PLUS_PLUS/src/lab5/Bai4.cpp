#include <iostream>
#include <cstring>
using namespace std;

class Student {
	protected:
	    char Ma[30];
	    char Ht[30];
	    bool gt;
	
	public:
	    Student(char* Ma = " ", char* Ht = " ", bool gt = false) {
	        strcpy(this->Ma, Ma);
	        strcpy(this->Ht, Ht);
	        this->gt = gt;
	    }
	
	    bool tgt() {
	        return gt == false ? "Nam" : "Nu";
	    }
	
	    bool get_gt() {
	        return this->gt;
	    }
	
	    char* get_ht() {
	        return this->Ht;
	    }
	
	    void nhap() {
	    	fflush(stdin);
	        cout << "Nhap Ma SV: ";
	        cin.getline(this->Ma, 30);
	        fflush(stdin);
	        cout << "Nhap Ho va Ten: ";
	        cin.getline(this->Ht, 30);
	        cout << "Nhap Gioi Tinh: " << endl
	             << "0:Nam" << endl
	             << "1:Nu" << endl;
	        cin >> gt;
	        fflush(stdin);
	    }
	
	    void xuat() {
	        cout << "MSV: " << this->Ma << endl
	             << "Ho va Ten: " << this->Ht << endl
	             << "Gioi Tinh: " << tgt() << endl;
	    }
};

class MonHoc {
	protected:
	    char Ma_M[30];
	    char Ten_M[30];
	
	public:
	    MonHoc(char* Ma_M = " ", char* Ten_M = " ") {
	        strcpy(this->Ma_M, Ma_M);
	        strcpy(this->Ten_M, Ten_M);
	    }
	
	    char* get_Ten_M() {
	        return this->Ten_M;
	    }
	
	    friend istream& operator >> (istream& is, MonHoc& a) {
	        cout << "Nhap Ma Mon: ";
	        is.getline(a.Ma_M, 30);
	        cout << "Nhap Ten Mon: ";
	        is.getline(a.Ten_M, 30);
	        return is;
	    }
	
	    friend ostream& operator << (ostream& os, MonHoc& a) {
	        os << "Ma Mon: " << a.Ma_M << endl
	           << "Ten Mon: " << a.Ten_M << endl;
	        return os;
	    }
};

class Diemmh : public Student, public MonHoc {
	private:
	    int diemthi;
	public:
	    Diemmh(char* Ma = " ", char* Ht = " ", bool gt = false, char* Ma_M = " ", char* Ten_M = " ", int diem = 0)
	        : Student(Ma, Ht, gt), MonHoc(Ma_M, Ten_M) {
	        this->diemthi = diem;
	    }
	
	    int get_diemthi() {
	        return this->diemthi;
	    }
	
	    friend istream& operator >> (istream& is, Diemmh& b) {
	        Student& s = b;
	        MonHoc& m = b;
			s.nhap();
			fflush(stdin);
	        is >> m;
	        cout << "Nhap Diem Thi: ";
	        is >> b.diemthi;
	        fflush(stdin);
	        return is;
	    }
	    friend ostream& operator << (ostream& os, Diemmh& b) {
	        Student& s = b;
	        MonHoc& a = b;
	        s.xuat();
	        os << a;
	        os << "Diem Thi: " << b.diemthi << endl;
	        return os;
	    }
};

void gtnam(Diemmh b[], int n) {
    for (int i = 0; i < n; i++) {
        if (b[i].get_gt() == false) {
            cout << b[i];
        }
    }
}

void dtb(Diemmh b[], int n) {
    float tdtbinh = 0;
    float dtbinh = 0;
    for (int i = 0; i < n; i++) {
        tdtbinh += b[i].get_diemthi();
        dtbinh=tdtbinh/n;
    }
    cout << dtbinh;
}

void tim(Diemmh b[], int n, char* find) {
    for (int i = 0; i < n; i++) {
        if (strcmp(find, b[i].get_ht()) == 0) {
            cout << b[i].get_Ten_M();
            cout << b[i].get_diemthi() << endl;
        }
    }
}

void sapxep(Diemmh b[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (b[i].get_diemthi() < b[j].get_diemthi()) {
                swap(b[i], b[j]);
            }
        }
    }
}

int main() {
    Diemmh b[100];
    int n;
    cout << "Nhap So Luong Student: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    cout << "_________________Danh sach sau khi nhap______________" << endl;
    for (int i = 0; i < n; i++) {
        cout << b[i];
    }
    cout << "_+_Danh sach Student co gioi tinh la Nam_+_" << endl;
    gtnam(b, n);
    cout << "DTB:" << endl;
    dtb(b, n);
    cout<<endl;
    char find[30];
    cout << "_+_Nhap Ten Doi Tuong Can Tim: " << endl;
    cin.getline(find, 30);
    fflush(stdin);
    tim(b, n, find);
    sapxep(b, n);
    cout << "__________Danh sach sau khi sap xep_________" << endl;
    for(int i=0;i<n;i++){
    	cout<<b[i];
	}
    return 0;
}

