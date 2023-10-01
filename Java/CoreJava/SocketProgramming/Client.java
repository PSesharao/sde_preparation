package SocketProgramming;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class Client {
    public static void main(String[] args) {
        try {
            // Create a socket to connect to the server on localhost, port 12345
            Socket socket = new Socket("localhost", 12345);

            // Create input and output streams for communication
            BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            // Create a reader for user input
            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));

            String message;

            while (true) {
                // Read a message from the user console
                System.out.print("Enter a message to send to the server: ");
                message = userInput.readLine();

                // Send the message to the server
                out.println(message);

                // Receive and print the server's response
                String serverResponse = in.readLine();
                System.out.println("Server: " + serverResponse);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
