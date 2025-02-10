#include<iostream>
#include<string.h> // char, string
#include<conio.h>// getch()
#include<iomanip> // setw, setpricision
using namespace std;
class sinhVien{
	public:
		char hoTen[20],gioiTinh[20];
		char namSinh[20], diaChi[30];
		char maSv[10], lop[10];
		float tin1, tin2, tin3, tin4, anh1, anh2, DTB;
		
		void nhap();
		void hienThi();
};

void sinhVien::nhap(){
	cin.ignore();
	cout<<"\n Nhap ho ten:"; cin.getline(hoTen,20); fflush(stdin);
	cout<<"\n Nhap gioi tinh:"; cin.getline(gioiTinh,20); fflush(stdin);
	cout<<"\n Nhap nam sinh:"; cin.getline(namSinh,20); fflush(stdin);
	cout<<"\n Nhap dia chi:"; cin.getline(diaChi,30); fflush(stdin);
	cout<<"\n Nhap ma Sv:"; cin.getline(maSv,10); fflush(stdin);
	cout<<"\n Nhap lop:"; cin.getline(lop,10); fflush(stdin);
	cout<<"\n Nhap diem tin 1:";
	cin>>tin1;
	cout<<"\n Nhap diem tin 2:";
	cin>>tin2;
	cout<<"\n Nhap diem tin 3:";
	cin>>tin3;
	cout<<"\n Nhap diem tin 4:";
	cin>>tin4;
	cout<<"\n Nhap diem anh 1:";
	cin>>anh1;
	cout<<"\n Nhap diem anh 2:";
	cin>>anh2;
	cout<<endl;
}

void sinhVien::hienThi(){
	cout<<""<<setw(10)<<hoTen<<setw(8)<<gioiTinh<<setw(10)<<namSinh;
	cout<<""<<setw(11)<<diaChi<<setw(11)<<maSv<<setw(11)<<lop;
	
	cout<<""<<setw(10)<<tin1<<setw(10)<<tin2<<setw(10)<<tin3<<setw(10)<<tin4;
	cout<<""<<setw(10)<<anh1<<setw(10)<<anh2;
	
	DTB = (tin1+tin2+tin3+tin4+anh1+anh2)/6;
	cout<<""<<setw(12)<<DTB;
	cout<<""<<setw(10)<<setprecision(2)<<DTB; // lam tron diemTB
	
	if(DTB>=8)
	{
		cout<<" Xep loai gioi";
	}
	else if(DTB>=7){
		cout<<" Xep loai kha";
	}
	else if(DTB>=5){
		cout<<" Xep loai trung binh";
	}
	else if(DTB < 5){
		cout<<" xep loai yeu";
	}
}

// xaydungchucnangke thua tu lop sinh vien
class quanLySv: public sinhVien
{
	public:
		sinhVien sv[100];
		int n;
		
			void nhap();
			void hienThi();
			void xepLoaiHL();
			void dssvDTBtd();
			void dssvDTBgd();
			void timSvDTBMax();
			void timKiemSv();
};

void quanLySv::nhap()
{
	cout<<"Nhap so luong sinh vien:"; cin>>n;
	for(int i = 0; i<n ; i++){
		cout<<"\n sinh vien thu: "<<i+1<<"";
		sv[i].nhap();
	}
}

void quanLySv::hienThi()
{
	cout<<"\n Ho Ten"<<setw(12)<<"Gioi Tinh"<<setw(11)<<"Nam Sinh"<<setw(12);
	cout<<"Dia chi"<<setw(14)<<"Ma Sinh Vien"<<setw(12)<<"Lop"<<setw(10);
	
	cout<<"Tin1"<<setw(10)<<"Tin2"<<setw(10)<<"Tin3"<<setw(10)<<"Tin4"<<setw(10);
	cout<<"Anh1"<<setw(10)<<"Anh2"<<setw(9)<<"DTB"<<setw(14)<<"DTB lam tron"<<setw(10);
	cout<<endl;
	for(int i = 0; i<n; i++)
	{
		sv[i].hienThi(); // goi phuon thuc hien thi o lop sinh vien
	}
}

