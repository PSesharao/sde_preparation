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
 
    
    public static int removeDuplicates(int[] nums) {
        int len = nums.length ; 
        if(len == 0 || len == 1)
            return len ; 
        int k = 0 ;
        for(int i=1 ; i<len ;i++){
            if( nums[i] != nums[i-1] ){
                nums[k] = nums[i-1] ; 
                k++ ; 
            }
        }
        nums[k] = nums[len-1] ; // always place last element
        k++ ; 
        return k ;
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int A[] = {0,0,1,1,1,2,2,3,3,4} ;
        int k = removeDuplicates(A) ;
        out.println(k) ;  
        out.println(Arrays.toString(A)) ;
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
 