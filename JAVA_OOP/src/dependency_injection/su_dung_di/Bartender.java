package dependency_injection.su_dung_di;

public class Bartender {
    private Coffee coffee;

    // Inject Coffee vào Barista qua constructor
    public Bartender(Coffee coffee) {
        this.coffee = coffee;
    }

    void makeCoffee() {
        coffee.brew();
    }
}
