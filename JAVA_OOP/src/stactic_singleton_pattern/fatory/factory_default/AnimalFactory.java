package stactic_singleton_pattern.fatory.factory_default;

// Factory Class để tạo đối tượng động vật
public class AnimalFactory {
    public static Animal createAnimal(String type) {
        if (type.equalsIgnoreCase("dog")) {
            return new Dog();
        } else if (type.equalsIgnoreCase("cat")) {
            return new Cat();
        }
        return null;
    }
}
//=> như kia sẽ vi phạm O trong solid (open-close) khi mình muốn thêm 1 thằng thì p sửa hàm
//=> phải dùng factory_method_pattern