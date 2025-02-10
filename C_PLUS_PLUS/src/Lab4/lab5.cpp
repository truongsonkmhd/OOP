#include <iostream>
#include <cstring>
using namespace std;
//Pham Truong Son - DHTIN16A3

class person {
protected:
    char name[30];
    char address[40];
    long int phone;
public:
    person() {};
    person(char* ten, char* dc, long int sdt) {
        strcpy(name, ten);
        strcpy(address, dc);
        phone = sdt;
    }
};

class officer : private person {
protected:
    float salary;
public:
    officer() {}
    officer(char* ten, char* dc, long int sdt, float sal) : person(ten, dc, sdt) {
        salary = sal;
    }

    bool operator !=(float a) {
        return salary != a;
    }

    char* GetAdd() {
        return address;
    }

    char* getName() {
        return name;
    }

    long int  getPhone() {
        return phone;
    }
    float getSalary(){
        return salary;
    }
};

class manager : public officer {
private:
    float extra;
public:
    manager() {};
    manager(char* ten, char* dc, long int sdt, float sal, float pc) : officer(ten, dc, sdt, sal) {
        extra = pc;
    }
    void xuat() {
        cout << "=================================\n";
        cout << "Name: " << getName() << endl;
        cout << "Phone: " << getPhone() << endl;
        cout <<"Address:" << GetAdd() <<endl;
        cout << "Salary: " << salary << endl;
        cout << "Extra: " << extra << endl;
    }
    bool Kt() {
        if (strcmpi(GetAdd(), "Ha Noi") == 0) {
            return true;
        }
        return false;
    }
};

int main() {
    manager m[5];
    m[0] = manager("Nguyen Van A", "Ha Noi", 12345, 123456, 200);
    m[1] = manager("Nguyen Van B", "Ha Noi", 12346, 123457, 300);
    m[2] = manager("Nguyen thi C","Ho Chi Minh",12345,4329,231);
    m[3] = manager("Nguyen Van D", "Ho Chi Minh", 12346,99999, 231);
    m[4] = manager("Nguyen thi E","Ho Chi Minh",12345,1129,432);
    for(int i = 0;i < 5;i++){
        m[i].xuat();
    }
    cout <<"Danh sach doi tuong can tim la:"<<endl;
    for(int i = 0;i < 5;i++){
        if(m[i].Kt()==1 && m[i].getSalary() != 10000000 ){
            m[i].xuat();
        }
    }
    return 0;
}
