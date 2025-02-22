package interface_practive.da_ke_thua;

// class_oop UserServiceImpl implements (thực thi) interface UserService và CommonService
public class UserServiceImpl implements UserService, CommonService {

    @Override
    public int addUser(User user) {
        System.out.println("-----[ addUser ]-----");
        return 0;
    }

    @Override
    public void updateUser(User userId) {
        System.out.println("-----[ updateUser ]-----");
    }

    @Override
    public void deleteUser(long userId) {
        System.out.println("-----[ deleteUser ]-----");
    }

    @Override
    public void saveLog() {
        System.out.println("-----[ saveLog ]-----");
    }

    @Override
    public void printLog() {
        System.out.println("-----[ printLog ]-----");
    }

    @Override
    public void connectDB() {
        System.out.println("-----[ connectDB ]-----");
    }
}