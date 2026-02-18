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
    public static void printList(ListNode head) throws IOException  {
        ListNode curr = head ; 
        while(curr != null ){
            out.print(curr.val + " ") ; 
            curr = curr.next ; 
        }
        out.println("") ; 
    }
 
    public static ListNode reverse( ListNode begin , ListNode end ) {
        ListNode prev , curr , next , first ; 
        prev = begin ; 
        first = curr = begin.next ;
 
        while( curr!=end ) {
            next = curr.next ; 
            curr.next = prev ; 
            prev = curr ;
            curr = next ; 
        }
 
        begin.next = prev ; 
        first.next = curr ; 
        return first ; 
    }
    
    public static ListNode reverseKGroup(ListNode head, int k) {
 
        ListNode tempHead = new ListNode(-1) ; 
        tempHead.next = head ; 
        ListNode begin = tempHead ;
        int i=0 ; 
        while(head != null ){
            i++ ;
            if( i%k == 0 ){
                begin = reverse( begin , head.next ); 
                head = begin.next ; 
            }else 
                head = head.next ; 
        }
        return tempHead.next ; 
    }
 
 
    public static void main( String[] args ) throws IOException {
 
        initialize(); 
        ListNode head = new ListNode(1);
        ListNode current = head;
 
        for (int i = 2; i <= 11; i++) {
            current.next = new ListNode(i);
            current = current.next;
        }
        // 1->2->3->4->5->6->7->8->9->10->11
        printList(head) ; 
        //out.println(ans) ; 
        ListNode ans = reverseKGroup(head , 3) ;
        printList(ans) ; 
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
