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

 

    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
 
        ListNode result = new ListNode(-1) ; 
        ListNode curr = result ;
        int carry = 0 ;
        while( l1!= null || l2!= null ) {
 
            int sum = ( l1!= null ? l1.val : 0 )  + ( l2!= null ? l2.val : 0 ) + carry ;
 
            int digit = sum % 10 ; 
            int data = digit ;
            carry = sum / 10 ; 
            ListNode node = new ListNode(data) ; 
            curr.next = node ; 
            curr = node ; 
            if(l1!= null)
                l1 = l1.next ;
 
            if(l2!= null)
                l2 = l2.next ;
 
        }
 
        if(carry > 0 ) {
            ListNode node = new ListNode(carry) ;
            curr.next = node ; 
        }
 
        return result.next ;
 
    }

    public static void main( String[] args ) throws IOException {
 
        initialize();
 
        ListNode l1 = new ListNode(2) ;
        l1.next = new ListNode(4) ; 
        l1.next.next = new ListNode(3) ;
 
        ListNode l2 = new ListNode(5) ;
        l2.next = new ListNode(6) ; 
        l2.next.next = new ListNode(4) ;
 
        //printList(head) ; 
        ListNode sum = addTwoNumbers( l1 , l2 ) ; 
        printList(sum) ;
 
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
