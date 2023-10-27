class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class List {
  constructor() {
    this.head = null;
  }

  append(value) {
    let newNode = new Node(value);

    if (this.head == null) {
      this.head = newNode;
      this.head.next = this.head;
    } else {
      let current = this.head;

      while (current.next != this.head) {
        current = current.next;
      }
      current.next = newNode;
      newNode.next = this.head;
    }
  }

  display() {
    let current = this.head;
    do {
      console.log(current.data);
      current = current.next;
    } while (current != this.head);
  }

  insertAtBeginning(value) {
    let newNode = new Node(value);
    let current = this.head;
    while (current.next != this.head) {
      current = current.next;
    }
    current.next = newNode;
    newNode.next = this.head;
    this.head = newNode;
  }

  insertAtEnd(value) {
    let newNode = new Node(value);
    let current = this.head;
    while (current.next != this.head) {
      current = current.next;
    }
    current.next = newNode;
    newNode.next = this.head;
  }

  insertAtSpecificIndex(value, index) {
    let newNode = new Node(value);
    let current = this.head;
    let n = 0;

    while (n != index - 1) {
      current = current.next;
      n++;
    }
    newNode.next = current.next;
    current.next = newNode;
  }

  deleteFirstNode() {
    let current = this.head;
    while (current.next != this.head) {
      current = current.next;
    }
    current.next = this.head.next;
    this.head = this.head.next;
  }

  deleteLastNode() {
    let current = this.head.next;
    let previous = this.head;
    while (current.next != this.head) {
      current = current.next;
      previous = previous.next;
    }
    previous.next = this.head;
  }

  deleteAtSpecificIndex(index) {
    let current = this.head.next;
    let previous = this.head;
    let n = 0;
    while (n != index - 2) {
      current = current.next;
      previous = previous.next;
      n++;
    }
    previous.next = current.next;
  }
}

let l = new List();

l.append(10);
l.append(20);
l.append(30);

l.insertAtBeginning(5);
l.insertAtEnd(40);
l.insertAtSpecificIndex(25, 3);

l.deleteFirstNode();
l.deleteLastNode();
l.deleteAtSpecificIndex(3);

l.display();
