package tren_lop;

class_oop NhanVienTiepThi extends NhanVien {
    private double doanhSo;
    private double hueHong;

    public NhanVienTiepThi(String maNV, String hoTen, double luong, double doanhSo, double hueHong) {
        super(maNV, hoTen, luong);
        this.doanhSo = doanhSo;
        this.hueHong = hueHong;
    }

    public void setDoanhSo(double doanhSo) {
        this.doanhSo = doanhSo;
    }

    public void setHueHong(double hueHong) {
        this.hueHong = hueHong;
    }

    public double getDoanhSo() {
        return doanhSo;
    }

    public double getHueHong() {
        return hueHong;
    }

    @Override
    public double tinhThuNhap() {
        return luong + doanhSo * hueHong;
    }
}