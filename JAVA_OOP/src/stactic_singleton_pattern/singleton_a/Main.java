package stactic_singleton_pattern.singleton_a;

public class_oop Main {
    public static void main(String[] args) {
        Singleton se = Singleton.getInstance();
        se .increaseX();
        se .increaseX();
        se .increaseX();
        System.out.println(se.getX());

        Singleton se2 = Singleton.getInstance();
        System.out.println(se2.getX());

        se2.increaseX();
        System.out.println(se2.getX());
        System.out.println(se.getX());
    }
}
