package stactic_singleton_pattern.proxy.sample_1;

// 1. Định nghĩa giao diện chung cho Proxy và Real Subject
interface SalaryRequest {
    void requestSalaryIncrease(String devName, double amount);
}