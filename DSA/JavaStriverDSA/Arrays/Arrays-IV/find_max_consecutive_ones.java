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
 
    
    public static int findMaxConsecutiveOnes_(int[] nums) {
        int ans = 0 ;
        int i=0 , len = nums.length ;
        while( i<len ){
            if(nums[i] == 1) {
                int j=i ;
                while( (i+1<len) && nums[i+1]==1 )
                    i++ ;
                ans = Math.max(ans , i-j+1 ) ;
            }
            i++ ;
        }
        return ans ;
    }

    // 1,1,0,1,1,1
    public static int findMaxConsecutiveOnes(int[] nums) {
        int count=0 , len=nums.length , ans=0 ;
        for(int i=0 ; i<len ; i++){
            if(nums[i] == 1)
                count++ ; 
            else{
                ans = Math.max(count , ans) ; 
                count = 0 ; // reset count
            }
            ans = Math.max(count , ans) ; // to check for the last element
        }
        return ans ;
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int A[] = {1,0,0,1,1,0,1,1,1,1} ;
        int k = findMaxConsecutiveOnes(A) ;
        out.println(k) ;  
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
 