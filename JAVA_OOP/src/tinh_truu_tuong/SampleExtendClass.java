package tinh_truu_tuong;

// class_oop extends từ abstract class_oop
public class_oop SampleExtendClass extends SampleAbstractClass {
    @Override // Ghi đè phương thức abstract method
    public void sayHello() {
        System.out.println("Hello, Tay Java");
    }

    @Override // Ghi đè phương thức non-abstract method
    public int calculate(int a, int b) {
        return a * b;
    }
}