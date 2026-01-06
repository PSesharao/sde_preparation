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
    


    public static ListNode middleNode(ListNode head) {
 
        ListNode slow = head ; 
        ListNode fast = head ;
 
        while( fast!=null && fast.next!=null ) {
            slow = slow.next ; 
            fast = fast.next.next ; 
        }
 
        return slow ;
 
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
        ListNode mid_node = middleNode(head) ; 
        printList(mid_node) ;
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
