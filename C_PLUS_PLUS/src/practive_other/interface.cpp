#include<iostream>
using namespace std;

class CongDan
{
	protected:
		string so_cccd;
		string ho_ten;
		int tuoi;
		
	public:
		CongDan(string so_cccd, string ho_ten, int tuoi){
			this->so_cccd = so_cccd;
			this->ho_ten = ho_ten;
			this->tuoi = tuoi;
		}
		
	~CongDan(){
	}
	
	string getCCCD(){
		return so_cccd;
	}
	
	void virtual nhapThongTin()
	{
		cout<<"\n Nhap cccd:";
		getline(cin,so_cccd);
		cout<<"Nhap ho ten:";
		getline(cin,ho_ten);
		cout<<"Nhap so tuoi:";
		cin>>tuoi;
	}
	
	void virtual inThongTin()
	{
		cout<<"\n So cccd la:"<<so_cccd<<endl;
		cout<<"Ho ten la: "<<ho_ten<<endl;
		cout<<"Tuoi la: "<< tuoi <<endl;
	}
};

class HocSinh : public CongDan
{
	private: 
		float diem_toan;
		float diem_van;
		
	public:
		HocSinh(string so_cccd="",string ho_ten = "", int tuoi = 1, float diem_toan = 1.0f, float diem_van = 1.0f)
		: CongDan(so_cccd,ho_ten,tuoi)
		{
			this->diem_toan = diem_toan;
			this->diem_van = diem_van;
			
		}
		
		~HocSinh(){
		}
		
		void nhapThongTin()
		{
			CongDan::nhapThongTin();
			cout<<"\nNhap diem toan: ";
			cin>>diem_toan;
			cout<<"Nhap diem van: ";
			cin>>diem_van;
			cin.ignore();
		}
		
		void inThongTin()
		{
			CongDan::inThongTin();
			cout<<"\n Diem toan la: "<< diem_toan;
			cout<<"\n Diem van la: "<< diem_van;
		}
		
};

class GiaoVien: public CongDan
{
	private:
		string chuyen_nganh;
		float hsl;
	public:
		GiaoVien(string so_cccd="",string ho_ten = "", int tuoi = 1, string chuyen_nganh = "", float hsl=1.0f)
		:CongDan(so_cccd,ho_ten,tuoi){
			this->chuyen_nganh = chuyen_nganh;
			this->hsl = hsl;
		}
		
		~GiaoVien(){
		}
		
		void nhapThongTin()
		{
			CongDan::nhapThongTin();
			cout<<"\nNhap chuyen nganh: ";
			cin>>chuyen_nganh;
			cout<<"Nhap hsl: ";
			cin>>hsl;
			cin.ignore();
		}
		
		void inThongTin()
		{
			CongDan::inThongTin();
			cout<<"\n chuyen nganh la: "<< chuyen_nganh;
			cout<<"\n hsl la: "<< hsl;
		}	
};

void nhapDanhSachHocSinh(CongDan *cd[], int m){
	for(int i= 0; i<m;i++){
		cd[i] = new HocSinh();
		cd[i]->nhapThongTin();
	}
}

void inDanhSachHocSinh(CongDan *cd[],int m){
		for(int i= 0; i<m;i++){
			cd[i]->inThongTin();
		}
}

void inDsHsinhCCCDnhoHon(CongDan *cd[],int m){
	int dem = 0;
		for(int i= 0; i<m;i++){
			if(cd[i]->getCCCD()<"1234")
			dem++;
		if(dem == 0)
			cout<<"Khong co hs nao co so cccd<1234\n";
		else 
				for(int i= 0; i<m;i++){
					if(cd[i]->getCCCD()< "1234")
					cd[i]->inThongTin();
				}
			}
}
int main()
{
	int m;
	do{
		cout<<"Nhap so luong hoc sinh m =";
		cin>>m;
		cin.ignore();
	}while(m<=0);
	CongDan *p[30];
	
	cout<<"\n------------------------------------------------------------\n";
	cout<<"Nhap danh sach hoc sinh: \n";
	nhapDanhSachHocSinh(p,m);
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"In danh sach hoc sinh: \n";
	inDanhSachHocSinh(p,m);
	cout<<"\n-----------------------------------------------------------\n";
	cout<<"In danh sach hoc sinh co cccd< 1234: \n";
	inDsHsinhCCCDnhoHon(p,m);
}

