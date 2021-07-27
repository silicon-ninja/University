
import java.util.concurrent.locks.*;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class App {
    public static void main(String[] args) {
        testClass<Integer> A = new testClass<>(1000);
        testClass<Integer> B = new testClass<>(2000);
        testClass<Integer> C = new testClass<>(3000);

        new transaction1(A, B, C, "1").start();
        new transaction2(A, B, C, "2").start();
    }
}

class transaction1 extends Thread {
    private testClass<Integer> A;
    private testClass<Integer> B;
    private testClass<Integer> C;
    String t;

    public transaction1(testClass<Integer> A, testClass<Integer> B, testClass<Integer> C, String t) {
        this.A = A;
        this.B = B;
        this.C = C;
        this.t = t;
    }

    @Override
    public void run() {
        int balance;
        balance = B.getBalance();
        B.setBalance(balance * 2, t);
        B.getBalance();
        A.withdraw(balance / 10);
        A.getBalance();
        try {
            System.out.println("Transaction 1 complete!\n");
            Thread.sleep(100);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

class transaction2 extends Thread {
    private testClass<Integer> A;
    private testClass<Integer> B;
    private testClass<Integer> C;
    String t;

    public transaction2(testClass<Integer> A, testClass<Integer> B, testClass<Integer> C, String t) {
        this.A = C;
        this.B = B;
        this.C = C;
        this.t = t;
    }

    @Override
    public void run() {
        int balance;
        balance = B.getBalance();
        B.setBalance(balance * 3, t);
        B.getBalance();
        C.withdraw(balance / 5);
        C.getBalance();
        try {
            System.out.println("Transaction 2 complete!\n");
            Thread.sleep(100);
        } catch (Exception e) {
            System.out.println(e);
        }

    }
}

class testClass<testObj> {
    private testObj obj;
    private ReadWriteLock LOCK = new ReentrantReadWriteLock();

    testClass(testObj obj) {
        this.obj = obj;
    }

    public testObj getBalance() {
        System.out.println("Balance: Rs." + obj + "\n");
        return obj;
    }

    public void setBalance(testObj val, String t) {
        Lock writeLock = LOCK.writeLock();
        writeLock.lock();
        System.out.println("Transaction " + t + " has started");
        try {
            obj = val;
            System.out.println("Balance updated!");
        } finally {
            writeLock.unlock();
        }
    }

    public void deposit(testObj val) {
        System.out.println("Deposit function");
        String balance;
        int bal, amount;
        Lock writeLock = LOCK.writeLock();
        writeLock.lock();
        try {
            bal = Integer.parseInt(obj.toString());
            amount = Integer.parseInt(val.toString());
            bal += amount;
            balance = String.valueOf(bal);
            obj = (testObj) balance;
            System.out.println("Rs." + val + " was deposited!");
        } finally {
            writeLock.unlock();
        }
    }

    public void withdraw(testObj val) {
        System.out.println("Withdraw function");
        String balance;
        int bal, amount;
        Lock writeLock = LOCK.writeLock();
        writeLock.lock();
        try {
            bal = Integer.parseInt(obj.toString());
            amount = Integer.parseInt(val.toString());
            if (bal > amount) {
                bal -= amount;
                balance = String.valueOf(bal);
                obj = (testObj) balance;
            } else {
                System.out.println("you don't have sufficient balance........");
            }
        } finally {
            System.out.println("Rs." + val + " was withdrawn!");
            writeLock.unlock();
        }
    }
}