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

    private static boolean binarySearch(int nums[] , int target , int l , int r ) {
 
        if(l >r )
            return false ;
 
        if(l == r)
            return nums[l] == target ;
 
        int m = l + (r-l)/2 ;
        if(target == nums[m])
            return true ; 
        else if( target < nums[m]  )
            return binarySearch(nums , target , l , m ) ; 
        else return binarySearch(nums , target , m+1 , r ) ;
 
    }
 
    private static boolean searchMatrix_1(int[][] matrix, int target) {
        int R = matrix.length ; 
        int C = matrix[0].length ; 
        for(int r=0 ; r<R ; r++ ){
            if(matrix[r][0] <= target && target <= matrix[r][C-1] )
                return binarySearch(matrix[r] , target , 0 , C-1 ) ; 
        }
        return false ; 
    }

    private static boolean searchMatrix(int[][] matrix, int target) {
        int R = matrix.length ; 
        if(R == 0)
            return false ; 
        int C = matrix[0].length ;
 
        int l = 0 , r = R*C-1 , m ;
        while(l <=r ){
            m = l + (r-l)/2 ; 
            int row = m/C ; 
            int col = m%C ;
            if( target == matrix[row][col]  )
                return true ; 
            else if(target < matrix[row][col] ) {
                r = m-1 ;
            }else {
                l = m+1 ; 
            }
        }
        return false ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        // int[][] matrix = { 
        //                    {1,3,5,7} , 
        //                    {10,11,16,20} , 
        //                    {23,30,34,60} 
        //                  } ;  
 
        int[][] matrix = { 
                           {1}  
                         } ;  
        int target = 1 ;
        boolean ans = searchMatrix(matrix ,target ) ; 
        // out.println(Arrays.toString(nums)) ; 
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
