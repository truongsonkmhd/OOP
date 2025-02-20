package stactic_singleton_pattern.fatory;

// Main class
public class Main {
    public static void main(String[] args) {
        Animal dog = AnimalFactory.createAnimal("dog");
        Animal cat = AnimalFactory.createAnimal("cat");

        dog.makeSound(); // Output: Woof! Woof!
        cat.makeSound(); // Output: Meow! Meow!
    }
}
