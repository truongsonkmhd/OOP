package generics;

public class_oop Main {
    public static void main(String[] args) {
        Person<Integer, Integer> person1 = new Person<>(1,20);
        System.out.println("Thong tin person1" + person1.getId() + "-" +person1.getAge());
        Person<Double,Integer> person2 = new Person<>(2.3,40);
        Person<String,String> person3 = new Person<>("dweed","fawefd");
    }
}
