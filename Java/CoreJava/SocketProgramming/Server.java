package SocketProgramming;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {

    public static void main(String[] args) {

        int port = 12345 ;
        // Create a server socket listening on port 12345
        try {
            ServerSocket serverSocket = new ServerSocket(port) ;
            System.out.println("Server is waiting for a connection...");

            // Accept client connections
            Socket clientSocket = serverSocket.accept() ; //Blocks console until client is connected

            System.out.println("Client connected: " + clientSocket.getInetAddress().getHostAddress());

            // Create input and output streams for communication
            BufferedReader input = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter output = new PrintWriter(clientSocket.getOutputStream() , true) ;
            String message ;
            while ((message = input.readLine()) != null) {
                System.out.println("Client : " + message );
                // Echo the message back to the client
                output.println( message);
            }

            // Close the socket and streams
            clientSocket.close();
            serverSocket.close();

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}
