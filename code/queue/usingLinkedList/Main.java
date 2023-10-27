package code.queue.usingLinkedList;

class Main {
    public static void main(String[] args) {
        QueueUsingLinkedList q1 = new QueueUsingLinkedList();
        q1.enqueue(10);
        q1.enqueue(20);
        q1.enqueue(30);
        q1.enqueue(40);

        System.out.println("Dequeued data is " + q1.dequeue());
        q1.display();
    }
}

class Node {
    public int data;
    public Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class QueueUsingLinkedList {
    Node front;
    Node rear;

    QueueUsingLinkedList() {
        this.front = this.rear = null;
    }

    private boolean isEmpty() {
        return this.front == null && this.rear == null;
    }

    public void enqueue(int data) {
        Node newNode = new Node(data);

        if (this.isEmpty()) {
            this.front = this.rear = newNode;
        } else {
            this.rear.next = newNode;
            this.rear = newNode;
        }
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("Queue underflow");
            return -1;
        }
        Node currentHead = this.front;
        int data = currentHead.data;
        this.front = currentHead.next;
        return data;
    }

    public void display() {
        if (isEmpty()) {
            System.out.println("Queue underflow");
            return;
        }
        Node current = this.front;
        while (current != null) {
            System.out.print(current.data + "->");
            current = current.next;
        }
        System.out.print("null\n");
    }
}