import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class JavaMain {
    
    private static FastReader in;
    private static FastWriter out ;

    public static void main(String[] args) throws IOException  {
        initialize(); 

        List<String> words = 
        Arrays.asList("Apple", "Java17", "Banana", "Stream API");


        String ans =
        words
        .stream()
        .filter( word -> word.chars().
            noneMatch( ch -> Character.isDigit(ch) ) )
        .max( (word1,word2) 
            -> Integer.compare(word1.length() , word2.length() ) )
        .orElse(null) ;

        out.println(ans);

        close() ; 
    }

    
    private static void initialize() throws IOException , FileNotFoundException {
        in = new FastReader();
        out = new FastWriter();
    }

    private static void close() throws IOException {
        in.close();
        out.close();
    }
}