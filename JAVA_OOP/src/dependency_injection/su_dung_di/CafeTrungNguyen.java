package dependency_injection.su_dung_di;

// Triển khai các loại cà phê khác nhau
class cafeTrungNguyen implements Coffee {
    public void brew() {
        System.out.println("Đang pha cà phê trung nguyên...");
    }
}