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

    // private static final int inf = (int) 1e9+1 ;
    
   public static int lengthOfLongestSubstring(String str) {
        int n = str.length() ; 
        if(n == 0)
            return 0 ;
        int ans = 0 ;
        Map<Character , Integer> map = new HashMap<>() ;
        int l=0 , r=0 ;  
        while( r<n ) {
 
            System.out.println() ;
            char ch = str.charAt(r) ; 
            if(map.containsKey(ch)) {  
 
                int j = map.get(ch) ;
                l = Math.max(l , j+1 ) ; // because we should not set l value to previous indices like for 'abba'
 
                // just bypass the duplicate directly
 
 
                // we must update index to latest 
                // for future elements in string 
                // which anyways is taken care below.
 
            } 
            int len= r-l+1 ; 
            ans = Math.max(ans , len) ;
            map.put(ch , r) ; 
            r++ ;  
        }
        return ans ; 
    }
 
 
    public static int lengthOfLongestSubstring2(String str) {
        int n = str.length() ; 
        if(n == 0)
            return 0 ;
        int ans = 0 ;
        Set<Character> set = new HashSet<>() ;
        int l=0 , r=0 ;  
        while( r<n ) {
            char ch = str.charAt(r) ; 
            if(set.contains(ch)) {  
                while( l<r && set.contains(ch) ) {
                    char ch1 = str.charAt(l) ;
                    set.remove(ch1) ; 
                    l++ ;  
                }  
            } // we can get rid of else condtion to support the map optimized solution
            // here we are inserting char at 'r' only after removing the duplicate in if condition. 
            int len= r-l+1 ; 
            ans = Math.max(ans , len) ;
            set.add(ch) ; 
            r++ ;  
        }
        return ans ; 
    }
 
 
    public static int lengthOfLongestSubstring1(String str) {
        int n = str.length() ; 
        if(n == 0)
            return 0 ;
        int ans = 0 ;
        Set<Character> set = new HashSet<>() ;
        int l=0 , r=0 ;  
        while( r<n ) {
            char ch = str.charAt(r) ; 
            if(!set.contains(ch)) {   // means there is no duplicate between [l,r]
                int len= r-l+1 ; 
                ans = Math.max(ans , len) ;
                set.add(ch) ; 
                r++ ;  
            }else{  // duplicate found between the range [l,r] , at r , 
                   // so we need to remove till first duplicate which
                // l can track.
                while( l<r && set.contains(ch) ) {
                    char ch1 = str.charAt(l) ;
                    set.remove(ch1) ; 
                    l++ ;  
                }   
            }
        }
        return ans ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        String str = "abba" ;
        int ans = lengthOfLongestSubstring(str) ; 
        //out.println( Arrays.toString(list) ) ; 
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
