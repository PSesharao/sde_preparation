package CollectionsPractise.Sets;
import java.util.Map;
import java.util.TreeMap;


public class TreeMapExample {
    public static void main(String[] args) {

        Map<String, Employee> employeeMap = new TreeMap<>() ;

        employeeMap.put( "Sesh" , new Employee(10 , "Sesh")) ;

        employeeMap.put( "Suresh" , new Employee(11 , "Suresh")) ;

        employeeMap.put( "Sai"  , new Employee(12 , "Sai")) ;

        employeeMap.put( "Gopi" , new Employee(13 , "Gopi")) ;

        employeeMap.forEach((k,v)->{
            System.out.println(k + " : " + v);
        });

        employeeMap.entrySet().stream().filter(entry -> entry.getValue().getId()>=12)
                .forEach(entry -> entry.getValue().setId(entry.getValue().getId()*10));

        employeeMap.forEach((k,v)->{
            System.out.println(k + " : " + v);
        });

    }
}
