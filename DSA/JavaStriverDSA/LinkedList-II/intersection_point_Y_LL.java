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
 
 
    public static int length( ListNode head ) {
 
        int l = 0 ; 
        while(head!=null ){
            head = head.next ; 
            l++ ; 
        }
        return l ;
 
    }
 
    public static ListNode skip( ListNode head , int n ) {
 
        for(int i=1 ; i<=n ; i++)  // We are skipping n nodes to go to n+1th, so we need to use <=
            head = head.next ;
        return head ;
 
    }
 
    public static ListNode getIntersectionPoint(ListNode headA, ListNode headB) {
 
        if( headA == null || headB == null )
            return null ;
 
        if( headA == headB )
            return headA ;
 
        do {
            headA = headA.next ; 
            headB = headB.next ; 
        }while( headA != headB ) ;
 
        // while(headA != null ) {
        //     if (headA == headB) return headA ;  // Intersection point found
        //     headA = headA.next;
        //     headB = headB.next;            
        // }
 
        return headA ; 
    }
 
    public static ListNode getIntersectionNode(ListNode headA, ListNode headB) throws IOException  {
 
        ListNode intersection = null ;
        int l1 = length(headA) ; 
        int l2 = length(headB) ; 
        // System.out.println(l1) ; 
        // System.out.println(l2) ; 
        if( l1 == l2 )
            intersection = getIntersectionPoint( headA , headB ) ;
        else if( l1 > l2 ){
            headA = skip( headA , l1-l2 ) ; 
            // printList(headA) ; 
            // printList(headB) ;
            intersection = getIntersectionPoint( headA , headB ) ;
        }else{
            headB = skip( headB , l2-l1 ) ; 
            // printList(headA) ; 
            // printList(headB) ;
            intersection = getIntersectionPoint( headA , headB ) ;
        }
 
        return intersection ; 
    }
 
    public static ListNode getIntersectionNode1(ListNode headA, ListNode headB) {
        Set<ListNode> set = new HashSet<>() ;  
        ListNode intersection = null ;
        ListNode curr = headA ;
 
        while( curr != null ) {
            set.add( curr ) ; 
            curr = curr.next ; 
        }
 
        curr = headB ; 
        while( curr != null ) {
            if( set.contains(curr) ){
                intersection = curr ; 
                break ; 
            }
            curr = curr.next ; 
        }
 
        return intersection ; 
    }
 
    public static void main( String[] args ) throws IOException {
 
        initialize();
 
        // // 1. Create the common/intersecting part: [8, 4, 5]
        // ListNode intersectPart = new ListNode(8);
        // intersectPart.next = new ListNode(4);
        // intersectPart.next.next = new ListNode(5);
 
        // // 2. Create List A: [4, 1] and point it to the intersection
        // // listA = [4, 1, 8, 4, 5]
        // ListNode headA = new ListNode(4);
        // headA.next = new ListNode(1);
        // headA.next.next = intersectPart;
 
        // // 3. Create List B: [5, 6, 1] and point it to the same intersection
        // // listB = [5, 6, 1, 8, 4, 5]
        // ListNode headB = new ListNode(5);
        // headB.next = new ListNode(6);
        // headB.next.next = new ListNode(1);
        // headB.next.next.next = intersectPart;
 
        // 1. Create the shared tail: [2, 4]
        ListNode intersectPart = new ListNode(2);
        intersectPart.next = new ListNode(4);
 
        // 2. Create List A: [1, 9, 1] then link to intersection
        // skipA = 3 nodes (1, 9, 1)
        ListNode headA = new ListNode(1);
        headA.next = new ListNode(9);
        headA.next.next = new ListNode(1);
        headA.next.next.next = intersectPart;
 
        // 3. Create List B: [3] then link to intersection
        // skipB = 1 node (3)
        ListNode headB = new ListNode(3);
        headB.next = intersectPart;
 
        printList(headA) ;
        printList(headB) ;
 
        ListNode intersection = getIntersectionNode( headA , headB ) ;
 
        printList(intersection) ; 
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