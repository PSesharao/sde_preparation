package builder;

public class BuilderDesignPattern {

    public static void main(String[] args) {
        Student cseStudent  =
                new CSEStudentBuilder(120 , "Seshrao" ).setPassport("KLWW112").build();
        Student eceStudent =
                new ECEStudentBuilder( 121 , "Pankaj").build() ;

        System.out.println(cseStudent);

        System.out.println(eceStudent);

    }

}
