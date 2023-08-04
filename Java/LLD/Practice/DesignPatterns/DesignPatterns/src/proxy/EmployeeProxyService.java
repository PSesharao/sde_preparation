package proxy;

public class EmployeeProxyService implements EmployeeService{

    EmployeeService employeeService ;

    EmployeeProxyService(){
        employeeService = new EmployeeConcreteService() ;
    }


    @Override
    public void create(String client) throws Exception {
        if(client.equals("ADMIN")){
            employeeService.create( client );
        }else {
            throw new Exception("Access Denied") ;
        }
    }

    @Override
    public void delete(String client) throws Exception {
        if(client.equals("ADMIN")){
            employeeService.delete( client );
        }else {
            throw new Exception("Access Denied") ;
        }
    }

    @Override
    public String get(String client) throws Exception {
        if(client.equals("ADMIN") || client.equals("USER") ){
            return employeeService.get( client );
        }else {
            throw new Exception("Access Denied") ;
        }
    }
}
