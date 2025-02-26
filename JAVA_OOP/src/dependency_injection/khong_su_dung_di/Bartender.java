package dependency_injection.khong_su_dung_di;

// Lớp Barista phụ thuộc trực tiếp vào Coffee
class Bartender {
    private Coffee coffee = new Coffee(); // Barista tự tạo Coffee (phụ thuộc chặt chẽ) => bắt buộc p là cafe truyền thống

    void makeCoffee() {
        coffee.brew();
    }
}
