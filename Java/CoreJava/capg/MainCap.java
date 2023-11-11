package capg;

import java.util.Arrays;

public class MainCap {


    public static void main(String[] args) {


        int inputArray[] = {0, 1, 0, 1, 0, 2, 0, 1, 1, 1, 0} ;

        // O(n Log n)

        // frequency method 0 , 1 , 2   3* O(n) , O(N)

        // National Flad / Dutch algo -- TC :O(N) , SC :O(1)

        int next_zero = 0  ;
        int next_two = inputArray.length -1 ;

        int curr_ptr = 0 ;

        for( ; curr_ptr<= next_two ; curr_ptr++  ) {

            if(inputArray[curr_ptr] == 0) {
                // swap curr_ptr , next_zero

                int temp = inputArray[next_zero] ;
                inputArray[next_zero] = inputArray[curr_ptr] ;
                inputArray[curr_ptr] = temp ;
                next_zero++ ;

            }else if(inputArray[curr_ptr] == 2) {
                // swap curr_ptr , next_two

                int temp = inputArray[next_two] ;
                inputArray[next_two] = inputArray[curr_ptr] ;
                inputArray[curr_ptr] = temp ;
                next_two -- ;
                curr_ptr-- ;
            }

        }

        for(int i=0 ; i<inputArray.length  ; i++)
            System.out.println(inputArray[i]) ;

    }
}
