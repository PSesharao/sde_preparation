package CollectionsPractise.Sets;

import java.util.Set;
import java.util.TreeSet;

class Employee implements Comparable<Employee>{
    private int id ;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    private String name ;

    public Employee(int id , String name) {
        this.id = id ;
        this.name = name ;
    }

    @Override
    public int compareTo(Employee obj ) {
        return obj.id - this.id;
        //return 0 ;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}

public class TreeSetExample {

    public static void main(String[] args) {

        Set<Employee> employees = new TreeSet<>();

        employees.add(new Employee(10 , "Sesh")) ;

        employees.add(new Employee(11 , "Suresh")) ;

        employees.add(new Employee(12 , "Sai")) ;

        employees.add(new Employee(13 , "Gopi")) ;

        employees.add(new Employee(10 , "Sesh")) ;

        System.out.println(employees);

        for(Employee employee : employees){
            System.out.println(employee);
        }

    }

}
