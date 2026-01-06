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

    public static void deleteNode(ListNode node) {
        ListNode next = node.next ; 
        node.val = next.val ; 
        node.next = next.next ; 
    } 

    public static void main( String[] args ) throws IOException {
 
        initialize();
 
        ListNode l1 = new ListNode(2) ;
        l1.next = new ListNode(4) ; 
        l1.next.next = new ListNode(3) ; 
        l1.next.next.next = new ListNode(5) ; 
        l1.next.next.next.next = new ListNode(6) ;
 
        printList(l1) ;
        deleteNode(l1.next.next) ;
 
        //printList(head) ; 
        printList(l1) ;
 
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
