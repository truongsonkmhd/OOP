package stactic_singleton_pattern.fatory.factory_method_pattern;

// Concrete Creator 2
class CatFactory extends AnimalFactory {
    @Override
    public Animal createAnimal() {
        return new Cat();
    }
}