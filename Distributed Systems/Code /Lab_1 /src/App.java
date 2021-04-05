import java.util.Scanner;
public class App {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.println("");
        System.out.println("************ K Srikanth 17ETCS002124 ************");
        System.out.println("************ Lab 1 ************");
        System.out.println("");
        System.out.println("************ Question 1 ************");
        int n = 2; // Number of threads
        for (int i = 0; i < n; i++) {
            HelloWorldMethod Hello = new HelloWorldMethod();
            Hello.start(); // Two Threads for Hello World
            Hello.join(); // Joining the Threads
        }
        System.out.println("");
        System.out.println("************ Question 2 ************");
        System.out.println("************ Calculator ************");
        System.out.println("Enter the 1st Number : ");
        int x = input.nextInt();
        System.out.println("Enter the 2nd Number : ");
        int y = input.nextInt();
        Addition add = new Addition(x, y);
        Subtraction sub = new Subtraction(x, y);
        Multiply mull = new Multiply(x, y);
        Division div = new Division(x, y);
        add.start(); // Thread 1
        sub.start(); // Thread 2
        mull.start(); // Thread 3
        div.start(); // Thread 4
        add.join(); // Joining Thread 1
        sub.join(); // Joining Thread 2
        mull.join(); // Joining Thread 3
        div.join(); // Joining Thread 4
        input.close(); // Done Taking Input 
    }
}


class HelloWorldMethod extends Thread {
    public void run() {
            System.out.println("Hello World Created by Thread " + Thread.currentThread().getId() + ".");
    }
}



class Addition extends Thread {
    int a, b;

    Addition(int x, int y) {
        a = x;
        b = y;
    }

    public void run() {
        int add = a + b;
        System.out.println("The Sum of " + a + " and " + b + " is " + add);
    }
}

class Subtraction extends Thread {
    int a, b;

    Subtraction(int x, int y) {
        a = x;
        b = y;
    }

    public void run() {
        int sub = a - b;
        System.out.println("The Subtraction of " + a + " and " + b + " is " + sub);
    }
}

class Multiply extends Thread {
    int a, b;

    Multiply(int x, int y) {
        a = x;
        b = y;
    }

    public void run() {
        int mull = a * b;
        System.out.println("The Multiplication of " + a + " and " + b + " is " + mull);
    }
}

class Division extends Thread {
    int a, b;

    Division(int x, int y) {
        a = x;
        b = y;
    }

    public void run() {
        int div = a / b;
        System.out.println("The Division of " + a + " and " + b + " is " + div);
    }
}