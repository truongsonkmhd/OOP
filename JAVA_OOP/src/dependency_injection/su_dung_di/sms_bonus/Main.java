package dependency_injection.su_dung_di.sms;

public class Main {
    public static void main(String[] args) {
        // Inject EmailService vào MessageSender
        MessageSender emailSender = new MessageSender(new EmailService());
        emailSender.send("Hello via Email!", "user@example.com");

        // Inject SmsService vào MessageSender
        MessageSender smsSender = new MessageSender(new SmsService());
        smsSender.send("Hello via SMS!", "123456789");
    }
}
