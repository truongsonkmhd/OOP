package dependency_injection.su_dung_di.sms;

class EmailService implements MessageService {
    public void sendMessage(String message, String receiver) {
        System.out.println("Email sent to " + receiver + " with message: " + message);
    }
}
