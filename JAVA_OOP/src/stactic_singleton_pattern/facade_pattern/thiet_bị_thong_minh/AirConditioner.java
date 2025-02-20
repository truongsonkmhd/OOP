package stactic_singleton_pattern.facade_pattern.thiet_bị_thong_minh;

// Lớp điều khiển điều hòa
class AirConditioner {
    public void turnOn() {
        System.out.println("Air Conditioner is ON.");
    }

    public void turnOff() {
        System.out.println("Air Conditioner is OFF.");
    }

    public void setTemperature(int temperature) {
        System.out.println("Setting Air Conditioner temperature to " + temperature + "°C.");
    }
}