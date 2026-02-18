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

    public static int[] findRepeatingAndMissing( int nums[] , int N ) {
 
        int xorRM = 0 ; 
        for(int i=0 ; i<N ; i++){
            xorRM = xorRM ^ nums[i] ; 
            xorRM = xorRM ^ (i+1) ; // doing xor with [ 1 , N ]
        }
 
        int rightMostSetBit = (xorRM & (- xorRM)) ; 
        int bitSet , bitNotSet ; 
        bitSet = bitNotSet = 0 ;
 
        for(int i=0 ; i<N ; i++){
 
            if((rightMostSetBit & nums[i])!=0)
                bitSet = bitSet ^ nums[i] ; 
            else
                bitNotSet = bitNotSet ^ nums[i] ;
 
            if((rightMostSetBit & (i+1))!=0)  // doing xor with [ 1 , N ]
                bitSet = bitSet ^ (i+1) ; 
            else
                bitNotSet = bitNotSet ^ (i+1) ;
 
        }
 
        // Now , we'd have bitSet , bitNotSet as answers
        // we just need to decide which is missing and which is repeating
 
        int bitSetCount = 0 ; 
        for(int i=0 ; i<N ; i++ )
            if(nums[i] == bitSet)
                bitSetCount ++ ;
 
        int R , M ;
 
        if( bitSetCount > 0 ){
            R = bitSet ; 
            M = bitNotSet ; 
        }else{
            R = bitNotSet ; 
            M = bitSet ; 
        }
 
        int ans[] = new int[2] ; 
        ans[0] = R ;
        ans[1] = M ; 
        return ans ;
 
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        int[] nums =  {1,2,3,4,4} ; 
        int ans[] = findRepeatingAndMissing(nums , 5 ) ; 
        out.println( Arrays.toString(ans) ) ; 
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
