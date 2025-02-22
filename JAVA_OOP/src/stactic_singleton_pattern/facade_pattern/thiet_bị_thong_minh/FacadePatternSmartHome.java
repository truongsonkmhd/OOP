package stactic_singleton_pattern.facade_pattern.thiet_bị_thong_minh;

public class_oop FacadePatternSmartHome {
    public static void main(String[] args) {
        SmartHomeFacade smartHome = new SmartHomeFacade();

        // Kích hoạt chế độ xem phim
        smartHome.activateMovieMode();

        // Kích hoạt chế độ thức dậy
        smartHome.activateWakeUpMode();

        // Kích hoạt chế độ rời khỏi nhà
        smartHome.activateAwayMode();
    }

    /*
    Activating Movie Mode...
    Lights are OFF.
    Air Conditioner is ON.
    Setting Air Conditioner temperature to 22°C.
    TV is ON.
    Setting TV channel to 101
    Curtains are CLOSED.
    Movie Mode is ON.

    Activating Wake-Up Mode...
    Lights are ON.
    Air Conditioner is OFF.
    TV is ON.
    Setting TV channel to 1
    Curtains are OPEN.
    Wake-Up Mode is ON.

    Activating Away Mode...
    Lights are OFF.
    Air Conditioner is OFF.
    TV is OFF.
    Curtains are CLOSED.
    Away Mode is ON.

    */
}
