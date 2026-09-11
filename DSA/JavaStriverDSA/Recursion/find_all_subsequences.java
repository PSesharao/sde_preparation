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

    // using for-loop + recursion
    
    private static void findAllSubSequences( int A[] , int start , 
         List<Integer> currList ,
         List<List<Integer>> allSubSeqList ) {

        allSubSeqList.add( new ArrayList<>(currList) );

        for( int i = start ; i < A.length ; i++ ){

            currList.add( A[i] );
            findAllSubSequences(A , i+1 , currList , allSubSeqList ) ; 
            currList.remove( currList.size() -1 );
        }
    }

    private static void findAllSubSets2(int A[] 
        , int ind , List<Integer> currList 
        , List<List<Integer>> allSubSetList ) {

        if( ind == A.length ) {
            allSubSetList.add( new ArrayList<> (currList) ) ; 
            // otherwise during backtracking , it gets cleaned up
            // so each reference of currList will be empty after we move 
            // out of this function.
            return ; 
        }

        
        // exclude
        findAllSubSets2( A , ind+1 , currList , allSubSetList ) ;

        // include 
        currList.add(A[ind]) ; 
        findAllSubSets2( A , ind+1 , currList , allSubSetList ) ;

        // If you omit the below line, every addition to currList persists 
        // permanently across every branch of the recursion tree 
        // because they all reference the same memory address.

        currList.remove( currList.size() - 1 ) ; 


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

        // findAllSubSets2( A , 0 , currList , allSubSetList ) ; 
        findAllSubSequences( A , 0 , currList , allSubSeqList ) ;

        out.println(allSubSetList) ;
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
