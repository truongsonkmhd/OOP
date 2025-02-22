package stactic_singleton_pattern.facade_pattern.movieApp;

public class_oop FacadePatternExample {
    public static void main(String[] args) {
        MovieBookingFacade bookingFacade = new MovieBookingFacade();

        // Đặt vé xem phim
        bookingFacade.bookMovieTicket("Avengers: Endgame", 10, "Credit Card");
        bookingFacade.bookMovieTicket("Inception", 15, "PayPal");
    }
}
