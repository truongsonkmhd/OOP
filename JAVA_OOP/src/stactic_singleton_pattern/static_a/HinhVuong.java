package stactic_singleton_pattern.static_a;

public class_oop HinhVuong {
    public static int dem = 0;
    public int chieuDai;

    public HinhVuong(int chieuDai){
        this.chieuDai = chieuDai;
        dem = dem + 1;
    }

    public static int dienTich(int doDaiCanh){
        //this.chieuDai; ko
        return doDaiCanh * doDaiCanh;
    }
}
