package CollectionsPractise.Sets;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Person{
    private int id ;

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    private String name ;

    public Person(int id, String name) {
        this.id = id;
        this.name = name;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                '}';
    }
}

public class ListExample {
    public static void main(String[] args) {

        List<Person> personList = new ArrayList<>() ;
        personList.add(new Person(10 , "Sesh")) ;
        personList.add(new Person(12 , "Sai")) ;
        personList.add(new Person(11 , "Suresh")) ;
        System.out.println(personList);
        Collections.sort(personList , (p1 , p2 ) -> p1.getId()- p2.getId());
        System.out.println(personList);

    }
}
