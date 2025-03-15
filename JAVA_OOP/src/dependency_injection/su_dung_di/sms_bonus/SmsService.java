package dependency_injection.su_dung_di.sms;

class SmsService implements MessageService {
    public void sendMessage(String message, String receiver) {
        System.out.println("SMS sent to " + receiver + " with message: " + message);
    }
}
