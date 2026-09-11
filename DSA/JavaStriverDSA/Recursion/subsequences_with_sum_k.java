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



    private static void findAllSubsequencesSumToK( int A[] , int ind ,
    int target , List<Integer> currList , List<List<Integer>> allSubSeqList ) {

        // Returning immediately when target == 0 misses valid subsequences 
        // like [1, 0]
        // if the array contains zeros (e.g., A = [1, 0], target = 1) , 
        // so we need to check for the full condition ind == A.length
        // unless we decide to return any subsequence.

        if( ind == A.length ) {
            if( target == 0 )
                allSubSeqList.add( new ArrayList<>(currList) ) ; 
            return ; 
        }

        // take 
        if( ( target - A[ind] ) >= 0 ) {

            currList.add(A[ind]) ; 
            findAllSubsequencesSumToK(A , ind+1 , 
                target - A[ind] , currList , allSubSeqList ) ; 

            currList.remove( currList.size() - 1 ) ; 
        }

        // not take 
        findAllSubsequencesSumToK( A , ind+1 , target , currList , allSubSeqList ) ; 
    }

    public static void main( String[] args ) throws IOException {

        initialize();  

        int A[] = {1, 2, 3, 4, 5} ; 
        int target = 5 ; 
        List<Integer> currList = new ArrayList<>() ; 
        List<List<Integer>> allSubSeqList = new ArrayList<>() ; 
        findAllSubsequencesSumToK( A , 0 , target , currList , allSubSeqList ) ; 
        out.println(allSubSeqList) ;

        
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
