package tren_lop;

abstract class NhanVien {
    protected String maNV;
    protected String hoTen;
    protected double luong;

    public NhanVien(String maNV, String hoTen, double luong) {
        this.maNV = maNV;
        this.hoTen = hoTen;
        this.luong = luong;
    }

    public abstract double tinhThuNhap();

    public double tinhThueThuNhap() {
        double thuNhap = tinhThuNhap();
        if (thuNhap < 9000000) {
            return 0;
        } else if (thuNhap <= 15000000) {
            return thuNhap * 0.1;
        } else {
            return thuNhap * 0.12;
        }
    }

    public String getMaNV() {
        return maNV;
    }

    public String getHoTen() {
        return hoTen;
    }

    public double getLuong() {
        return luong;
    }

    @Override
    public String toString() {
        return "Mã NV: " + maNV + ", Họ tên: " + hoTen + ", Lương: " + luong + ", Thu nhập: " + tinhThuNhap() + ", Thuế: " + tinhThueThuNhap();
    }
}
