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

    private static void sumOfSubsets( int A[] , int cur_sum , 
        int ind , List<Integer> subSetSumList ) {

        if( ind == A.length ) {
            subSetSumList.add(cur_sum) ; 
            return ;  
        }

        // include
        cur_sum += A[ind] ;
        sumOfSubsets(A , cur_sum , ind+1 , subSetSumList ) ; 

        // exclude
        cur_sum -= A[ind] ;
        sumOfSubsets(A , cur_sum , ind+1 , subSetSumList ) ; 
    }

    private static void findAllSubSets(int A[] 
        , int ind , List<Integer> currList 
        , List<List<Integer>> allSubSetList ) {

        if( ind == A.length ) {
            allSubSetList.add( new ArrayList<> (currList) ) ; 
            // otherwise during backtracking , it gets cleaned up
            // so each reference of currList will be empty after we move 
            // out of this function.
            return ; 
        }

        // include 
        currList.add(A[ind]) ; 
        findAllSubSets( A , ind+1 , currList , allSubSetList ) ;

        // exclude
        currList.remove(currList.size() - 1 ) ; 
        findAllSubSets( A , ind+1 , currList , allSubSetList ) ;

    }


    public static void main( String[] args ) throws IOException {
        initialize();  
        int A[] = {5 , 2 , 1} ; 
        List<Integer> currList = new ArrayList<>() ; 
        List<List<Integer>> allSubSetList = new ArrayList<>() ; 

        findAllSubSets( A , 0 , currList , allSubSetList ) ; 
        out.println(allSubSetList) ;

        List<Integer> subSetSumList = new ArrayList<>() ; 

        sumOfSubsets( A , 0 , 0 , subSetSumList ) ; 
        out.println(subSetSumList) ;
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
