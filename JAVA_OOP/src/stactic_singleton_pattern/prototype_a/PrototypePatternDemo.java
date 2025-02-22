package stactic_singleton_pattern.prototype_a;

public class_oop PrototypePatternDemo {
    public static void main(String[] args) {
        // Tạo một đối tượng gốc
        Shape circle = new Shape("Circle");

        // Sao chép đối tượng gốc
        Shape clonedCircle = (Shape) circle.clone();

        // Thay đổi thuộc tính của đối tượng sao chép
        clonedCircle.setType("Cloned Circle");

        // In ra thông tin của các đối tượng
        System.out.println("Original Shape: " + circle);
        System.out.println("Cloned Shape: " + clonedCircle);
    }
}