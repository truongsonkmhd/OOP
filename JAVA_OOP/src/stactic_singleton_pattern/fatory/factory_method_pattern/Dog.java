package stactic_singleton_pattern.fatory.factory_method_pattern;

// Concrete Product 1
class Dog implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }
}
