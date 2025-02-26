package abtraction;

import java.util.ArrayList;
import java.util.List;

// Lớp chính để chạy chương trình
public class Main {
    public static void main(String[] args) {
        // Tạo danh sách các phương tiện
        List<Vehicle> vehicles = new ArrayList<>();

        // Thêm đối tượng Car và Truck vào danh sách
        Vehicle car = new Car(1, 200, 400, 150);
        Vehicle truck = new Truck(2, 300, 600, 250);

        vehicles.add(car);
        vehicles.add(truck);

        // Đặt màu cho từng phương tiện và hiển thị thông tin
        car.setColor("Red");
        truck.setColor("Blue");

        for (Vehicle v : vehicles) {
            v.displayInfo();
        }
    }
}
