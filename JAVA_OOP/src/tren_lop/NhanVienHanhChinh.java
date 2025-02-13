package tren_lop;

class NhanVienHanhChinh extends NhanVien {
    public NhanVienHanhChinh(String maNV, String hoTen, double luong) {
        super(maNV, hoTen, luong);
    }

    @Override
    public double tinhThuNhap() {
        return luong;
    }
}
