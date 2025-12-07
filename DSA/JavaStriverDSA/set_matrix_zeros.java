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

    private static void setMatrixZeros(int mat[][]) {

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
            {0,1,2,0},
            {3,4,5,2},
            {1,3,1,5}
        };

        setMatrixZeros( mat ) ; 
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
