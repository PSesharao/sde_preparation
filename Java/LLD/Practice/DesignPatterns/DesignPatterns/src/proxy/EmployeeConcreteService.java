package proxy;

public class EmployeeConcreteService implements EmployeeService{
    @Override
    public void create(String client ) {
        System.out.println("Created new row ");
    }

    @Override
    public void delete(String client ) {
        System.out.println("Deleted a row");
    }

    @Override
    public String get(String client ) {
        return "Employee details";
    }
}
