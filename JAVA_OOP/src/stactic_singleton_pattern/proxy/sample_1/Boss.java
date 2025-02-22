package stactic_singleton_pattern.proxy.sample_1;

// 2. Lớp thực tế (Real Subject): Xếp xét duyệt tăng lương
class_oop Boss implements SalaryRequest {
    @Override
    public void requestSalaryIncrease(String devName, double amount) {
        System.out.println("Xếp: Đã duyệt yêu cầu tăng lương cho " + devName + " thêm " + amount + " triệu.");
    }
}