import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class Assignment_Client {

	// 17ETCS002124 K Srikanth
	public static void main(String[] args) throws IOException {
		InetAddress ip_address = InetAddress.getLocalHost();
		int port_num = 8080;
		Scanner scanobj = new Scanner(System.in);
		Socket socketobj = new Socket(ip_address, port_num);
		DataInputStream data_input_stream = new DataInputStream(socketobj.getInputStream());
		DataOutputStream data_output_stream = new DataOutputStream(socketobj.getOutputStream());
		System.out.println("");
		System.out.println("****** 17ETCS002124 K Srikanth **************");
		System.out.println("****** Client Side **************");

		while (true) {
			System.out.println("");
			System.out.print("Enter the Inputs\n");
			System.out.print("*****************************************\n");
			System.out.print("Enter the First Number\n");
			String input_1 = scanobj.nextLine();
			System.out.print("Enter the Second Number\n");
			String input_2 = scanobj.nextLine();
			System.out.print("********* Calculator *********\n");
			System.out.print("Press 1 For Addition\n");
			System.out.print("Press 2 For Subtraction\n");
			System.out.print("Press 3 For Multiplication\n");
			System.out.print("Press 4 For Division\n");
			System.out.print("Press 5 to exit\n");
			String choice = scanobj.nextLine();
			data_output_stream.writeUTF(input_1);
			data_output_stream.writeUTF(input_2);
			if (choice.equals("1")) {
				data_output_stream.writeUTF(choice);
				String result = data_input_stream.readUTF();
				System.out.println("The Addition you're looking for is " + result);
				continue;
			}
			if (choice.equals("2")) {
				data_output_stream.writeUTF(choice);
				String result = data_input_stream.readUTF();
				System.out.println("The Subtraction you're looking for is " + result);
				continue;
			}
			if (choice.equals("3")) {
				data_output_stream.writeUTF(choice);
				String result = data_input_stream.readUTF();
				System.out.println("The Multiplication you're looking for is " + result);
				continue;
			}
			if (choice.equals("4")) {
				data_output_stream.writeUTF(choice);
				String result = data_input_stream.readUTF();
				System.out.println("The Division you're looking for is " + result);
				continue;
			}
			if (choice.equals("5")) {
				data_output_stream.writeUTF(choice);
				String result = data_input_stream.readUTF();
				System.out.println("The resultwer you're looking for is " + result);
				break;
			}

		}

	}

}
