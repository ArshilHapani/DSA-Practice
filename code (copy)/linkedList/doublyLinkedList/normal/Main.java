package code.linkedList.doublyLinkedList.normal;

class Test {
    public static void main(String[] args) {
        List<Integer> l = new List<Integer>();
        l.append(10);
        l.append(20);
        l.append(30);

        l.appendAtStart(5);
        l.appendAtEnd(40);
        l.appendAtSpecificIndex(25, 3);

        l.deleteFirstNode();
        l.deleteLastNode();
        l.deleteByIndex(3);

        l.display();

        l.traverseBiDirection();
    }
}

class Node<T> {
    T data;
    Node<T> next;
    Node<T> prev;

    public Node(T data) {
        this.data = data;
        this.next = null;
        this.prev = null;
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
        } else {
            Node<T> current = this.head;
            while (current.next != null) {
                current = current.next;
            }
            current.next = newNode;
            newNode.prev = current;
            newNode.next = null;
        }
        return newNode;
    }

    public void display() {
        Node<T> current = this.head;

        while (current != null) {
            System.out.print("(" + (current.prev == null ? "null" : current.prev.data) + "," + current.data + ")->");
            current = current.next;
        }
        System.out.print("(null,null) don't be single\n");
    }

    public void appendAtStart(T data) {
        Node<T> newNode = new Node<T>(data);

        newNode.next = this.head;
        this.head.prev = newNode;
        newNode.prev = null;
        this.head = newNode;
    }

    public void appendAtEnd(T data) {
        Node<T> newNode = new Node<T>(data);
        Node<T> current = this.head;

        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
        newNode.prev = current;
        newNode.next = null;
    }

    public void appendAtSpecificIndex(T data, int index) {
        Node<T> newNode = new Node<T>(data);
        Node<T> current = this.head;
        int n = 0;
        while (n != index - 1 && current != null) {
            current = current.next;
            n++;
        }
        if (current == null) {
            System.out.println("Enter an valid index");
            return;
        }
        newNode.next = current.next;
        newNode.prev = current;
        current.next.prev = newNode;
        current.next = newNode;
    }

    public void deleteFirstNode() {
        this.head = this.head.next;
        this.head.prev = null;
    }

    public void deleteLastNode() {
        Node<T> current = this.head;
        while (current.next != null) {
            current = current.next;
        }
        current.prev.next = null;
    }

    public void deleteByIndex(int index) {
        Node<T> current = this.head;
        int n = 0;
        while (n != index - 1 && current != null) {
            current = current.next;
            n++;
        }
        if (current == null) {
            System.out.println("Enter valid index");
        }
        current.prev.next = current.next;
        current.next.prev = current.prev;
    }

    public void traverseBiDirection() {
        Node<T> current = this.head;
        Node<T> last = current;

        while (last.next != null) {
            last = last.next;
        }
        System.out.print("start->");
        while (current != null) {
            System.out.print(current.data + "->");
            current = current.next;
        }
        System.out.print("end->");
        while (last != null) {
            System.out.print(last.data + "->");
            last = last.prev;
        }
        System.out.print("start\n");
    }
}