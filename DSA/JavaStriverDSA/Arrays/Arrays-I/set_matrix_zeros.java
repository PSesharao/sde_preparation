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


    public static void setZeroes(int[][] matrix) {
        // Get dimensions of matrix
        int m = matrix.length;
        int n = matrix[0].length;

        // Flag to track if first row should be zeroed
        boolean firstRowZero = false;
        // Flag to track if first column should be zeroed
        boolean firstColZero = false;

        // Check if first row has any zero
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Check if first column has any zero
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Use first row/column as markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set cells to zero based on markers
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero the first column if needed
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }


    private static void setZeros1(int mat[][]) {

        int R = mat.length ; 
        int C = mat[0].length ; 
        int col_buff[] = new int[C] ; 
        int row_buff[] = new int[R] ;
        Arrays.fill(col_buff, 0);
        Arrays.fill(row_buff, 0);

        for(int r=0 ; r<R ; r++)
            for(int c=0 ; c<C ; c++) {
                if(mat[r][c] == 0 ) {
                    row_buff[r] = 1 ;
                    col_buff[c] = 1 ; 
                }
            }

        for(int r=0 ; r<R ; r++ ){
            if(row_buff[r] == 1){
                for(int c=0 ; c<C ; c++)
                    mat[r][c] = 0 ; 
            }
        }

        for(int c=0 ; c<C ; c++ ){
            if(col_buff[c] == 1)
                for(int r=0 ; r<R ; r++)
                    mat[r][c] = 0 ; 
        }

    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        int[][] mat = {
            {1,2,3,4},
            {5,0,7,8},
            {0,10,11,12},
            {13,14,15,0}
        };

        setZeroes( mat ) ; 
        for(int i=0 ; i<mat.length ; i++)
            out.println(Arrays.toString(mat[i])) ;
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
