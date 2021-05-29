import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

public class Assignment_Client {

	// 17ETCS002124 K Srikanth
	public static void main(String[] args) throws IOException {
		InetAddress ip = InetAddress.getLocalHost();
		int port = 8080;
		Scanner sc = new Scanner(System.in);
		Socket s = new Socket(ip, port);
		DataInputStream dis = new DataInputStream(s.getInputStream());
		DataOutputStream dos = new DataOutputStream(s.getOutputStream());
		System.out.println("");
		System.out.println("****** 17ETCS002124 K Srikanth **************");
		System.out.println("****** Client Side **************");

		while (true) {
			System.out.println("");
			System.out.print("Enter the Inputs\n");
			System.out.print("*****************************************\n");
			System.out.print("Enter the First Number\n");
			String input_1 = sc.nextLine();
			System.out.print("Enter the Second Number\n");
			String input_2 = sc.nextLine();
			System.out.print("********* Calculator *********\n");
			System.out.print("Press 1 For Addition\n");
			System.out.print("Press 2 For Subtraction\n");
			System.out.print("Press 3 For Multiplication\n");
			System.out.print("Press 4 For Division\n");
			System.out.print("Press 5 to exit\n");
			String choice = sc.nextLine();
			dos.writeUTF(input_1);
			dos.writeUTF(input_2);
			if (choice.equals("1")) {
				dos.writeUTF(choice);
				String ans = dis.readUTF();
				System.out.println("The Addition you're looking for is " + ans);
				continue;
			}
			if (choice.equals("2")) {
				dos.writeUTF(choice);
				String ans = dis.readUTF();
				System.out.println("The Subtraction you're looking for is " + ans);
				continue;
			}
			if (choice.equals("3")) {
				dos.writeUTF(choice);
				String ans = dis.readUTF();
				System.out.println("The Multiplication you're looking for is " + ans);
				continue;
			}
			if (choice.equals("4")) {
				dos.writeUTF(choice);
				String ans = dis.readUTF();
				System.out.println("The Division you're looking for is " + ans);
				continue;
			}
			if (choice.equals("5")) {
				dos.writeUTF(choice);
				String ans = dis.readUTF();
				System.out.println("The Answer you're looking for is " + ans);
				break;
			}

		}

	}

}
