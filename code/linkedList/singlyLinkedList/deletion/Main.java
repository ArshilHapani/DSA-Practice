package code.linkedList.singlyLinkedList.deletion;

class Test {
    public static void main(String[] args) {
        List l = new List();
        l.append(10);
        Node n1 = l.append(20);
        l.append(30);
        l.append(40);
        Node n2 = l.append(50);
        Node n3 = l.append(60);
        l.append(70);

        l.display();
        l.deleteFirstNode();
        l.display();
        l.deleteEndNode();
        l.display();
        l.deleteBySpecificValue(40);
        l.display();
        l.deleteBySpecificIndex(2);
        l.display();
        l.deleteAfterSpecificNode(n2, n1);
        l.deleteByNode(n3);

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
            Node currentNode = this.head;

            while (currentNode.next != null) {
                currentNode = currentNode.next;
            }
            currentNode.next = newNode;
        }
        return newNode;
    }

    public void display() {
        Node current = this.head;
        while (current != null) {
            System.out.print(current.data + "->");
            current = current.next;
        }
        System.out.print("null\n");
    }

    public void deleteFirstNode() {
        Node nextNode = this.head.next;
        this.head = nextNode;
    }

    public void deleteEndNode() {
        Node end = this.head.next;
        Node beforeEnd = this.head;
        while (end.next != null) {
            end = end.next;
            beforeEnd = beforeEnd.next; // it stops before end node as end node encounters null earlier
        }
        beforeEnd.next = null;
    }

    public void deleteBySpecificValue(int value) {
        Node forwardNode = this.head.next;
        Node currentNode = this.head;
        while (forwardNode.data != value) {
            forwardNode = forwardNode.next;
            currentNode = currentNode.next;
        }
        currentNode.next = forwardNode.next;
    }

    public void deleteBySpecificIndex(int index) {
        Node forwardNode = this.head.next;
        Node currentNode = this.head;
        int n = 0;
        while (n != index - 2) {
            forwardNode = forwardNode.next;
            currentNode = currentNode.next;
            n++;
        }
        currentNode.next = forwardNode.next;
    }

    public void deleteAfterSpecificNode(Node node_to_delete, Node n) {
        Node nextNode = node_to_delete.next;
        n.next = nextNode;
    }

    public void deleteByNode(Node n) {
        Node current = this.head.next;
        Node prev = this.head;

        while (current != n) {
            current = current.next;
            prev = prev.next;
        }
        prev.next = n.next;
    }
}