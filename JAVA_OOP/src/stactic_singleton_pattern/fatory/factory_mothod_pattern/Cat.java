package stactic_singleton_pattern.fatory.factory_mothod_pattern;

// Concrete Product 2
class Cat implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }
}