package stactic_singleton_pattern.fatory.factory_mothod_pattern;

public class_oop FactoryMethodPatternDemo {
    public static void main(String[] args) {
        // Tạo đối tượng Dog thông qua DogFactory
        AnimalFactory dogFactory = new DogFactory();
        dogFactory.doSomething();  // Output: Woof!

        // Tạo đối tượng Cat thông qua CatFactory
        AnimalFactory catFactory = new CatFactory();
        catFactory.doSomething();  // Output: Meow!
    }
}
