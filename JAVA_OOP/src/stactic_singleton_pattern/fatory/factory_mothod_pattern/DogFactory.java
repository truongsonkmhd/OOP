package stactic_singleton_pattern.fatory.factory_mothod_pattern;

class_oop DogFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() {
        return new Dog();
    }
}