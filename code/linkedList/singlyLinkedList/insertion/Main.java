package code.linkedList.singlyLinkedList.insertion;

class Test {
    public static void main(String[] args) {
        List l = new List();
        l.append(10);
        Node n = l.append(20);
        l.append(30);
        l.appendAtStart(5);
        l.appendAtEnd(40);
        l.appendAtSpecificIndex(15, 2);
        l.appendAfterSpecificNode(25, n);
        l.display();
    }
}

class Node {
    int data;
    Node next;

    public Node(int data) {
        this.data = data;
        this.next = null;
    }
}

class List {
    Node head;

    List() {
        this.head = null;
    }

    public Node append(int data) {
        Node newNode = new Node(data);
        if (this.head == null) {
            this.head = newNode;
        } else {
            Node current = this.head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
        }
        return newNode;
    }

    public void display() {
        Node currentNode = this.head;
        while (currentNode != null) {
            System.out.print(currentNode.data + "->");
            currentNode = currentNode.next;
        }
        System.out.print("null\n");
    }

    public void appendAtStart(int data) {
        Node newNode = new Node(data);
        newNode.next = this.head;
        this.head = newNode;
    }

    public void appendAtEnd(int data) {
        Node newNode = new Node(data);
        Node current = this.head;

        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
        newNode.next = null;
    }

    public void appendAtSpecificIndex(int data, int index) {
        Node newNode = new Node(data);
        Node previousNode = this.head;
        int n = 0;
        while (n != index - 1) {
            previousNode = previousNode.next;
            n++;
        }
        newNode.next = previousNode.next;
        previousNode.next = newNode;
    }

    public void appendAfterSpecificNode(int data, Node node) {
        Node newNode = new Node(data);
        newNode.next = node.next;
        node.next = newNode;
    }
}