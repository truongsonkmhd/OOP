package stactic_singleton_pattern.facade_pattern.thiet_bị_thong_minh;

// Lớp điều khiển TV
class TV {
    public void turnOn() {
        System.out.println("TV is ON.");
    }

    public void turnOff() {
        System.out.println("TV is OFF.");
    }

    public void setChannel(int channel) {
        System.out.println("Setting TV channel to " + channel);
    }
}