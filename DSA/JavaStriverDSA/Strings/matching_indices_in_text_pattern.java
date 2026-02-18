import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;


    private static List<Integer> matchIndices( String text , String pattern ){
        int tLen = text.length() ; 
        int pLen = pattern.length() ; 
        List<Integer> indexList = new ArrayList<>() ;
        int i=0 , j ;
        while( i<= tLen - pLen) {
            j=0 ;
 
            while( (j< pLen) && ( text.charAt(i+j) == pattern.charAt(j) ) ) 
                j++ ;
 
            if( j == pLen )
                indexList.add(i) ;
 
            i++ ;
        }
        return indexList ; 
    }
 


    public static void main( String[] args ) throws IOException {
        initialize();  
        String text = "abracadabra" ;
        String pattern = "abra" ;
        List<Integer> ansList = matchIndices(text , pattern) ;
        out.println(ansList);
        close() ; 
    }

    
    private static void initialize() throws IOException , FileNotFoundException {
        in = new FastReader();
        out = new FastWriter();
    }

    private static void close() throws IOException  {
        in.close();
        out.close();
    }
}
