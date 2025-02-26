package interface_practive.cong_dung_chinh;

// Lớp Cat thực thi interface Animal
class Cat implements Animal {
    @Override
    public void makeSound() {
        System.out.println("Meow! Meow!");
    }
}