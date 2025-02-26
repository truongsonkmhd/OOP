package abtraction;

// Lớp Car kế thừa Vehicle
class Car extends Vehicle {
    public Car(int id, int width, int length, int height) {
        super(id, width, length, height);
    }

    @Override
    void setColor(String color) {
        this.color = color;
        System.out.println("Car color set to " + color);
    }
}
