package stactic_singleton_pattern.prototype_a.prative2;

public class_oop CloneableDemo {
    public static void main(String[] args) {
        // Tạo một đối tượng gốc
        Person originalPerson = new Person("Alice", 25);

        // Sao chép đối tượng
        Person clonedPerson = originalPerson.clone();

        // Thay đổi thông tin của bản sao
        clonedPerson.setName("Bob");
        clonedPerson.setAge(30);

        // In ra thông tin của các đối tượng
        System.out.println("Original Person: " + originalPerson);
        System.out.println("Cloned Person: " + clonedPerson);
    }
}