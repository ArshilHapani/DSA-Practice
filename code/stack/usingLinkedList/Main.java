package code.stack.usingLinkedList;

class Test {
    public static void main(String[] args) {
        Stack<String> s = new Stack<String>();
        s.push("Nami");
        s.push("Robin");
        s.push("Luffy");
        s.push("Zoro");

        System.out.println("Popped element is " + s.pop());
        System.out.println("Peeked element is " + s.peek(3));
        System.out.println("StackTop element is " + s.stackTop());
        System.out.println("StackBottom element is " + s.stackBottom());

        s.display();
    }
}

class Node<T> {
    T data;
    Node<T> next;

    public Node(T data) {
        this.data = data;
        this.next = null;
    }
}

class Stack<T> {
    Node<T> top;

    Stack() {
        this.top = null;
    }

    public boolean isEmpty() {
        if (this.top == null) {
            System.out.println("Stack Underflow");
            return true;
        }
        return false;
    }

    public void display() {
        if (isEmpty()) {
            return;
        }
        Node<T> current = this.top;

        while (current != null) {
            System.out.println(current.data);
            current = current.next;
        }
    }

    public void push(T data) {
        Node<T> newNode = new Node<T>(data);

        if (this.top == null) {
            this.top = newNode;
        } else {
            newNode.next = this.top;
            this.top = newNode;
        }
    }

    public T peek(int index) {
        int n = 1;
        Node<T> current = this.top;
        while (n != index && current != null) {
            current = current.next;
            n++;
        }
        if (current == null) {
            throw new Error("Invalid index");
        }
        return current.data;
    }

    public T pop() {
        T data = this.top.data;
        this.top = this.top.next;
        return data;
    }

    public T stackTop() {
        if (isEmpty()) {
            return null;
        }
        return this.top.data;
    }

    public T stackBottom() {
        if (isEmpty()) {
            return null;
        }
        Node<T> current = this.top;
        while (current.next != null) {
            current = current.next;
        }
        return current.data;
    }
}