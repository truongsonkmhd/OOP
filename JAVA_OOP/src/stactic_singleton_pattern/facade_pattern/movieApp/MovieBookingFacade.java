package stactic_singleton_pattern.facade_pattern.movieApp;

// Lớp Facade để đơn giản hóa quy trình đặt vé
class_oop MovieBookingFacade {
    private SeatChecker seatChecker;
    private PaymentProcessor paymentProcessor;
    private TicketManager ticketManager;

    public MovieBookingFacade() {
        this.seatChecker = new SeatChecker();
        this.paymentProcessor = new PaymentProcessor();
        this.ticketManager = new TicketManager();
    }

    public void bookMovieTicket(String movie, int seatNumber, String paymentMethod) {
        if (seatChecker.checkAvailability(seatNumber)) {
            paymentProcessor.processPayment(paymentMethod);
            ticketManager.generateTicket(movie, seatNumber);
            System.out.println("Booking successful!\n");
        } else {
            System.out.println("Sorry, the seat is not available.\n");
        }
    }
}
