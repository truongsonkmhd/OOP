package dependency_injection.su_dung_di;

public class Main {
    public static void main(String[] args) {
        Coffee bacXiu = new bacXiu(); // Chọn loại cà phê
        cafeTrungNguyen cfTrungNguyen = new cafeTrungNguyen();
        cafeLotte cfLotte = new cafeLotte();
        Bartender bartender = new Bartender(cfLotte); // ta có thể tiêm bao nhiêu tuỳ thích, không bị gò bó vào 1 đối tượng
        bartender.makeCoffee(); // Đang pha Espresso...
    }
}
