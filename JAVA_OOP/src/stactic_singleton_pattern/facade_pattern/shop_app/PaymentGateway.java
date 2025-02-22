package stactic_singleton_pattern.facade_pattern.shop_app;

// Lớp xử lý thanh toán
class PaymentGateway {
    public void processPayment(String paymentMethod, double amount) {
        System.out.println("Processing payment of $" + amount + " via " + paymentMethod);
    }
}