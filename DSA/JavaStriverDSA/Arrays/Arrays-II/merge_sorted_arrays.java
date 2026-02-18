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

    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        if(m == 0) {
            for(int i=0 ; i<n ; i++)
                nums1[i] = nums2[i] ; 
            return ; 
        }else if( n == 0 ){
            return ; 
        }
 
        int k = m+n-1 ; // to track the filling 0 places from back for nums1
        int i=m-1 ; // to track nums1
        int j=n-1 ; // to track nums2 
        while( i>=0 && j>=0 ){
            if( nums1[i] > nums2[j] ){
                nums1[k] = nums1[i] ; 
                i-- ; 
                k-- ;
            }else{
                nums1[k] = nums2[j] ; 
                j-- ; 
                k-- ;
            }
        }
 
        // If there are any values left in nums2 then place them at front of nums1
        if(j >=0 ){
            while( j>=0 ){
                nums1[j] = nums2[j] ; 
                j-- ;
            }
        }
 
        // If there are any values left in nums1 (i>=0) let them be 
        // as they would have been in right place already after the check  
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int[] nums1 = {1,2,3,0,0,0} ;
        int[] nums2 = {2,5,6} ;
        merge(nums1 , 3 , nums2 , 3 ) ; 
        out.println( Arrays.toString(nums1 ) ) ; 
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
