package stactic_singleton_pattern.facade_pattern.thiet_bị_thong_minh;

class SmartHomeFacade {
    private Light light;
    private AirConditioner airConditioner;
    private TV tv;
    private Curtains curtains;

    public SmartHomeFacade() {
        this.light = new Light();
        this.airConditioner = new AirConditioner();
        this.tv = new TV();
        this.curtains = new Curtains();
    }

    // Chế độ xem phim
    public void activateMovieMode() {
        System.out.println("\nActivating Movie Mode...");
        light.turnOff();
        airConditioner.turnOn();
        airConditioner.setTemperature(22);
        tv.turnOn();
        tv.setChannel(101);
        curtains.close();
        System.out.println("Movie Mode is ON.\n");
    }

    // Chế độ thức dậy
    public void activateWakeUpMode() {
        System.out.println("\nActivating Wake-Up Mode...");
        light.turnOn();
        airConditioner.turnOff();
        tv.turnOn();
        tv.setChannel(1);
        curtains.open();
        System.out.println("Wake-Up Mode is ON.\n");
    }

    // Chế độ rời khỏi nhà
    public void activateAwayMode() {
        System.out.println("\nActivating Away Mode...");
        light.turnOff();
        airConditioner.turnOff();
        tv.turnOff();
        curtains.close();
        System.out.println("Away Mode is ON.\n");
    }
}