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

    // private static final int inf = (int) 1e9+1 ;
    
    public static List<List<Integer>> fourSum(int[] nums, int target) {
 
        List< List<Integer> > list = new ArrayList<>() ; 
        int n = nums.length ; 
        Arrays.sort(nums) ;
        for( int first=0 ; first< n-3 ; first++ ) {
            for( int second = first+1 ; second<n-2 ; second++ ) {
                long target1 =  target - ( 0l + nums[first] + nums[second] ) ; 
                int third = second+1 ; 
                int fourth = n-1 ; 
                while( third < fourth ) {
 
                    if( 0l + nums[third] + nums[fourth] < target1 ) // In this case we need to make sum bigger 
                        third ++ ;
 
                    else if( 0l + nums[third] + nums[fourth] > target1 ) // In this case we need to make sum lesser
                        fourth -- ;
 
                    else{
 
                        List<Integer> curr = new ArrayList<>() ; 
                        curr.add(nums[first]) ; 
                        curr.add(nums[second]) ; 
                        curr.add(nums[third]) ; 
                        curr.add(nums[fourth]) ; 
                        list.add(curr) ; 
                        // skipping duplicates for third element
                        while( (third < fourth) && nums[third] == curr.get(2) )
                            third ++ ;
 
                        // skipping duplicates for fourth element
                        while( (third < fourth) && nums[fourth] == curr.get(3) )
                            fourth -- ;
 
                        // We have to skip 3rd and 4th in this else condition here only 
                        // because once we find the target sum required , we would need to 
                        // move away from both third , fourth postions here itself
                    }
                }
 
                // skipping duplicates for second element
                while( (second+1 <n-2) && nums[second] == nums[second+1] )
                    second++ ; 
            }
 
            // skipping duplicates for first element
            while( (first+1 <n-3) && nums[first] == nums[first+1] )
                first++ ; 
        }
 
        return list ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int[] nums = {1,0,-1,0,-2,2} ;
        int target = 0 ; 
        List<List<Integer>> list = fourSum(nums , target ) ;  
        //out.println( Arrays.toString(list) ) ; 
        out.println( list ) ; 
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
