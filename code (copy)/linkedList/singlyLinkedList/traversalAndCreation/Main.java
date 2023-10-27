package code.linkedList.singlyLinkedList.traversalAndCreation;

class Test {
    public static void main(String[] args) {
        List l = new List();
        l.append(10);
        l.append(20);
        l.append(30);
        l.display();
    }
}

class List {
    Node head;

    List() {
        this.head = null;
    }

    public void append(int value) {
        Node newNode = new Node(value); // * Creating new node */
        if (this.head == null) {
            this.head = newNode; // * If head node is null then assign new node */
        } else {
            Node currentNode = this.head; // *assigning head node to current for further transaction */
            while (currentNode.next != null) {
                currentNode = currentNode.next;
            }
            currentNode.next = newNode;
        }
    }

    public void display() {
        Node current = this.head;
        while (current != null) {
            System.out.print(current.value + "->");
            current = current.next;
        }
        System.out.print("Null\n");
    }
}

class Node {
    int value;
    Node next;

    public Node(int value) {
        this.value = value;
        this.next = null;
    }
}