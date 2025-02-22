package bieu_thuc_lambda;

public class Cat implements Animal{

    @Override
    public void speak(String lastName, String firstName) {
        System.out.println(lastName + firstName);
    }
}
