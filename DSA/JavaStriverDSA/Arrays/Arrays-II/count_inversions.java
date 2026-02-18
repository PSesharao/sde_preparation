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

    private static int merge(int nums[] , int l , int m , int r ) {
        int L = m-l +1 ; // [l , m]
        int R = r-m ; // [m+1 , r] since m is not inclusive we are not adding +1
        int leftArr[] = new int[L] ; 
        int rightArr[] = new int[R] ;
 
        // copying to left array
        for(int i=0 ; i<L ; i++ )
            leftArr[i] = nums[l+i] ;
 
        // copying to right array
        for(int i=0 ; i<R ; i++ )
            rightArr[i] = nums[m+1+i] ;
 
        // merging process
        int i , j , k , inverseCount ; 
        i=0 ; j=0 ; k=l ; inverseCount = 0 ;
 
        while( i<L && j<R ){
            if( leftArr[i] > rightArr[j] ){
                inverseCount += L-i ; 
                nums[k] = rightArr[j] ; 
                j++ ; 
                k++ ; 
            }else{
                nums[k] = leftArr[i] ; 
                i++ ; 
                k++ ; 
            }
        }
        // copy remaining from leftArr
        if(i<L){
            while(i<L){
                nums[k] = leftArr[i] ; 
                i++ ; 
                k++ ; 
            }
        }
 
        // copy remaining from rightArr
        if(j<R){
            while(j<R){
                nums[k] = rightArr[j] ; 
                j++ ; 
                k++ ; 
            }
        }
        return inverseCount ; 
    }

    private static int mergeSort(int nums[] , int l , int r ) {
 
        if(l >= r) {
            return 0 ; 
        }
 
        int m = l+ ((r-l)/2) ; // To avoid integer overflow
        int leftAns = mergeSort(nums , l , m ) ;
        int rightAns = mergeSort(nums , m+1 , r) ;
        int mergeAns = merge(nums , l , m , r ) ;
        return leftAns + rightAns + mergeAns ;
 
    }

    public static int inversionCount(int nums[]) {
        return mergeSort(nums , 0 , nums.length-1 ) ;
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        int[] nums =  {2,4,1,3,5} ; 
        int ans = inversionCount(nums) ; 
        out.println(Arrays.toString(nums)) ; 
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
