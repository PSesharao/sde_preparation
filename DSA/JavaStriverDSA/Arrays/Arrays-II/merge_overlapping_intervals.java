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

    public static int[][] merge(int[][] intervals) {
 
        // sort intervals in ascending order based on first value
        Arrays.sort( intervals , 
            ( interval1 , interval2 ) -> Integer.compare( interval1[0] , interval2[0] ) ) ;
 
        // interval1/2 are of type int[]
        // We are using lambda expression to override the Comparator's compare function which takes int[] arguments.
        // Integer.compare takes care of the Integer overflow.
        // Comparator's compare function -ve value means sorting required any other values 0/ -ve not required.
 
 
        // using array list for dynamically storing the merged intervals
        List<int[]> list = new ArrayList<>() ;
 
        int merge_start = intervals[0][0] ; 
        int merge_end = intervals[0][1] ;
 
        for(int i=1 ; i<intervals.length ; i++ ) {
            int curr_start = intervals[i][0] ; 
            int curr_end = intervals[i][1] ;
 
            if( curr_start <= merge_end ) {
                // overlap interval case 
                // we need to update the boundary as the new interval
                merge_end = Math.max( curr_end , merge_end ) ; 
            }else{
                // non overlapping intervals case
                // we need to push the updated interval so far as the new interval 
                int[] updated_interval = new int[2] ; 
                updated_interval[0] = merge_start ; 
                updated_interval[1] = merge_end ; 
                list.add(updated_interval) ; 
                // reset the values of merge intervals to current boundaries be used from here for next cases
                merge_start = curr_start ; 
                merge_end = curr_end ; 
            }
        }
        // After the for loop is over , we'd still miss to capture the last possible interval 
        // so we need to explictly push this to the answer.
        int[] updated_interval = new int[2] ; 
        updated_interval[0] = merge_start ; 
        updated_interval[1] = merge_end ; 
        list.add(updated_interval) ; 
        int[][] merged_intervals = new int[list.size()][] ; 
        // convert array list back to array
        merged_intervals = list.toArray(merged_intervals) ; 
        return merged_intervals ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int intervals[][] = { {1,3},{2,6},{8,10},{15,18} } ; 
        int[][] merged_intervals = merge(intervals) ; 
        for(int i=0 ; i<merged_intervals.length ; i++ )
            out.println( Arrays.toString(merged_intervals[i]) ) ; 
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
