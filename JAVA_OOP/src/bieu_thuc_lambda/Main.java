package bieu_thuc_lambda;

public class_oop Main {
    public static void main(String[] args) {
        Animal meo1 = new Cat();
        meo1.speak("go","go");

        Animal meo2 = (firstname, lastName) -> System.out.println(firstname + lastName);
        meo2.speak("go", "go");
    }
}
