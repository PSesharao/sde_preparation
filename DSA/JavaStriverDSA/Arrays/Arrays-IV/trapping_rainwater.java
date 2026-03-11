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
 
 
 
    public static int trap(int[] height) {
 
        int totalTrapArea = 0 ;
        int len = height.length ; 
        int maxLeft = height[0] ;
        int maxRight = height[len-1] ;
        int left = 1 ; 
        int right = len-2 ;
 
        while( left <= right ) {
            if( maxLeft <= maxRight ) { // if we need to do the comparision from extreme indices , we can have the check like height[left] <= height[right]
    // There is a chance that height[left] can hold the water if it is less than maxLeft also
    // As at any point , we would only need to know the value of Min( maxLeft , maxRight )
                if( height[left] < maxLeft ) 
                    totalTrapArea += maxLeft - height[left] ; 
                else
                    maxLeft = height[left] ; // We can not hold here , but this can be fresh maxLeft
                left ++ ; 
            }else {
                if( height[right] < maxRight )
                    totalTrapArea += maxRight - height[right] ;
                else
                    maxRight = height[right] ; 
                right -- ; 
            }
        }
 
        return totalTrapArea ; 
    }
 
    public static int trap_(int[] height) {
 
        int totalTrapArea = 0 ;
        int len = height.length ; 
        int leftMax[] = new int[len];
        int rightMax[] = new int[len];
 
        int maxLeft = height[0] ;
        for(int i=1 ; i<len-1 ; i++) {
            leftMax[i] = maxLeft ; 
            maxLeft = Math.max(maxLeft , height[i] ) ;  
        }
 
        int maxRight = height[len-1] ;
        for(int i=len-2 ; i>=1 ; i--) {
            rightMax[i] = maxRight ; 
            maxRight = Math.max( maxRight , height[i] ) ; 
        }
 
        // System.out.println(Arrays.toString(leftMax)) ; 
        // System.out.println(Arrays.toString(rightMax)) ; 
        for(int i=1 ; i<len-1 ; i++){
            int minVal = Math.min(leftMax[i] , rightMax[i]) ; 
            totalTrapArea += ( minVal > height[i] ) ? ( minVal - height[i] ) : 0  ; 
        }
 
        return totalTrapArea ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        int height[] = {4,2,0,3,2,5} ; 
        // {3,1,5} ;
        // {0,1,0,2,1,0,1,3,2,1,2,1} ; // {4,2,0,3,2,5} ; 
        int ans = trap(height) ;
        out.println(ans) ;  
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

