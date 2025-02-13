package interface_practive.da_ke_thua;

// Sub interface
public interface UserService extends BaseService, LogService {

    int addUser(User user);

    void updateUser(User userId);

    void deleteUser(long userId);
}
