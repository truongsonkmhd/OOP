package stactic_singleton_pattern.facade_pattern.movieApp;

class TicketManager {
    public void generateTicket(String movie, int seatNumber) {
        System.out.println("Generating ticket for movie: " + movie + " at seat number: " + seatNumber);
    }
}