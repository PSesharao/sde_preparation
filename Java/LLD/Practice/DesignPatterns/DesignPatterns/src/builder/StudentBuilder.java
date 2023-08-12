package builder;

import java.util.List;

public abstract class StudentBuilder {

     final int rollNumber;

     final String name;

     String department ;

     List<String> subjects;

     String passport ;

    // Make the required fields as final so that we could force initialize them using constructor

    protected StudentBuilder(int rollNumber, String name) {
        this.rollNumber = rollNumber;
        this.name = name;
    }

    public abstract StudentBuilder setPassport(String passport) ;

    public abstract Student build() ;


}
