#include <iostream>
#include <cstring>
using namespace std;

class Person {
	protected:
	    char Name[30];
	    char Address[30];
	    int Phone;
	
	public:
	    Person(char* Name = " ", char* Address = " ", int Phone = 0) {
	        strcpy(this->Name, Name);
	        strcpy(this->Address, Address);
	        this->Phone = Phone;
	    }
	
	    char* get_Name() {
	        return this->Name;
	    }
	
	    void nhap() {
	    	fflush(stdin);
	        cout << "Nhap Name: ";
	        cin.getline(this->Name, 30);
	        cout << "Nhap Address: ";
	        cin.getline(this->Address, 30);
	        cout << "Nhap Phone: ";
	        cin >> this->Phone;
	        cin.ignore();
	    }
	
	    void xuat() {
	        cout << "Name: " << this->Name << endl
	             << "Address: " << this->Address << endl
	             << "Phone: " << this->Phone << endl;
	    }
};

class Officer : public Person {
	protected:
	    int Salary;
	
	public:
	    Officer(char* Name = " ", char* Address = " ", int Phone = 0, int Salary = 0)
	        : Person(Name, Address, Phone) {
	        this->Salary = Salary;
	    }
	
	    int get_Salary() {
	        return this->Salary;
	    }
	
	    friend istream& operator >> (istream& is, Officer& a) {
	        a.nhap();
	        fflush(stdin);
	        cout << "Nhap Salary: ";
	        is >> a.Salary;
	        return is;
	    }
	
	    friend ostream& operator << (ostream& os, Officer& a) {
	        a.xuat();
	        os << "Salary: " << a.Salary << endl;
	        return os;
	    }
};

class OffStudent : public Officer {
	protected:
	    int Fee;
	
	public:
	    OffStudent(char* Name = " ", char* Address = " ", int Phone = 0, int Salary = 0, int Fee = 0)
	        : Officer(Name, Address, Phone, Salary) {
	        this->Fee = Fee;
	    }
	
	    friend istream& operator >> (istream& is, OffStudent& c) {
	        Officer& a = c;
	        a.nhap();
	        cout << "Nhap Salary: ";
	        is >> c.Salary;
	        cout << "Nhap Fee: ";
	        is >> c.Fee;
	        return is;
	    }
	
	    friend ostream& operator << (ostream& os, OffStudent& c) {
	        Officer& a = c;
	        a.xuat();
	        os << "Salary: " << c.Salary << endl;
	        os << "Fee: " << c.Fee << endl;
	        return os;
	    }
};

void Salary_Jack(OffStudent c[], int n) {
    for (int i = 0; i < n; i++) {
        if (c[i].get_Salary() == 5000000) {
            cout << c[i];
        }
    }
}

void Sapxep(OffStudent c[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(c[i].get_Name(), c[j].get_Name()) > 0) {
                swap(c[i], c[j]);
            }
        }
    }
}

int main() {
    OffStudent c[100];
    int n;
    cout << "Nhap So Luong Vien Chuc: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    cout << "____________Danh sach sau khi nhap_____________" << endl;
    for (int i = 0; i < n; i++) {
        cout << c[i];
    }
    cout<<"_+_Danh sach Vien Chuc co luong 5000000_+_"<<endl;
    Salary_Jack(c, n);
    Sapxep(c, n);
    cout << "_+_Danh sach sau khi Sap Xep_+_" << endl;
    for (int i = 0; i < n; i++) {
        cout << c[i];
    }
    return 0;
}

