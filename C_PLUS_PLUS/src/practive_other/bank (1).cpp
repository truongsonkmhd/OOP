#include <bits/stdc++.h>
#define ll long long

using namespace std;
class bank{
private:
    bool bang_cap = false;
public:
    void info(){
        cout << "ten:"<<name<<endl;
        cout << "matkhau:";
        for(ll i = 0;i < pass.size();i++){
            if(i <= pass.size()-4) cout << '*';
            else cout << pass[i];
        }
        cout << endl;
    }
    void tuthien(){
        system("color 3");
        ll tien_tu_thien;
        cout << "chon so tien ban muon tu thien:";cin >> tien_tu_thien;
        if(tien_tu_thien > money||tien_tu_thien == 0){
            cout << "ngheo ma cung doi tu thien!!!"<<endl;
        }else{
            money -= tien_tu_thien;
            cout <<" chon quy tu thien:"<<endl;
            cout << "1.quy ba nguyen fuong hang"<<endl;
            cout << "2.hoi chu thap do"<<endl;
            cout << "3.mr.best"<<endl;
            int quy;
            cout <<"chon 1 quy:";cin >> quy;
            srand((int)time(0));
            int tile = rand()%100;
            int ung_ho = rand()%100;
            if(tile <= 50){
                cout << " ban tu thien xong"<<endl;
            }else if(tile > 50&&tile <= 80){
                cout << "ban bi lua loc lay mat 50$"<<endl;
                money -= 50;
            }else{
                cout << "ban duoc moi nguoi ung ho "<<ung_ho<<" $"<<endl;
                money += ung_ho;
            }
        }
    }
    void hoctap(){
        if(money - 10 >= 0){
        money -= 10;
        cout << "chao mung ban den truong dai hoc tin hoc"<<endl;
        float res;
        long long res2;
        int trinhdo = 0;
        cout << "de tinh dien tich hinh chu nhat ta lay chieu dai*chieu rong"<<endl;
        srand((int)time(0));
        int a = rand()%100;
        int b = rand()%100;
        cout <<"cho hinh vuong co chieu dai va rong lan luot la "<<a<<','<<b<<endl;
        cout << "nhap dien tich hinh do:";
        cin >> res2;
        if(res2 == a*b){
            cout<<" dung roi"<<endl;
            trinhdo++;
        }else{
            cout << "sai roi,phai la "<<a*b<<endl;
        }
        a = rand()%100;
        cout<<"de tinh dien tich hinh tron, ta lay ban kinh^2*3,14"<<endl;
        cout <<"cho hinh tron, co ban kinh la "<<a<<endl;
        cout << "nhap dien tich hinh do(toi da 6 chu so):";
        cin >> res;

        if(res == pow(a,2)*3.14){
            cout<<" dung roi"<<endl;
            trinhdo++;
        }else{
            cout << "sai roi,phai la "<<pow(a,2)*3.14<<endl;
        }
        if(trinhdo == 2){
            money += 30;
            cout << "ban "<<name<<" do dai hoc!!"<<endl;
            cout << "ban "<<name<<" duoc hoc bong 30$"<<endl;
            bang_cap = true;
        }else{
            cout << "ban "<<name<<" rot"<<endl;
        }
        }else{
            cout << "khong du tien di hoc"<<endl;
        }
    }
    string name;
    bool running = true;
    ~bank(){
        cout <<"ban "<<name<<" dang xuat"<<endl;
    }
    bool matkhauantoana(string matkhau){
        bool a[4] = {false,false,false,false};
        for(char c:matkhau){
            if(isdigit(c)){
                a[0] = true;
            }if('a'<= c&&c <= 'z'){
                a[1] = true;
            }if('A' <= c&&c <= 'Z'){
                a[2] = true;
            }if(c == '@'){
                a[3] = true;
            }
        }
        for(bool b:a){
            if(b == false){
                return false;
            }
        }
        return true;
    }
    void dangky(){
        cout << "nhap ten tai khoan:";getline(cin,this->name);
        cout << "tao mat khau(co chu a-z,A-Z,@,0-9):";cin >> this->pass;
        if(!matkhauantoana(pass)){
            while(!matkhauantoana(pass)){
                cout <<"mat khau chua an toan,vui long nhap lai:";cin >> this->pass;
            }
        }
        cout << "tao tai khoan thanh cong cho "<<name<<endl;
    }
    bank(ll const &money):money(money){}
    void sotien(){
        cout << "so tien cua ban "<<name<<" la:"<<money<<"$"<<endl;
    }
    void kiemtien(){
        int tien = 0;
        int kq;
        cout << "chao mung ban toi tro choi kiem tien"<<endl;
        int n = 10;
        while(n--){
            if(n >= 5){
                srand((int)time(0));
                int a = rand()%100;
                int b = rand()%100;
                cout << a<<'+'<<b<<'=';cin >> kq;
                if(kq == a+b){
                    cout <<"ban dung roi, ban trung 3$"<<endl;
                    money += 3;
                }else{
                    cout <<"ban sai roi"<<endl;
                }
            }else{
                srand((int)time(0));
                int a = rand()%100;
                int b = rand()%100;
                cout << a<<'*'<<b<<'=';cin >> kq;
                if(kq == a*b){
                    cout <<"ban dung roi, ban trung 5$"<<endl;
                    money += 5;
                }else{
                    cout <<"ban sai roi"<<endl;
                }
            }
        }
    }
    void muahang(){
        int so_mat_hang = 2;
        while(so_mat_hang--){
            khodo.push_back(0);
        }
        int hang;
        system("color 2");
        cout << "chao mung ban den voi cho den"<<endl;
        cout << "noi day co nhung mat hang nhu:"<<endl;
        cout << "1.giam 1$ gia ve so(con "<<3-khodo[0]<<" mon):10$"<<endl;
        cout << "2.tang 1 do moi lan su dung dich vu(con "<<5-khodo[1]<<" mon):50$"<<endl;
        cout << "..."<<endl;
        cout << "ban mua cai nao?(chon theo so thu tu):";cin >> hang;
        if(hang == 1 && money >= 10&&3-khodo[0]!=0){
            money -=10;
            cout << "giao dich thanh cong"<<endl;
            cout << "giam 1$ tien ve so"<<endl;
            giamgiave += 1;
            khodo[0]++;
        }else if(hang == 1&&3-khodo[0]== 0){
            cout << "het hang"<<endl;
        }else if(hang == 1&&money < 10){
            cout << "khong du tien";
        }if(hang == 2&&money >=50){
            money -= 50;
            cout << "giao dich thanh cong"<<endl;
            cout << "tang 1$ moi lan su dich vu"<<endl;
            tienthudong += 1;
            khodo[1]++;
        }else if(hang == 2&&money < 50){
            cout << "khong du tien";
        }else if(hang == 2&&5-khodo[1]== 0){
            cout << "het hang"<<endl;
        }
    }
    void veso(){
        if(money -(5-giamgiave)>= 0){
            money =money- (5-giamgiave);
            cout << "thuc hien mua ve so thanh cong !!"<<endl;
            srand((int)time(0));
            int trungso = rand()%100;
            if(trungso <= 50){
                cout << "chuc ban may man lan sau"<<char(1)<<endl;
            }if(trungso > 50 && trungso <= 70){
                cout << "chuc mung ban da trung giai ba"<<char(1)<<endl;
                cout << "ban da trung 3$ trong tai khoan"<<endl;
                money += 3;
            }if(trungso > 70 && trungso <= 90){
                cout << "chuc mung ban da trung giai nhi"<<char(1)<<endl;
                cout << "ban da trung 5$ trong tai khoan"<<endl;
                money += 5;
            }if(trungso > 90 && trungso <= 100){
                cout << "chuc mung ban da trung giai nhat !!"<<char(1)<<endl;
                cout << "ban da trung 10$ trong tai khoan"<<endl;
                money += 10;
            }
        }else{
            cout << "ban khong co du tien de mua, ban con thieu "<<5-giamgiave-money<<'$'<<endl;
        }

    }
    void dichvu(){
        ll lenh;
        cout << "\n-------------------------------------------\n";
        cout << "chao mung ban toi ngan hang tin hoc:|"<<endl;
        cout << "sau day la cac dich vu:             |"<<endl;
        cout << "1.xem so tien                       |"<<endl;
        cout << "2.dang xuat                         |"<<endl;
        cout << "3.cao ve so(mat "<<5-giamgiave<<"$)"<<"\t\t    |"<<endl;
        cout << "4.kiem tien                         |"<<endl;
        cout << "5.mua hang                          |"<<endl;
        cout << "6.di hoc(hoc phi 10$)               |"<<endl;
        cout << "7.xem lai thong tin                 |"<<endl;
        cout << "8.tu thien                          |"<<endl;
        cout << "...."<<endl;
        cout << "\n-------------------------------------------\n";
        cout << "vui long chon dich vu(chon theo so thu tu):";
        cin >> lenh;
        system("cls");
        switch(lenh){
            case 1:
                sotien();
                break;
            case 2:
                running = false;
                break;
            case 3:
                veso();
                break;
            case 4:
                kiemtien();
                break;
            case 5:
                muahang();
                break;
            case 6:
                hoctap();
                break;
            case 7:
                info();
                break;
            case 8:
                tuthien();
                break;
            default:
                cout << "yeu cau sai lam ngan hang bi loi"<<char(176)<<endl;
                running = false;
        }
        money += tienthudong;
        system("color F");
    }
private:
    vector <ll> khodo;
    ll money;
    int giamgiave = 0;
    int tienthudong = 0;
    string pass;
};
int main()
{
    bank *khach = new bank(0);
    cout << "tao tai khoan de su dung ngan hang"<<endl;
    khach->dangky();
    cout <<"so tien hien tai cua ban la 0$"<<endl;
    while(khach->running){
        khach->dichvu();
    }
    delete khach;
    return 0;
}
