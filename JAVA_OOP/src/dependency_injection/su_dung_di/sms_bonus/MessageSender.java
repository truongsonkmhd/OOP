package dependency_injection.su_dung_di.sms;

class MessageSender {
    private MessageService messageService;

    // Constructor Injection
    public MessageSender(MessageService messageService) {
        this.messageService = messageService;
    }

    public void send(String message, String receiver) {
        messageService.sendMessage(message, receiver);
    }
}
