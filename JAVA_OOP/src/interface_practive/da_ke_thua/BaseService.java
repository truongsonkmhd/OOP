package interface_practive.da_ke_thua;

public interface BaseService {

    default void printMessage() {
        System.out.println("Default message from BaseService");
    }
}