void quanLySv::xepLoaiHL()
{
	cout<<"\n";
	cout<<"---\n Sinh vien xep loai hoc luc gioi---"<<endl;
	for(int i=0; i<n;i++){
		if(sv[i].DTB>=8)
		{
			sv[i].hienThi();
		}
	}
	cout<<"\n";
	cout<<"\n--- Sinh vien xep loai hoc luc yeu----"<<endl;
	for(int i = 0; i<n;i++)
	{
		if(sv[i].DTB < 5)
		{
		sv[i].hienThi();	
		}
	}
	
}

void quanLySv::dssvDTBtd()
{
	int i,j;
	sinhVien tg;
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh tang dan---"<<endl;
	for(i = 0; i < n-1; i++)
	{
	  for(j = i+1; j<n;j++)
	  {
	  	if(sv[i].DTB > sv[j].DTB)
	  	tg = sv[i];
	  	sv[i]= sv[j];
	  	sv[j]= tg;
	  }
	}
	cout<<"sau khi sap xep la:"<<endl;
	for(int i = 0; i< n; i++)
	{
		sv[i].hienThi();
	
	}
}

void quanLySv::dssvDTBgd()
{
	int i,j;
	sinhVien tg;
	cout<<"\n";
	cout<<"\n---Danh sach sinh vien co diem trung binh giam dan---"<<endl;
	for(i = 0; i < n-1; i++)
	{
	  for(j = i+1; j<n;j++)
	  {
	  	if(sv[i].DTB < sv[j].DTB)
	  	tg = sv[i];
	  	sv[i]= sv[j];
	  	sv[j]= tg;
	  }
	}
	cout<<"sau khi sap xep la:"<<endl;
	for(int i = 0; i< n; i++)
	{
		sv[i].hienThi();
	
	}
}

void quanLySv::timSvDTBMax()
{
    int max = sv[0].DTB;  // Initialize max with the first student's DTB

    for(int i = 1; i < n; i++)
    {
        if(sv[i].DTB > max)
        {
            max = sv[i].DTB;  // Update max if a larger DTB is found
        }
    }

    cout<<"\n";
    cout<<"\n---Danh sach sinh vien co diem trung binh cao nhat---"<<endl;

    for(int i = 0; i< n; i++)
    {
        if(sv[i].DTB == max)
        {
            sv[i].hienThi();
        }
    }
}

void quanLySv::timKiemSv()
{
    string msv;
    int count = 0;
    cout<<"\n Nhap ma sinh vien can tim: "; fflush(stdin);getline(cin, msv);

    cout<<"\n---Thong tin sinh vien tim duoc---";
    cout<<"\n Ho ten"<<setw(12)<<"Gioi Tinh"<<setw(11)<<"Nam Sinh"<<setw(12);
    cout<<"Dia chi"<<setw(14)<<"Ma Sinh Vien"<<setw(12)<<"Lop"<<setw(10);
    cout<<"Tin1"<<setw(10)<<"Tin2"<<setw(10)<<"Tin3"<<setw(10)<<"Tin4"<<setw(10);
    cout<<"Anh1"<<setw(10)<<"Anh2"<<setw(9)<<"DTB"<<setw(14)<<"DTB lam tron "<< setw(10);

    for(int i = 0; i<n ; i++)
    {
        if(sv[i].maSv == msv)
        {
            sv[i].hienThi();
            count++;
        }
    }

    if(count == 0 )
    {
        cout<<"\n Khong tim thay thong tin sinh vien";
    }
}

int main()
{
    quanLySv QLSV;
    QLSV.nhap();
    QLSV.hienThi();
    QLSV.xepLoaiHL();
    QLSV.dssvDTBtd();
    QLSV.dssvDTBgd();
    QLSV.timSvDTBMax();
    QLSV.timKiemSv();
    getch();
    return 0;
}

