package stactic_singleton_pattern.facade_pattern.shop_app;

// Lớp vận chuyển đơn hàng
class Shipping {
    public void arrangeShipping(String productName) {
        System.out.println("Arranging shipping for: " + productName);
    }
}