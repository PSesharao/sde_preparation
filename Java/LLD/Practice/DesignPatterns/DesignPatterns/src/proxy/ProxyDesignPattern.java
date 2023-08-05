package proxy;

public class ProxyDesignPattern {

    public static void main(String[] args) {
        EmployeeService employeeService = new EmployeeProxyService();

        try {
            employeeService.create("ADMIN");
            employeeService.delete("ADMIN");
            System.out.println(employeeService.get("USER1"));
            employeeService.create("USER");
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

}
