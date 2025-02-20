package stactic_singleton_pattern.proxy.sample_2;

// 4. Kiểm thử hệ thống
public class ProxyPatternExample {
    public static void main(String[] args) {
        // Nhân viên bình thường muốn truy cập tài liệu
        Document doc1 = new DocumentProxy("Báo cáo tài chính 2024", "Employee");
        doc1.display();

        // Quản lý muốn truy cập tài liệu
        Document doc2 = new DocumentProxy("Báo cáo tài chính 2024", "Manager");
        doc2.display();
    }
}