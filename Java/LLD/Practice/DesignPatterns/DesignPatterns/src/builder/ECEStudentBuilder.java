package builder;

import java.util.ArrayList;
import java.util.List;

public class ECEStudentBuilder extends StudentBuilder{
    protected ECEStudentBuilder(int rollNumber, String name) {

        super(rollNumber, name);
        this.department = "ECE" ;
        List<String> subs = new ArrayList<>();
        subs.add("Embedded");
        subs.add("Java");
        subs.add("DLD");
        this.subjects = subs;

    }

    @Override
    public StudentBuilder setPassport(String passport) {
        this.passport = passport ;
        return this ;
    }

    @Override
    public Student build() {
        return new Student(this);
    }
}
