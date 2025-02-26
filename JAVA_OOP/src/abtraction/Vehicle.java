package abtraction;
import java.util.ArrayList;
import java.util.List;

// Lớp trừu tượng Vehicle
public abstract class Vehicle {
    int id;
    int width;
    int length;
    int height;
    String color;
    int x, y;
    String status;

    // Constructor
    public Vehicle(int id, int width, int length, int height) {
        this.id = id;
        this.width = width;
        this.length = length;
        this.height = height;
        this.x = 0;
        this.y = 0;
    }

    // Phương thức trừu tượng (phải được triển khai bởi lớp con)
    abstract void setColor(String color);

    // Phương thức có sẵn phần thân
    protected void setWidth(int width) {
        this.width = width;
    }

    public void displayInfo() {
        System.out.println("Vehicle ID: " + id + ", Color: " + color);
    }
}

