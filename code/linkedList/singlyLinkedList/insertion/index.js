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
    } else {
      let currentNode = this.head;
      while (currentNode.next != null) {
        currentNode = currentNode.next;
      }
      currentNode.next = newNode;
    }
    return newNode;
  }

  display() {
    let current = this.head;

    while (current != null) {
      console.log(current.data);
      current = current.next;
    }
    console.log("null");
  }

  insertAtBeginning(data) {
    let newNode = new Node(data);
    newNode.next = this.head;
    this.head = newNode;
  }

  insertAtEnd(data) {
    let newNode = new Node(data);
    let currentNode = this.head;

    while (currentNode.next != null) {
      currentNode = currentNode.next;
    }

    currentNode.next = newNode;
    newNode.next = null;
  }

  insertAtSpecificIndex(data, index) {
    let newNode = new Node(data);
    let current = this.head;
    let n = 0;
    while (n != index - 1) {
      current = current.next;
      n++;
    }
    newNode.next = current.next;
    current.next = newNode;
  }

  insertAfterSpecificNode(data, node) {
    let newNode = new Node(data);
    newNode.next = node.next;
    node.next = newNode;
  }
}

let l1 = new List();

l1.append(10);
l1.append(20);
let n = l1.append(30);
l1.insertAtBeginning(5);
l1.insertAtEnd(40);
l1.insertAtSpecificIndex(25, 3);
l1.insertAfterSpecificNode(35, n);

l1.display();
