package stactic_singleton_pattern.facade_pattern.shop_app;

class_oop OnlineShoppingFacade {
    private ProductSearch productSearch;
    private Inventory inventory;
    private PaymentGateway paymentGateway;
    private Shipping shipping;

    public OnlineShoppingFacade() {
        this.productSearch = new ProductSearch();
        this.inventory = new Inventory();
        this.paymentGateway = new PaymentGateway();
        this.shipping = new Shipping();
    }

    public void purchaseProduct(String productName, String paymentMethod, double amount) {
        System.out.println("\nStarting purchase process for: " + productName);

        productSearch.searchProduct(productName);

        if (inventory.checkStock(productName)) {
            paymentGateway.processPayment(paymentMethod, amount);
            shipping.arrangeShipping(productName);
            System.out.println("Purchase completed successfully!\n");
        } else {
            System.out.println("Sorry, " + productName + " is out of stock.\n");
        }
    }
}
