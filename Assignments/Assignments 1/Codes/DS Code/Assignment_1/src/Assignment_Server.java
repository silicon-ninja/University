import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.StringTokenizer;

public class Assignment_Server {
	public static void main(String args[]) throws IOException {

		ServerSocket socketobj = new ServerSocket(8080);
		Socket soccon = socketobj.accept();
		DataInputStream data_input_stream = new DataInputStream(soccon.getInputStream());
		DataOutputStream data_output_stream = new DataOutputStream(soccon.getOutputStream());
		System.out.println("");
		System.out.println("****** 17ETCS002124 K Srikanth **************");
		System.out.println("****** Server Side **************");

		while (true) {
			String in1 = data_input_stream.readUTF();
			String in2 = data_input_stream.readUTF();
			String choice = data_input_stream.readUTF();
			System.out.println("Received Data from Client");
			int result = 0;
			int Input_1 = Integer.parseInt(in1);
			System.out.println("Srikanth's Input 1 is : " + Input_1);
			int Input_2 = Integer.parseInt(in2);
			System.out.println("Srikanth's Input 2 is : " + Input_2);
			int switch_choice = Integer.parseInt(choice);
			System.out.println("Srikanth's Choice is : " + switch_choice);
			System.out.println("");
			System.out.println("");
			switch (switch_choice) {
				case 1:
					result = Input_1 + Input_2;
					data_output_stream.writeUTF(String.valueOf(result));
					break;
				case 2:
					result = Input_1 - Input_2;
					data_output_stream.writeUTF(String.valueOf(result));
					break;
				case 3:
					result = Input_1 * Input_2;
					data_output_stream.writeUTF(String.valueOf(result));
					break;
				case 4:
					result = Input_1 / Input_2;
					data_output_stream.writeUTF(String.valueOf(result));
					break;
				case 5:
					String bye_String = "Good Bye From Server Hahah XD";
					data_output_stream.writeUTF(bye_String);
					break;
				default:
					System.out.println("Invalid Input Please Try Again");

			}
		}

	}
}
