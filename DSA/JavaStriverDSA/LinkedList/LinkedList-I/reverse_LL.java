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
    


    public static ListNode reverseList(ListNode head) {

        // 1 2 3 4 5
        // head -> 1
        if( head == null || head.next == null )
            return head ;
        // last -> 2
        ListNode last = head.next ; 
        ListNode rev_head = reverseList(head.next) ; // 5 4 3 2
        last.next = head ;  // 2->1
        head.next = null ;  // 1->null
        return rev_head ; 

    }


    public static ListNode reverseList1(ListNode head) {
        ListNode prev , curr , next ; 
        prev = null ; 
        curr = head ; 
        while( curr!=null ) {
            next = curr.next ; 
            curr.next = prev ; 
            prev = curr ;
            curr = next ; 
        }
        ListNode rev_head = prev ; // prev will have the reverse head now
        return rev_head ; 
    }
 
    public static void main( String[] args ) throws IOException {
        initialize(); 
        ListNode head = new ListNode(10) ;
        head.next = new ListNode(20) ; 
        head.next.next = new ListNode(30) ; 
        head.next.next.next = new ListNode(40) ;
        head.next.next.next.next = new ListNode(50) ;
        printList(head) ; 
        ListNode rev_head = reverseList(head) ; 
        printList(rev_head) ;
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
