import java.util.concurrent.atomic.AtomicInteger;

class Atomicity extends Thread {
    // K Srikanth 17ETCS002124
    AtomicInteger Variable_1;
    AtomicInteger Variable_2;

    Atomicity() {
        Variable_1 = new AtomicInteger();
        Variable_2 = new AtomicInteger();
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            Variable_1.addAndGet(1);
            Variable_2.decrementAndGet();
        }
    }
}

public class App {
    public static void main(String[] args) throws InterruptedException {
        // K Srikanth 17ETCS002124
        System.out.println("");
        System.out.println("******** Lab Exam ********");
        System.out.println("******** K Srikanth 17ETCS002124 ********");
        System.out.println("");

        Atomicity obj = new Atomicity();
        Thread thread_1 = new Thread(obj, "First");
        Thread thread_2 = new Thread(obj, "Second");
        thread_1.start();
        thread_2.start();
        thread_1.join();
        thread_2.join();

        System.out.println("This is the First variable : " + obj.Variable_1);
        System.out.println("This is the Second variable : " + obj.Variable_2);

        if (Math.abs(obj.Variable_1.get()) == Math.abs(obj.Variable_2.get())) {
            System.out.println("Variables have been updated correctly");
        } else {
            System.out.println("Variables haven't been updated correctly");
        }
    }
}
