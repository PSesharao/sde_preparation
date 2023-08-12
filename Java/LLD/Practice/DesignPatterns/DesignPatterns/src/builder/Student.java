package builder;

import java.util.List;

public class Student {

    // required field
    private int rollNumber;

    // required field
    private String name;

    // Required and specific
    private String department ;

    // Required and specific to department
    private List<String> subjects;

    // Optional and null values are accepted if we do not specify
    private String passport ;

    public Student(StudentBuilder studentBuilder){
        this.rollNumber = studentBuilder.rollNumber ;
        this.name = studentBuilder.name ;
        this.department = studentBuilder.department ;
        this.subjects = studentBuilder.subjects ;
        this.passport = studentBuilder.passport ;
    }

    @Override
    public String toString() {
        return "Student{" +
                "rollNumber=" + rollNumber +
                ", name='" + name + '\'' +
                ", department='" + department + '\'' +
                ", subjects=" + subjects +
                ", passport='" + passport + '\'' +
                '}';
    }
}
