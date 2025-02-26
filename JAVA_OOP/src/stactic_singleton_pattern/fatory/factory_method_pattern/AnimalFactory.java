package stactic_singleton_pattern.fatory.factory_method_pattern;

// Creator abstract class_oop
abstract class AnimalFactory {
    // Factory Method (abstract)
    public abstract Animal createAnimal();

    // Method sử dụng đối tượng được tạo bởi Factory Method
    public void doSomething() {
        Animal animal = createAnimal();
        animal.makeSound();
    }
}