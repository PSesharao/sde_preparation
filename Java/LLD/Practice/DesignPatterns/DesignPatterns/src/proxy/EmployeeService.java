package proxy;

public interface EmployeeService {

    void create(String client ) throws Exception;
    void delete(String client ) throws Exception;
    String get(String client ) throws Exception;

}
