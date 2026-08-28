import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class Solution {
    public String greetUser(String name ) {
        return "Hello " + name ; 
    }
}

class JavaMain {
    
    private static FastReader in;
    private static FastWriter out ;

    public static void main(String[] args) throws IOException  {
        initialize(); 
        Solution sol = new Solution() ; 
        String name = in.nextLine() ; 
        out.println(name) ; 
        out.println(sol.greetUser(name)) ;  
        out.println("Hello Every one , how are you all doing ? ") ; 
        close() ; 
    }

    
    private static void initialize() throws IOException , FileNotFoundException{
        in = new FastReader();
        out = new FastWriter();
    }

    private static void close() throws IOException  {
        in.close();
        out.close();
    }
}