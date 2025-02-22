package stactic_singleton_pattern.proxy.sample_2;

// 3. Proxy kiểm soát quyền truy cập vào tài liệu
class_oop DocumentProxy implements Document {
    private ConfidentialDocument document;
    private String userRole; // Chức vụ của người dùng

    public DocumentProxy(String content, String userRole) {
        this.document = new ConfidentialDocument(content);
        this.userRole = userRole;
    }

    @Override
    public void display() {
        if ("Manager".equals(userRole) || "Admin".equals(userRole)) {
            System.out.println("Proxy: Kiểm tra quyền truy cập...");
            document.display();
        } else {
            System.out.println("Proxy: Bạn không có quyền truy cập vào tài liệu này.");
        }
    }
}
