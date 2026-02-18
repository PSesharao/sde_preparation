import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class Solution {

}


class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;


    private static List<List<Integer>> generate(int R) {
        List<List<Integer>> ansList = new ArrayList<>();
        for( int i=0 ; i<R ; i++ ){
            List<Integer> list = new ArrayList<>() ; 

            for( int j=0 ; j<=i ; j++ ) {

                if( j==0 || j==i )
                    list.add(1) ; 

                else {

                    int val = ansList.get(i-1).get(j) +  ansList.get(i-1).get(j-1) ; 
                    list.add(val) ;

                }
            }
            ansList.add(list) ; 
        }
        return ansList ; 
    }

    private static List<List<Integer>> generate(int R) {

        List<List<Integer>> pascal = new ArrayList<>(R) ; 
        for(int r=0 ; r<R ; r++){
            List<Integer> curr_row = new ArrayList<>(Collections.nCopies(r+1 , 0 ));
            curr_row.set(0, 1) ;
            curr_row.set(r ,1) ;  
            for(int c=1 ; c<r ; c++ ){
                int ans = pascal.get(r-1).get(c) + pascal.get(r-1).get(c-1) ; 
                curr_row.set(c , ans ) ; 
            }
            pascal.add(curr_row) ; 
        }
        return pascal ; 
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        int N = 5 ; 
        List<List<Integer>> pascal = generate(N) ;
        for(int i=0 ; i<N ; i++ ){
            for(int j=0 ; j<=i ; j++)
                out.print(pascal.get(i).get(j) + " ") ; 
            out.println("") ; 
        }
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
