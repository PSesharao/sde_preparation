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
    


    public static int longestConsecutive(int[] nums) {
        int n = nums.length ; 
        if(n == 0 )
            return 0 ; 
        Set<Integer> set = new HashSet<>() ; 
        for(int num : nums )
            set.add(num) ;
 
        int ans = 0 ; 
        int count ; 
        for(int num : set ){ // giving TLE if we traverse through the array nums ,
            // instead it is better if we traverse the set directly.
 
            if( set.contains(num-1) ) // num is not the smallest number in the sequence
                continue ;
 
            else {
                int y = num ;
                count =1 ; 
                while( set.contains(y+1) ) {
                    count ++ ; 
                    y++ ; 
                }
                ans = Math.max(ans , count) ; 
            }
 
        }
        return ans ;  
    }
 
    public static int longestConsecutive1(int[] nums) {
        Arrays.sort(nums) ; 
        int n = nums.length ; 
        if(n == 0 )
            return 0 ; 
        int ans = 0 ; 
        int count = 1 ;
 
        for(int i=1 ; i<n ; i++) {
            if(nums[i] == nums[i-1]+1) { 
                count ++ ;  // consecutive 
            }else if(nums[i] == nums[i-1] ){
                continue ; // do nothing as we may expect increasing sequence if we skip
                //these duplicates like [1,2,3,4,4,4,5] here if we skip duplicate 4 , we can 
                //get the number 5 which is in sequence.
            }else{
                ans = Math.max(ans , count) ;
                count = 1 ; // reset count
            }
        }
        ans = Math.max(ans , count) ; // We need to do this as for the last increasing element 
        // We might miss this.
        return ans ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int[] nums = {1,0,1,2} ;
        int ans = longestConsecutive(nums) ; 
        //out.println( Arrays.toString(list) ) ; 
        out.println( ans ) ; 
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
