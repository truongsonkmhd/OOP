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

