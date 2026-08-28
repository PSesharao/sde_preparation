import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileNotFoundException ; 
import java.io.OutputStreamWriter;
import java.io.FileWriter;

public class FastWriter {
    private final BufferedWriter bw;

    public FastWriter() throws  IOException , FileNotFoundException {
        //this.bw = new BufferedWriter(new OutputStreamWriter(System.out));
        this.bw = new BufferedWriter(new FileWriter("output.txt"));
    }

    public void print(Object object) throws IOException {
        bw.append("" + object);
    }

    public void println(Object object) throws IOException {
        print(object);
        bw.append("\n");
    }

    public void close() throws IOException {
        bw.close();
    }
}