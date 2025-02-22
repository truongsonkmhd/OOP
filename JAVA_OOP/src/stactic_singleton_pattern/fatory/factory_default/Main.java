package stactic_singleton_pattern.fatory.factory_default;

// Main class_oop
public class_oop Main {
    public static void main(String[] args) {
        Animal dog = AnimalFactory.createAnimal("dog");
        Animal cat = AnimalFactory.createAnimal("cat");

        dog.makeSound(); // Output: Woof! Woof!
        cat.makeSound(); // Output: Meow! Meow!
    }
}
