package abtraction;

// Lớp Truck kế thừa Vehicle
class Truck extends Vehicle {
    public Truck(int id, int width, int length, int height) {
        super(id, width, length, height);
    }

    @Override
    void setColor(String color) {
        this.color = color;
        System.out.println("Truck color set to " + color);
    }
}
