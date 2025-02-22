package stactic_singleton_pattern.proxy.sample_2;

// 2. Lớp thực tế (Real Subject): Tài liệu quan trọng
class_oop ConfidentialDocument implements Document {
    private String content;

    public ConfidentialDocument(String content) {
        this.content = content;
    }

    @Override
    public void display() {
        System.out.println("Hiển thị tài liệu: " + content);
    }
}
