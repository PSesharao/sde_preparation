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

    private static void reverse(int[] row , int i , int j ) {
        while(i < j ){
            int temp = row[i] ; 
            row[i] = row[j] ;
            row[j] = temp ;  
            i++ ; 
            j-- ; 
        }
    }
 
    public static void rotate(int[][] matrix) {
        int R = matrix.length ;
        int C = matrix[0].length ; 
        // Transpose (swap the upper parts with lower part)
        for(int i=0 ; i<R ; i++)
            for(int j=i+1 ; j<C ; j++){
                int temp = matrix[i][j] ; 
                matrix[i][j] = matrix[j][i] ; 
                matrix[j][i] = temp ; 
            }
 
        // Reverse each row
        for(int i=0 ; i<R ; i++)
            reverse(matrix[i] , 0 , C-1 ) ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize();  
        int mat[][] = {{1,2,3},{4,5,6},{7,8,9}} ; 
        rotate(mat) ; 
        for(int i=0 ; i<mat.length ; i++ )
            out.println( Arrays.toString(mat[i]) ) ; 
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
