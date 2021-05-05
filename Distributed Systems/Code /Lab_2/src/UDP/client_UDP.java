package UDP;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

// 17ETCS002124 K Srikanth
public class client_UDP {
    /*
     * The server port to which the client socket is going to connect
     */
    public final static int SERVICE_PORT = 8080;

    public static void main(String[] args) throws IOException {
        try {
            DatagramSocket clientSocket = new DatagramSocket();

            // Get the IP address of the server
            InetAddress IPAddress = InetAddress.getByName("localhost");
            byte[] sendingDataBuffer = new byte[1024];
            byte[] receivingDataBuffer = new byte[1024];
            String sentence = "Hello from UDP client";
            sendingDataBuffer = sentence.getBytes();
            DatagramPacket sendingPacket = new DatagramPacket(sendingDataBuffer, sendingDataBuffer.length, IPAddress,
                    SERVICE_PORT);
            clientSocket.send(sendingPacket);
            DatagramPacket receivingPacket = new DatagramPacket(receivingDataBuffer, receivingDataBuffer.length);
            clientSocket.receive(receivingPacket);
            // Printing the received data
            String receivedData = new String(receivingPacket.getData());
            System.out.println("Sent from the server: " + receivedData);
            // Closing the socket connection with the server
            clientSocket.close();
        } catch (SocketException e) {
            e.printStackTrace();
        }
    }
}
