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
    

    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
 
        ListNode merge_head = new ListNode(-1) ;  
        ListNode merge_ptr = merge_head ;
 
        while( list1 != null && list2 != null ) {
 
            if( list1.val < list2.val ){
                merge_ptr.next = list1 ; 
                list1 = list1.next ; 
            }else {
                merge_ptr.next = list2 ; 
                list2 = list2.next ; 
            }
            merge_ptr = merge_ptr.next ;
 
        }
 
        // To put the remaining elements from list1
        while( list1 != null ) {
            merge_ptr.next = list1 ; 
            list1 = list1.next ; 
            merge_ptr = merge_ptr.next ; 
        }
 
        // To put the remaining elements from list2
        while( list2 != null ) {
            merge_ptr.next = list2 ; 
            list2 = list2.next ; 
            merge_ptr = merge_ptr.next ; 
        }
 
        return merge_head.next ;
 
    }
 

    public static void main( String[] args ) throws IOException {
 
        initialize();
 
        ListNode head1 = new ListNode(1) ;
        head1.next = new ListNode(2) ; 
        head1.next.next = new ListNode(4) ;
 
        ListNode head2 = new ListNode(1) ;
        head2.next = new ListNode(3) ; 
        head2.next.next = new ListNode(4) ;
 
        printList(head1) ; 
        printList(head2) ;
        ListNode merge_head = mergeTwoLists( head1 , head2 ) ; 
        printList(merge_head) ;
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
