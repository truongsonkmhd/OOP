#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Nguoi{
	private:
		char hoTen[60];
		char ngheNghiep[30];
        char quocTich[30];
		int tuoi;
	
	public:
		Nguoi(const char* hoTen = " ", const char* ngheNghiep = " ", const char* quocTich = " ", int tuoi =0){
			strcpy(this->hoTen, hoTen);
            strcpy(this->ngheNghiep, ngheNghiep);
            strcpy(this->quocTich, quocTich);
			this->tuoi = tuoi;
		}
	
		~Nguoi(){}
	
	const char* getNgheNghiep() {
		return ngheNghiep;
	}
    
    const char* getHoTen() {
        return hoTen;
    }
    
    const char* getQuocTich() {
        return quocTich;
    }
    
    int getTuoi() {
        return tuoi;
    }
		
	void nhapTT() {
    cout << "Nhap tt ho ten :";
    fflush(stdin);
    cin.getline(hoTen, 30);
    cout << "Nhap tt nghe nghiep :";
    cin.getline(ngheNghiep, 30);
    cout << "Nhap tt quoc tich :";
    cin.getline(quocTich, 30);
    cout << "Nhap tuoi: ";
    cin >> tuoi;
	}

	
	void inTT(){
		cout<<"+ Ho ten la: "<< hoTen << endl;
		cout<<"+ Nghe nghiep la: "<< ngheNghiep << endl;
		cout<<"+ Quoc tich la: "<< quocTich << endl;
        cout<<"+ Tuoi la: "<< tuoi << endl;
	}

    friend bool operator > (Nguoi &p1, Nguoi &p2){
		return strcmp(p1.hoTen, p2.hoTen) > 0;
	}
    
    friend bool operator == (Nguoi &p1, Nguoi &p2) {
        return strcmp(p1.hoTen, p2.hoTen) == 0;
    }
};

void nhapTTNguoi(Nguoi p[], int n){
	for(int i = 0; i < n; i++){
		cout<<"Nhap tt nguoi thu "<< i + 1 << ":"<< endl;
		p[i].nhapTT();
		cout<<"---------------------------------------------------"<<endl;
	}
}

void inTTNguoi(Nguoi p[], int n){
	for(int i = 0; i < n; i++){
		cout<<"[+] TT nguoi thu "<< i + 1 << ":"<< endl;
		p[i].inTT();
		cout<<"---------------------------------------------------"<<endl;
	}
}

void sapXepTang(Nguoi p[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(p[i] > p[j]) {
				swap(p[i], p[j]);
			}
		}
	}
}

void timKiemBacSi(Nguoi p[], int n) {
    const char *bacSy = "bac sy";
    cout << "[+] Danh sach nguoi co nghe nghiep la bac sy: " << endl;
	for(int i = 0; i < n; i++) {
		if(strcmpi(p[i].getNgheNghiep(), bacSy) == 0) {
			 p[i].inTT();
		}
	}
}

void xoaNguoiCampuchia(Nguoi p[], int &n) {
    const char *quocTich = "campuchia";
    int i = 0;
    while (i < n) {
        if (strcmpi(p[i].getQuocTich(), quocTich) == 0) {
            for (int j = i; j < n - 1; j++) {
                p[j] = p[j + 1];
            }
            n--;
        } else {
            i++;
        }
    }
}

void chenNguoiLeDaiNghia(Nguoi p[], int &n) {   
    bool kt1 = false;
    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].getHoTen(), "Le Dai Nghia") == 0) {
            kt1 = true;
            p[i].inTT();
           break;
        }
    }

    if (!kt1) {
        Nguoi t;
        cout << "\t\nNhap thong tin cua ban 'Le Dai Nghia' \n";
        t.nhapTT(); 
        p[n] = t; 
        n++; 
        cout << "\n[+] Danh sach sau khi chen nguoi co ho ten Le Dai Nghia: " << endl;
        inTTNguoi(p, n);
    }
}

void timTuoiCaoNhat(Nguoi p[], int n) {
    int maxTuoi = p[0].getTuoi();
    int idxMaxTuoi = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].getTuoi() > maxTuoi) {
            maxTuoi = p[i].getTuoi();
            idxMaxTuoi = i;
        }
    }
    cout << "[+] Nguoi co tuoi cao nhat: " << endl;
    p[idxMaxTuoi].inTT();
}

void timTuoiThapNhat(Nguoi p[], int n) {
    int minTuoi = p[0].getTuoi();
    int idxMinTuoi = 0;
    for (int i = 1; i < n; i++) {
        if (p[i].getTuoi() < minTuoi) {
            minTuoi = p[i].getTuoi();
            idxMinTuoi = i;
        }
    }
    cout << "[+] Nguoi co tuoi thap nhat: " << endl;
    p[idxMinTuoi].inTT();
}

int main(){
	int n; 
	do{
		cout<<"Nhap so luong nguoi: ";
		cin>>n;
		cin.ignore();
	}while(n <= 0);
	
	Nguoi p[n];
	nhapTTNguoi(p, n);
	cout << "[=] Danh sach nguoi sau khi nhap: " << endl;
	inTTNguoi(p, n);
	
    cout << "\n[+] Danh sach theo thu tu tang dan cua ten: " << endl;
	sapXepTang(p, n);
	inTTNguoi(p, n);

    timKiemBacSi(p, n);

    xoaNguoiCampuchia(p, n);
    cout << "\n[+] Danh sach sau khi xoa nguoi co quoc tich Campuchia: " << endl;
    inTTNguoi(p, n);

    chenNguoiLeDaiNghia(p, n);

    timTuoiCaoNhat(p, n);

    timTuoiThapNhat(p, n);

    return 0;
}

