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




    public static List<List<Integer>> threeSum(int[] nums, int target) {
 
        List< List<Integer> > list = new ArrayList<>() ; 
        int n = nums.length ; 
        Arrays.sort(nums) ;


        for(int first = 0 ; first < n-2 ; first++ ){

            int second = first+1 ;
            int third = n-1 ; 
            long target1 = 0l + target - nums[first]  ; 

            while( second < third ) {
                long two_sum = 0l + nums[second] + nums[third] ;

                if(two_sum < target1 )
                    second++ ; 
                else if(two_sum > target1 )
                    third-- ; 
                else{

                    List<Integer> curr = new ArrayList<>() ; 
                    curr.add(nums[first]) ;
                    curr.add(nums[second]) ; 
                    curr.add(nums[third]) ; 
                    list.add(curr);
                    
                    while((second < third ) && nums[second] == curr.get(1) )
                        second ++ ; // skip 2nd element dups

                    while( (second < third ) && nums[third] == curr.get(2) )
                        third -- ; // skip 3rd element dups
                }
            }

            while( ( first+1 < n-2 ) && ( nums[first] == nums[first+1] ) )
                first++ ; // skip 1st element dups

        }
 
        return list ; 
    }

    public static void main( String[] args ) throws IOException {

        initialize() ;   
        int A[] = {-1,0,1,2,-1,-4} ; 
        List<List<Integer>> list = threeSum(A , 0 ) ;
        out.println(list) ;
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
