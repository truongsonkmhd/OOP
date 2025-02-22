package stactic_singleton_pattern.facade_pattern.movieApp;

class SeatChecker {
    public boolean checkAvailability(int seatNumber) {
        System.out.println("Checking seat availability for seat number: " + seatNumber);
        return true; // Giả sử chỗ luôn có sẵn
    }
}
