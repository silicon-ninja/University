import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

public class App {
    // AtomicInteger supports atomic operations on underlying int variable.
    static AtomicInteger balance = new AtomicInteger(200);

    public static void main(String[] args) throws Exception {

        while (true) {
            Scanner sc = new Scanner(System.in);
            System.out
                    .println("1. Press 1 for balance enquiry" + "\n2. Press 2 for withdrawal\n3. Press 3 for deposit");
            int choice = sc.nextInt(); // take user input for the selected option
            if (choice == 1) {
                try {
                    // create an object of class Equiry
                    Enquiry balance_enquiry = new Enquiry();
                    balance_enquiry.start();// the thread starts execution
                    balance_enquiry.join();
                } catch (Exception ex) {
                    System.out.println(ex);
                }
            } else if (choice == 2) {
                try {
                    // create an object of class Withdraw
                    Withdraw w = new Withdraw();
                    w.start(); // the thread w starts execution
                    w.join();
                } catch (Exception ex) {
                    System.out.println(ex);
                }

            } else if (choice == 3) {
                try {
                    // create an object of class Deposit
                    Deposit d = new Deposit();
                    d.start(); // the thread d starts execution
                    d.join();
                } catch (Exception ex) {
                    System.out.println(ex);
                }
            } else {
                System.out.println("Please press an option from the above list.");
            }
        }
    }

    private static class Enquiry extends Thread {
        @Override
        public void run() {
            try {
                // public int get() - Gets the current value.
                System.out.println("Your current balance is: " + balance.get());
            } catch (Exception ex) {
                System.out.println(ex);
            }
        }
    }

    private static class Withdraw extends Thread {
        @Override
        public void run() {
            Scanner sc = new Scanner(System.in);
            try {
                System.out.println("Enter the amount to withdraw");
                int withdraw_amount = sc.nextInt();
                // public void set(int newValue) - Sets to the given value.
                // public int get() - Gets the current value.
                int currentBalance = balance.get(); // get the current balance
                // check if withdrawal amount is less than current balance
                if (currentBalance - withdraw_amount >= 0) {
                    balance.set(currentBalance - withdraw_amount);
                    System.out.println("Withdrawal Successful");
                    System.out.println("Your balance is :Rs." + balance.get());
                } else
                    System.out.println("You only have Rs." + currentBalance + " in your account.");
            } catch (Exception ex) {
                System.out.println(ex);
            }
        }
    }

    private static class Deposit extends Thread {
        @Override
        public void run() {
            Scanner sc = new Scanner(System.in);
            try {
                System.out.println("Enter the amount to deposit");
                int deposit_amount = sc.nextInt();
                // public int addAndGet(int delta) - Atomically adds the
                // given value to the current value.
                System.out.println(
                        "Deposit Successful." + "\nYour current balance is: Rs." + balance.addAndGet(deposit_amount));
            } catch (Exception ex) {
                System.out.println(ex);
            }
        }
    }
}
