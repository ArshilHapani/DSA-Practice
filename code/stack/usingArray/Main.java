package code.stack.usingArray;

import java.util.ArrayList;
import java.util.List;

class Test {
    public static void main(String[] args) {
        Stack<String> s = new Stack<String>(5);
        s.push("nami");
        s.push("robin");
        s.push("luffy");
        s.push("misa");
        s.push("zoro");

        // s.pop();

        s.display();
        System.out.println("Peeked element = " + s.peek(1));
    }
}

class Stack<T> {
    private int size;
    private int top;
    private List<T> arr;

    Stack(int size) {
        this.size = size;
        this.top = -1;
        this.arr = new ArrayList<T>(size);
    }

    public boolean isEmpty() {
        if (this.top == -1) {
            System.out.println("Stack underflow");
            return true;
        }
        return false;
    }

    public boolean isFull() {
        if (this.top == this.size - 1) {
            System.out.println("Stack overflow");
            return true;
        }
        return false;
    }

    public T push(T data) {
        if (isFull()) {
            return null;
        }
        this.arr.add(data);
        this.top++;
        return data;
    }

    public void display() {
        if (isEmpty()) {
            return;
        }
        for (int i = 0; i < this.top + 1; i++) {
            System.out.println(this.arr.get(i));
        }
    }

    public T pop() {
        if (isEmpty()) {
            return null;
        }
        T element = this.arr.get(this.top);
        this.arr.set(this.top, null);
        this.top--;
        return element;
    }

    public T peek(int index) {
        if (isEmpty()) {
            return null;
        }
        if (index >= this.top) {
            System.out.println("Index out of bound");
            return null;
        }
        return this.arr.get(this.size - index);
    }
}