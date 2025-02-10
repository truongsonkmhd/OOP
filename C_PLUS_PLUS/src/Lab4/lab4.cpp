#include <iostream>
#include <cstring>
using namespace std;
//Pham Truong Son - DHTIN16A3

class AnPham{
    protected:
    char ten[30];
    double gia;
    public:
    void Nhap(){
        cin.ignore();
        cout  <<"Nhap ten:";
        cin.getline(ten,30);
        cout <<"Nhap don gia:";
        cin >> gia;
        cin.ignore();
    }
    void Xuat(){
        cout <<"Ten an pham:"<<ten<<endl;
        cout <<"don gia:"<<gia<<endl;
    }
};
class Sach : public AnPham{
    private:
        int SoTrang;
    public:
        void Nhap(){
        AnPham::Nhap();
        cout <<"Nhap so trang:";
        cin >> SoTrang;
    }
        void Xuat(){
            AnPham::Xuat();
            cout <<"So trang:"<<SoTrang<<endl;
        }
friend void KiemTra(Sach s[],int n){
    for(int i = 0; i < n;i++){
        if(s[i].SoTrang>500){
            s[i].Xuat();
        }
    }
}
};
class Dia:public AnPham{
    private:
        int soPhut;
    public:
        void Nhap(){
            AnPham::Nhap();
            cout <<"Nhap so phut:";
            cin >> soPhut;
        }
        void Xuat(){
            AnPham::Xuat();
            cout<<"So phut:"<<soPhut<<endl;
        }
        int TimTen(char x[]){
            if(strcmp(ten,x)==0){
                return 1;
            }
            return 0;
        }
};
void NhapDia(Dia d[],int m){
    for(int i = 0;i < m;i++){
    d[i].Nhap();
    }
}
void NhapSach(Sach s[],int n){
    for(int i = 0;i < n;i++){
    s[i].Nhap();
    }
}
void TimTen(Dia d[],int m){
    char t[30];
    cin.ignore();
    cout <<"Nhap ten dia can tim:";
    cin.getline(t,30);
    for(int i = 0; i < m;i++){
        if(d[i].TimTen(t)){
                d[i].Xuat();}
    }
}
int main(){
    Sach s[50];
    Dia d[50];
    int n,m;
    cout <<"Nhap so sach:";
    cin >> n;
    NhapSach(s,n);
    cout <<"Sach co so trang > 500"<<endl;
    KiemTra(s,n);
    cin.ignore();
    cout <<"Nhap so dia:";
    cin >> m;
    NhapDia(d,m);
    TimTen(d,m);
    return 0;
}
