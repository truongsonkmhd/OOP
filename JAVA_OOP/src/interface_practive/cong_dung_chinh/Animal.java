package interface_practive.cong_dung_chinh;

interface Animal {
    void makeSound(); // Phương thức trừu tượng

    default void eat() { // Phương thức mặc định có phần thân
        System.out.println("Eating...");
    }
}