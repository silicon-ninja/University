
import java.util.LinkedList;

public class Lab_4 {
    public static void main(String[] args) throws InterruptedException {
        // K Srikanth 17ETCS002124
        final PC pc = new PC();

        Thread t1 = new Thread(new Runnable() {
            // K Srikanth 17ETCS002124
            @Override
            public void run() {
                try {
                    pc.produce();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread t2 = new Thread(new Runnable() {
            // K Srikanth 17ETCS002124
            @Override
            public void run() {
                try {
                    pc.consume();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();
    }

    public static class PC {
        // K Srikanth 17ETCS002124
        LinkedList<Integer> list = new LinkedList<>();
        int capacity = 2;

        public void produce() throws InterruptedException {
            int value = 0;
            while (true) {
                synchronized (this) {
                    while (list.size() == capacity)
                        wait();
                    System.out.println("Producer Produced Item => " + value);

                    list.add(value++);

                    notify();

                    Thread.sleep(1000);
                }
            }
        }

        public void consume() throws InterruptedException {
            // K Srikanth 17ETCS002124
            while (true) {
                synchronized (this) {

                    while (list.size() == 0)
                        wait();

                    int val = list.removeFirst();

                    System.out.println("Consumer Just Consumed Item =>" + val);

                    notify();

                    Thread.sleep(1000);
                }
            }
        }
    }
}
