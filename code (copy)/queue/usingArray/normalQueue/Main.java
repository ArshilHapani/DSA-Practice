package code.queue.usingArray.normalQueue;

import java.util.ArrayList;
import java.util.List;

class Main {
    public static void main(String[] args) {
        MyQueue<String> q = new MyQueue<String>(5);

        q.enqueue("nami");
        q.enqueue("robin");
        q.enqueue("luffy");

        System.out.println("Dequeued element is " + q.dequeue());
        System.out.println("Peeked element at position 3 is " + q.peek(3));
        System.out.println("Queue top element is " + q.queueTop());
        System.out.println("Queue bottom element is " + q.queueBottom());

        q.display();
    }
}

class MyQueue<T> {
    List<T> list;
    int front;
    int rear;
    int size;

    public MyQueue(int size) {
        this.list = new ArrayList<T>(size);
        this.size = size;
        this.rear = this.front = -1;
    }

    private boolean isFull() {
        return this.rear == this.size - 1;
    }

    private boolean isEmpty() {
        return this.rear == this.front;
    }

    public void enqueue(T data) {
        if (isFull()) {
            return;
        }
        this.rear++;
        this.list.add(this.rear, data);
    }

    public T dequeue() {
        if (isFull()) {
            return null;
        }
        this.front++;
        T data = this.list.get(this.front);
        this.list.set(this.front, null);
        return data;
    }

    public void display() {
        if (isEmpty()) {
            return;
        }
        for (T t : this.list) {
            System.out.println(t);
        }
    }

    public T peek(int pos) {
        if (pos > this.size) {
            System.out.println("Enter valid index");
        }
        return this.list.get(pos - 1);
    }

    public T queueTop() {
        return this.list.get(this.front + 1);
    }

    public T queueBottom() {
        return this.list.get(this.rear);
    }

}