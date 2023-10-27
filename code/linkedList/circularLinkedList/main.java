package code.linkedList.circularLinkedList;

class Test {
    public static void main(String[] args) {
        List<Integer> l = new List<Integer>();
        l.append(10);
        l.append(20);
        l.append(30);

        l.insertAtBeginning(5);
        l.insertAtEnd(40);
        l.insertAtSpecificIndex(25, 3);

        l.deleteFirstNode();
        l.deleteLastNode();
        l.deleteSpecificIndex(3);

        l.display();
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

class List<T> {
    Node<T> head;

    List() {
        this.head = null;
    }

    public Node<T> append(T data) {
        Node<T> newNode = new Node<T>(data);
        if (this.head == null) {
            this.head = newNode;
            this.head.next = this.head;
        } else {
            Node<T> current = this.head.next;
            while (current.next != this.head) {
                current = current.next;
            }
            current.next = newNode;
            newNode.next = this.head;
        }
        return newNode;
    }

    public void display() {
        Node<T> current = this.head;
        do {
            System.out.print(current.data + "->");
            current = current.next;
        } while (current != this.head);
        System.out.println("HEAD(" + current.data + ")");
    }

    public void insertAtBeginning(T data) {
        Node<T> newNode = new Node<T>(data);
        Node<T> lastNode = this.head;
        while (lastNode.next != this.head) {
            lastNode = lastNode.next;
        }
        lastNode.next = newNode;
        newNode.next = this.head;
        this.head = newNode;
    }

    public void insertAtEnd(T data) {
        Node<T> newNode = new Node<T>(data);
        Node<T> current = this.head;

        while (current.next != this.head) {
            current = current.next;
        }
        newNode.next = this.head;
        current.next = newNode;
    }

    public void insertAtSpecificIndex(T data, int index) {
        Node<T> newNode = new Node<T>(data);
        Node<T> current = this.head;
        int n = 0;
        while (n != index - 1) {
            current = current.next;
            n++;
        }
        newNode.next = current.next;
        current.next = newNode;
    }

    public void deleteFirstNode() {
        Node<T> current = this.head;

        while (current.next != this.head) {
            current = current.next;
        }
        current.next = this.head.next;
        this.head = this.head.next;
    }

    public void deleteLastNode() {
        Node<T> current = this.head.next;
        Node<T> previous = this.head;
        while (current.next != this.head) {
            current = current.next;
            previous = previous.next;
        }
        previous.next = this.head;
    }

    public void deleteSpecificIndex(int index) {
        Node<T> current = this.head.next;
        Node<T> previous = this.head;
        int n = 0;

        while (n != index - 2) {
            current = current.next;
            previous = previous.next;
            n++;
        }
        previous.next = current.next;
    }
}