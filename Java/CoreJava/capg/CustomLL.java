package capg;

class LL {

    public int data ;
    public LL next ;

    public LL( int data ) {
        this.data = data ;
        this.next = null ;
    }

    public void printLL(LL head ) {

        LL temp = head ;

        while (temp!=null) {

            int curr_data = temp.data ;
            System.out.print(curr_data + "-->");
            temp = temp.next ;
        }

    }

}

public class CustomLL {

    public static void printLL(LL head ) {

        LL temp = head ;

        while (temp!=null) {

            int curr_data = temp.data ;
            System.out.print(curr_data + "-->");
            temp = temp.next ;
        }

    }

    public static void main(String[] args) {
        LL head = new LL(10) ;
        LL n1 = new LL(11) ;
        LL n2 = new LL(13) ;
        LL n3 = new LL(14) ;
        head.next = n1 ;
        n1.next = n2 ;
        n2.next = n3 ;

        printLL(head );

    }

}
