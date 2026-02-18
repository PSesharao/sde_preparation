import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ; 


class Solution {

}

class ListNode {
     int val;
     ListNode next;
     ListNode() {}
     ListNode(int val) { this.val = val; }
     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class JavaMain {

    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;

    // private static final int inf = (int) 1e9+1 ;

    public static void printList(ListNode head) throws IOException {
        ListNode curr = head ; 
        while(curr != null ){
            out.print(curr.val + " ") ; 
            curr = curr.next ; 
        }
        out.println("") ; 
    } 
    
   public static ListNode removeNthFromEnd(ListNode head, int n) {
 
        ListNode fast_ptr = head ; 
        for(int i=1 ; i<n ; i++ )
            fast_ptr = fast_ptr.next ;
 
        ListNode slow_ptr = head ; 
        ListNode prev = null ;
 
        while( fast_ptr.next != null ) {
            prev = slow_ptr ;
            fast_ptr = fast_ptr.next ; 
            slow_ptr = slow_ptr.next ; 
        }
 
        if( slow_ptr == head ) {     // we need to remove head itself here
            head = head.next ; 
        }else {
            prev.next = slow_ptr.next ; 
        }
 
        return head ; 
    }
    
    public static ListNode removeNthFromEnd1(ListNode head, int n) {
 
        int l = 0 ; 
        ListNode curr = head ; 
        while( curr != null ) {
            curr = curr.next ; 
            l++ ; 
        }
        int t = l-n+1  ;
        curr = head ;
 
        if( t == 1 ) {  // removing the first node at head
             head = head.next ; 
        } else {
 
            ListNode prev = null ;
            ListNode next = null ;
            for(int i=1 ; i<t ; i++ ) {
                prev = curr ;
                curr = curr.next ; 
            }
 
            next = curr.next ; 
            prev.next = next ; 
        }
 
        return head ; 
    }
 

    public static void main( String[] args ) throws IOException {
 
        initialize();
 
        ListNode head = new ListNode(10) ;
        head.next = new ListNode(20) ; 
        head.next.next = new ListNode(30) ; 
        head.next.next.next = new ListNode(40) ;
        head.next.next.next.next = new ListNode(50) ;
        head.next.next.next.next.next = new ListNode(60) ;
        printList(head) ; 
        ListNode new_head = removeNthFromEnd(head , 1 ) ;
        printList(new_head) ;
 
        close() ; 
    }

    private static void initialize() throws IOException , FileNotFoundException {
        in = new FastReader();
        out = new FastWriter();
    }

    private static void close() throws IOException {
        in.close();
        out.close();
    }
}
