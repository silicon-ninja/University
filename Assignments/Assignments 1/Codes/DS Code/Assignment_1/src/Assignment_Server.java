import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.StringTokenizer;

public class Assignment_Server {

	// 17ETCS002124 K Srikanth
	public static void main(String args[]) throws IOException {

		ServerSocket ss = new ServerSocket(8080);
		Socket s = ss.accept();
		DataInputStream dis = new DataInputStream(s.getInputStream());
		DataOutputStream dos = new DataOutputStream(s.getOutputStream());
		while (true) {
			// 17ETCS002124 K Srikanth

			String input = dis.readUTF();
			System.out.println("Input received:-" + input);
			int result = 0;
			StringTokenizer st = new StringTokenizer(input);
			int Input_1 = Integer.parseInt(st.nextToken());
			String operation = st.nextToken();
			int Input_2 = Integer.parseInt(st.nextToken());
			if (operation.equals("+")) {
				result = Input_1 + Input_2;
			} else if (operation.equals("-")) {
				result = Input_1 - Input_2;
			} else if (operation.equals("*")) {
				result = Input_1 * Input_2;
			} else if (operation.equals("/")) {
				result = Input_1 / Input_2;
			}
			System.out.println("Sending the Caculation to Client");

			dos.writeUTF(String.valueOf(result));
		}
	}
}
