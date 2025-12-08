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

    private static void reverse(int arr[] , int i , int j ){
        while(i< j ){
            int temp = arr[i] ; 
            arr[i] = arr[j] ; 
            arr[j] = temp ; 
            i++ ; 
            j-- ; 
        }
    }

    private static void get_next_permutation( int arr[] ) {
        int N = arr.length ; 
        int bp = -1 ; 

        for(int i=N-2 ; i>=0 ; i--) {
            if(arr[i] < arr[i+1]){
                bp = i ; 
                break ; 
            }
        }

        if(bp == -1 ){
            reverse(arr , 0 , N-1 ) ; 
        }else {

            for(int i=N-1 ; i>bp ; i--){

                if( arr[i] > arr[bp] ){
                    int temp = arr[i] ; 
                    arr[i] = arr[bp] ; 
                    arr[bp] = temp ; 
                    break ; 
                }
            }

            reverse(arr , bp+1 , N-1 ) ; 
        }
    }

    public static void main( String[] args ) throws IOException {
        initialize();  
        int A[] = {1,3,5,4,2} ; 
        get_next_permutation(A) ; 
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
