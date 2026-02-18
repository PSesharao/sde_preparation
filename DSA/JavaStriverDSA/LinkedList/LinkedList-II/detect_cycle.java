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
 

     public static boolean hasCycle(ListNode head) {
 
        ListNode slow_ptr = head ;
        ListNode fast_ptr = head ;
 
        while( fast_ptr !=null && fast_ptr.next != null ) {
 
            slow_ptr = slow_ptr.next ;
            fast_ptr = fast_ptr.next.next ;
 
            if( fast_ptr == slow_ptr )
                return true ;
        }
 
        return false ;
    }


    public static void main( String[] args ) throws IOException {
 
        initialize();
        // 1. Create the nodes
        ListNode head = new ListNode(3);
        ListNode secondNode = new ListNode(2);
        ListNode thirdNode = new ListNode(0);
        ListNode tail = new ListNode(-4);
 
        // 2. Link them linearly: 3 -> 2 -> 0 -> -4
        head.next = secondNode;
        secondNode.next = thirdNode;
        thirdNode.next = tail;
 
        // 3. Create the cycle: Connect tail (-4) to the 2nd node (2)
        // pos = 1 (if 0-indexed) refers to the node with value 2
        tail.next = secondNode;
        //printList(head) ;
        out.println( hasCycle(head) ) ;
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