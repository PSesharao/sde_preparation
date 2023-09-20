package Strings;

public class Example {
    public static void main(String[] args) {
        String str = "Hello" ;
        char [] chars = str.toCharArray() ;
        int len = chars.length ;
        for(int i=0; i<len/2 ; i++ ){

            char ch = chars[i] ;
            chars[i] = chars[len-1-i] ;
            chars[len-1-i] = ch ;

        }

        str = new String(chars) ;

        System.out.println(str);

    }
}
