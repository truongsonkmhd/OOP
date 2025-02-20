package stactic_singleton_pattern.facade_pattern.shop_app;

// Lớp kiểm tra tồn kho
class Inventory {
    public boolean checkStock(String productName) {
        System.out.println("Checking stock for: " + productName);
        return true; // Giả sử sản phẩm luôn có sẵn
    }
}