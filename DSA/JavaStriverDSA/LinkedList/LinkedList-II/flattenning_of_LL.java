import java.io.*;
import java.util.*;
import java.util.function.* ; 
import java.util.concurrent.* ; 
import java.util.stream.* ;

// class ListNode {
//      int val;
//      ListNode next;
//      ListNode() {}
//      ListNode(int val) { this.val = val; }
//      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// }
 
class Node {
    int data;
    Node next;
    Node bottom;
 
    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
 
class JavaMain {
    private static FastReader in;
    private static FastWriter out ;
    private static final int minVal = Integer.MIN_VALUE + 10 ; 
    private static final int maxVal = Integer.MAX_VALUE - 10 ;
    // private static final int inf = (int) 1e9+1 ;
 
    // public static void printList(ListNode head) {
    //     ListNode curr = head ; 
    //     while(curr != null ){
    //         out.print(curr.val + " ") ; 
    //         curr = curr.next ; 
    //     }
    //     out.println("") ; 
    // }

    public static void printList(Node head) throws IOException {
        Node curr = head ; 
        while(curr != null ){
            out.print(curr.data + " ") ; 
            curr = curr.bottom ; 
        }
        out.println("") ; 
    }
 
 
    public static Node mergeNodes( Node node1 , Node node2 ){
 
        if(node1 == null )
            return node2 ;
 
        if(node2 == null )
            return node1 ;
 
        if( node1.data < node2.data ){ 
            node1.bottom = mergeNodes(node1.bottom , node2) ;
            return node1 ; 
        }
        else {
            node2.bottom = mergeNodes(node1 , node2.bottom ) ;
            return node2 ; 
        }
 
    }
 
    public static Node flatten(Node root) {
 
        Node flattenedList = null ; 
        Node currNode = root ;
        while( currNode != null ) {
            Node nextNode = currNode.next ; 
            currNode.next = null ; 
            flattenedList = mergeNodes( flattenedList , currNode ) ;
            currNode = nextNode ; 
        }
        return flattenedList ; 
    }
 
    public static void main( String[] args ) throws IOException {
 
        initialize(); 
        // --- Column 1: Starting at 5 ---
        Node head = new Node(5);
        head.bottom = new Node(7);
        head.bottom.bottom = new Node(8);
        head.bottom.bottom.bottom = new Node(30);
 
        // --- Column 2: Starting at 10 ---
        Node node10 = new Node(10);
        head.next = node10; // Link 5 -> 10
 
        // --- Column 3: Starting at 19 ---
        Node node19 = new Node(19);
        node10.next = node19; // Link 10 -> 19
        node19.bottom = new Node(22);
        node19.bottom.bottom = new Node(50);
 
        // --- Column 4: Starting at 28 ---
        Node node28 = new Node(28);
        node19.next = node28; // Link 19 -> 28
        Node flattenedList = flatten(head) ; 
        printList(flattenedList) ; 
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