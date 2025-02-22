package stactic_singleton_pattern.proxy.sample_1;

// 3. Proxy: Thư Ký kiểm tra yêu cầu trước khi gửi cho Xếp
class_oop SecretaryProxy implements SalaryRequest {
    private Boss boss;

    public SecretaryProxy(Boss boss) {
        this.boss = boss;
    }

    @Override
    public void requestSalaryIncrease(String devName, double amount) {
        if (amount <= 5) {
            System.out.println("Thư Ký: Yêu cầu của " + devName + " hợp lệ, chuyển đến xếp.");
            boss.requestSalaryIncrease(devName, amount);
        } else {
            System.out.println("Thư Ký: Yêu cầu tăng lương của " + devName + " quá cao, không thể duyệt.");
        }
    }
}