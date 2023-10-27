package code.queue.doubleEndedQueue;

import java.util.ArrayList;
import java.util.List;

class Main {
    public static void main(String[] args) {
        MyQueue<String> q = new MyQueue<String>(5);

        q.enqueueR("nami");
        q.enqueueR("robin");
        q.enqueueR("luffy");

        System.out.println("Dequeued element is from front " + q.dequeueF());
        System.out.println("Dequeued element is from rear " + q.dequeueR());

        q.enqueueF("Zoro");
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

    public void enqueueR(T data) {
        if (isFull()) {
            return;
        }
        this.rear++;
        this.list.add(this.rear, data);
    }

    public void enqueueF(T data) {
        if (this.front == -1) {
            System.out.println("Cannot insert element at beginning");
            return;
        }
        this.list.add(this.front, data);
        this.front--;
    }

    public T dequeueF() {
        if (isFull()) {
            return null;
        }
        this.front++;
        T data = this.list.get(this.front);
        this.list.set(this.front, null);
        return data;
    }

    public T dequeueR() {
        if (isFull()) {
            return null;
        }
        T data = this.list.get(this.rear);
        this.list.set(this.rear, null);
        this.rear--;
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

}