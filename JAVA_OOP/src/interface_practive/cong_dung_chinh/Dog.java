package interface_practive.cong_dung_chinh;

// Lớp Dog thực thi interface Animal
class Dog implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof! Woof!");
    }
}