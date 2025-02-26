package interface_practive.cong_dung_chinh;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Tạo danh sách chứa các đối tượng Animal
        List<Animal> animals = new ArrayList<>();

        // Thêm các đối tượng Dog và Cat vào danh sách
        animals.add(new Dog());
        animals.add(new Cat());

        // Duyệt qua danh sách và gọi các phương thức
        for (Animal animal : animals) {
            animal.makeSound(); // Gọi phương thức trừu tượng
            animal.eat();       // Gọi phương thức mặc định
        }
    }
}