package stactic_singleton_pattern.singleton_a;

public class_oop Singleton {
    private static Singleton instance = null ;
    public int x;

    private Singleton() {
        this.x = 0;
    }

    public static Singleton getInstance(){
        if(instance == null){
            instance = new Singleton();
        }
        return instance;
    }

    public int getX() {
        return x;
    }

    public void increaseX(){
        this.x += 1;
    }
}
