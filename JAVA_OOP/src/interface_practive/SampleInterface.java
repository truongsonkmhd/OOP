package interface_practive;

import java.time.LocalDate;
//@FunctionalInterface // nếu dùng thằng này thì chỉ có 1 abstract methods
public interface SampleInterface {
    // là 1 kịch bản tạo ra các class , để hỗ trợ việc kế thừa trong java
    // constant fields // ko thể thay đỏi giá trị, ko overrive đc
    String name = "Tây Java";

    // abstract methods
    void method1();

    int method2();

    String methodN();

    // default method
    default void sayHello() {
        System.out.println("Đây là sample interface");
    }

    // static method
    static String getCurrentTime(){
        return String.valueOf(LocalDate.now());
    }
}



