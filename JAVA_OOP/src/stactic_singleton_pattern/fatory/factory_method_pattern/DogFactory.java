package stactic_singleton_pattern.fatory.factory_method_pattern;

class DogFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() {
        return new Dog();
    }
}