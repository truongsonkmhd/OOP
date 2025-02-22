package stactic_singleton_pattern.proxy.sample_1;

// 4. Dev gửi yêu cầu tăng lương
public class_oop ProxyPatternExample {
    public static void main(String[] args) {
        Boss boss = new Boss();
        SalaryRequest secretary = new SecretaryProxy(boss);

        // Dev gửi yêu cầu tăng lương
        secretary.requestSalaryIncrease("John", 3); // Được duyệt
        secretary.requestSalaryIncrease("Mike", 7); // Bị từ chối
    }
}