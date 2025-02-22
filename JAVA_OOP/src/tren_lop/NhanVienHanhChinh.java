package tren_lop;

class_oop NhanVienHanhChinh extends NhanVien {
    public NhanVienHanhChinh(String maNV, String hoTen, double luong) {
        super(maNV, hoTen, luong);
    }

    @Override
    public double tinhThuNhap() {
        return luong;
    }
}
