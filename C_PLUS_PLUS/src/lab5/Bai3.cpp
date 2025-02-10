#include <iostream>
#include <cstring>
using namespace std;

class MayIn {
	protected:
	    char soHieu[30];
	    int soLuong;
	public:
	    MayIn(const char* s = "", int sl = 0) : soLuong(sl) {
	        strcpy(soHieu, s);
	    }
	
	    void nhapKho(int q) {
	        soLuong += q;
	    }
	
	    void xuatKho(int q) {
	        soLuong -= (soLuong >= q) ? q : soLuong;
	    }
	
	    virtual void In() {
	        cout << "May In " << soHieu << " ton " << soLuong << " chiec" << endl;
	    }
};

class MayInLaser : public virtual MayIn {
	protected:
	    int dpi;
	public:
	    MayInLaser(int dpi = 0, const char* s = "") : MayIn(s), dpi(dpi) {}
	
	    void In(){
	        cout << "May in laser " << soHieu << " (" << dpi << " dpi) ton " << soLuong << " chiec" << endl;
	    }
};

class MayInMau : public virtual MayIn {
	protected:
	    int bangMau;
	public:
	    MayInMau(int bm = 0, const char* s = "") : MayIn(s), bangMau(bm) {}
	
	    void In() {
	        cout << "May in mau " << soHieu << " (" << bangMau << " bang mau) ton " << soLuong << " chiec" << endl;
	    }
};

class MayInLaserMau : public MayInLaser, public MayInMau {
	public:
	    MayInLaserMau(int dpi, int bm, const char* s) : MayIn(s), MayInLaser(dpi, s), MayInMau(bm, s) {}
	
	    void In() {
	        cout << "May in laser mau " << soHieu << " (" << dpi << " dpi, " << bangMau << " bang mau) ton " << soLuong << " chiec" << endl;
	    }
};

int main() {
    MayIn s1("Epson", 0);
    MayInLaser s2(600, "HP6");
    MayInMau s3(3, "Apple");
    MayInLaserMau s4(400, 3, "Kodak");

    s1.nhapKho(5);
    s2.nhapKho(7);
    s1.xuatKho(2);
    s3.nhapKho(2);
    s2.xuatKho(3);
    s4.nhapKho(6);

    s1.In();
    s2.In();
    s3.In();
    s4.In();
    return 0;
}
