package stactic_singleton_pattern.static_a;

public class Main {
    public static void main(String[] args) {
        HinhVuong hv1 = new  HinhVuong(1);
        HinhVuong hv2 = new HinhVuong(2);
        HinhVuong hv3 = new HinhVuong(3);
        System.out.println(HinhVuong.dem);
        // => dem = 3
        HinhVuong.dem++;
        System.out.println(HinhVuong.dem);

        System.out.println(HinhVuong.dienTich(3));
    }
}

/*
* Instance (non-static) là các thành phần (biến, phương thức) thuộc về một đối tượng cụ thể (object) của lớp.
* VD: HinhVuong hv1 = new  HinhVuong(1);
* */


/*
*
* Thuộc về lớp, không thuộc về thể hiện:

Static method được gọi trực tiếp từ lớp mà không cần tạo đối tượng (instance) của lớp.

Ví dụ: ClassName.staticMethod().

*Không thể truy cập thành viên không tĩnh:

Static method không thể truy cập trực tiếp các biến instance (non-static) hoặc phương thức instance (non-static) vì chúng yêu cầu một thể hiện cụ thể của lớp.

Static method chỉ có thể truy cập các biến tĩnh (static variables) hoặc phương thức tĩnh (static methods) khác.

*Không có từ khóa this:

Vì static method không liên quan đến thể hiện cụ thể, từ khóa this không tồn tại trong static method.

*Được khởi tạo khi lớp được tải:

Static method được khởi tạo và tồn tại trong bộ nhớ ngay khi lớp được tải (load) bởi ClassLoader (trong Java) hoặc trình thông dịch (trong các ngôn ngữ khác).

Tiết kiệm bộ nhớ:

*/