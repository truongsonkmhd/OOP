package tren_lop;

class TruongPhong extends NhanVien {
    private double luongTrachNhiem;

    public TruongPhong(String maNV, String hoTen, double luong, double luongTrachNhiem) {
        super(maNV, hoTen, luong);
        this.luongTrachNhiem = luongTrachNhiem;
    }

    @Override
    public double tinhThuNhap() {
        return luong + luongTrachNhiem;
    }
}