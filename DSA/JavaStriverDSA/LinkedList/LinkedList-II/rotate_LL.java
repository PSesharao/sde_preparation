import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ;
 
 
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
 
 
    public static void printList(ListNode head) throws IOException {
        ListNode curr = head ; 
        while(curr != null ){
            out.print(curr.val + " ") ; 
            curr = curr.next ; 
        }
        out.println("") ; 
    }
 
 
 
    public static ListNode rotateRight( ListNode head, int k ) {
 
        if(head == null || k == 0 )
            return head ;
        // Now , list should have at least of 1 length
        ListNode last = head ;
        int len = 1 ;
        while( last.next != null ){
            len ++ ; 
            last = last.next ; 
        }
        // Now , need to point last to the head to form circular list
        last.next = head ;
        int l = len - (k%len) ;
        ListNode tail = head ;
        for(int i=1 ; i<l ; i++)
            tail = tail.next ;
 
        ListNode newHead = tail.next ;
        tail.next = null ; // break circular links
        return newHead ; 
    }
    public static void main( String[] args ) throws IOException {
 
        initialize();  
        List<Integer> list = List.of(1,2,3,4,5); 
        ListNode head = new ListNode(list.get(0)) ; 
        ListNode curr = head ; 
        for( int i=1 ; i<list.size() ; i++ ){
            curr.next = new ListNode(list.get(i)) ;
            curr = curr.next ; 
        }
        printList(head) ; 
        ListNode newHead = rotateRight(head , 2); 
        printList(newHead) ; 
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