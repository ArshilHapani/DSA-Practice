package code.queue.usingArray.circularQueue;

public class Main {
    public static void main(String[] args) {
        CircularQueue<Integer> c = new CircularQueue<>(5);
        c.enqueue(10);
        c.enqueue(20);
        c.enqueue(30);
        c.enqueue(40);
        c.enqueue(50);

        c.dequeue();
        c.dequeue();
        c.dequeue();
        c.dequeue();

        c.enqueue(10);
        c.enqueue(20);
        c.enqueue(30);
        c.enqueue(40);

        c.display();
    }
}

class CircularQueue<T> {
    private int size;
    private int front;
    private int rear;
    private Object[] arr;

    public CircularQueue(int size) {
        this.size = size + 1;
        this.front = this.rear = -1;
        this.arr = new Object[size + 1];
    }

    public boolean isEmpty() {
        return this.rear == this.front;
    }

    public boolean isFull() {
        return (this.rear + 1) % this.size == this.front;
    }

    public void enqueue(T data) {
        if (isFull()) {
            System.out.println("Queue overflow");
            return;
        }
        this.rear = (this.rear + 1) % this.size;
        this.arr[this.rear] = data;
    }

    public T dequeue() {
        if (isEmpty()) {
            System.out.println("Queue underflow");
            return null;
        }
        this.front = (this.front + 1) % this.size;
        @SuppressWarnings("Unchecked cast from Object to T")
        T val = (T) this.arr[this.front];
        this.arr[this.front] = null;
        return val;
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue underflow");
            return;
        }
        for (int i = 0; i < this.size; i++) {
            System.out.print(this.arr[i] + ",");
        }
        System.out.println();
    }
}