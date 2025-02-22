package stactic_singleton_pattern.facade_pattern.shop_app;

public class_oop FacadePatternShopping {
    public static void main(String[] args) {
        OnlineShoppingFacade shoppingFacade = new OnlineShoppingFacade();

        // Mua sản phẩm "Laptop"
        shoppingFacade.purchaseProduct("Laptop", "Credit Card", 1200.00);

        // Mua sản phẩm "Smartphone"
        shoppingFacade.purchaseProduct("Smartphone", "PayPal", 800.00);
    }
}

