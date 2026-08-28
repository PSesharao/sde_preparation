import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException ; 
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.FileReader;

public class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader() throws FileNotFoundException {
        //br = new BufferedReader(new InputStreamReader(System.in));
        br = new BufferedReader(new FileReader("input.txt"));
    }

    String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                st = new StringTokenizer(br.readLine());
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() {
        return Integer.parseInt(next());
    }

    long nextLong() {
        return Long.parseLong(next());
    }

    double nextDouble() {
        return Double.parseDouble(next());
    }

    String nextLine() {
        String str = "";
        try {
            str = br.readLine().trim();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return str;
    }

    public void close() throws IOException {
        br.close();
        
    }
}