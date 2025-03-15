Dependency Injection (DI) là gì?
Dependency Injection (DI) là một kỹ thuật trong lập trình nhằm giảm sự phụ thuộc giữa các thành phần trong ứng dụng, giúp code dễ bảo trì, mở rộng và kiểm thử.
Lợi ích của Dependency Injection![Uploading image.png…]()

1.Giảm sự phụ thuộc (Loose Coupling): Các lớp không khởi tạo trực tiếp dependencies của chúng mà nhận chúng từ bên ngoài.
2.Dễ dàng kiểm thử (Testability): Dễ dàng sử dụng các Mock hoặc Stub trong Unit Test.
3.Tái sử dụng mã nguồn (Reusability): Các thành phần có thể được tái sử dụng mà không cần sửa đổi code bên trong.
4.Bảo trì dễ dàng: Khi thay đổi implementation của một dependency, ta chỉ cần thay đổi tại nơi inject.

Ví dụ Dependency Injection trong thực tế bằng Java
1. Không sử dụng Dependency Injection (Coupling cao)

class EmailService {
    public void sendEmail(String message, String recipient) {
        System.out.println("Sending Email to " + recipient + " with message: " + message);
    }
}

class NotificationService {
    private EmailService emailService = new EmailService(); // Coupling cao

    public void sendNotification(String message, String recipient) {
        emailService.sendEmail(message, recipient);
    }
}

2. Áp dụng Dependency Injection

Cách 1: Constructor Injection

interface MessageService {
    void sendMessage(String message, String recipient);
}

class EmailService implements MessageService {
    public void sendMessage(String message, String recipient) {
        System.out.println("Sending Email to " + recipient + " with message: " + message);
    }
}

class NotificationService {
    private final MessageService messageService;

    // Inject dependency qua constructor
    public NotificationService(MessageService messageService) {
        this.messageService = messageService;
    }

    public void sendNotification(String message, String recipient) {
        messageService.sendMessage(message, recipient);
    }
}

public class Main {
    public static void main(String[] args) {
        MessageService emailService = new EmailService();
        NotificationService notificationService = new NotificationService(emailService);
        notificationService.sendNotification("Hello DI!", "example@gmail.com");
    }
}

Cách 2: Sử dụng Spring Dependency Injection
interface MessageService {
    void sendMessage(String message, String recipient);
}

@Component
class EmailService implements MessageService {
    public void sendMessage(String message, String recipient) {
        System.out.println("Sending Email to " + recipient + " with message: " + message);
    }
}

@Component
class NotificationService {
    private final MessageService messageService;

    @Autowired
    public NotificationService(MessageService messageService) {
        this.messageService = messageService;
    }

    public void sendNotification(String message, String recipient) {
        messageService.sendMessage(message, recipient);
    }
}

@Configuration
@ComponentScan(basePackages = "com.example")
class AppConfig {}

public class Main {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(AppConfig.class);
        NotificationService notificationService = context.getBean(NotificationService.class);
        notificationService.sendNotification("Hello Spring DI!", "example@gmail.com");
        context.close();
    }
}

3. Ví dụ với @RequiredArgsConstructor, Khi dùng Lombok, ta không cần viết constructor thủ công.

interface MessageService {
    void sendMessage(String message, String recipient);
}

@Component
class EmailService implements MessageService {
    public void sendMessage(String message, String recipient) {
        System.out.println("Sending Email to " + recipient + " with message: " + message);
    }
}

@Component
@RequiredArgsConstructor // Tự động tạo constructor với các trường final
class NotificationService {
    private final MessageService messageService;

    public void sendNotification(String message, String recipient) {
        messageService.sendMessage(message, recipient);
    }
}

@Configuration
@ComponentScan(basePackages = "com.example")
class AppConfig {}

public class Main {
    public static void main(String[] args) {
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(AppConfig.class);
        
        // Không cần truyền dependencies bằng tay, Spring sẽ tự động inject
        NotificationService notificationService = context.getBean(NotificationService.class);
        notificationService.sendNotification("Hello Lombok DI!", "example@gmail.com");
        
        context.close();
    }
}
