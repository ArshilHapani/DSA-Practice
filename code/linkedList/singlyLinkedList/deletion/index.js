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
      let current = this.head;
      while (current.next != null) {
        current = current.next;
      }
      current.next = newNode;
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

  deleteFirstNode() {
    let temp = this.head;
    this.head = temp.next;
  }

  deleteLastNode() {
    let current = this.head.next;
    let prev = this.head;
    while (current.next != null) {
      current = current.next;
      prev = prev.next;
    }
    prev.next = null;
  }

  deleteNodeByValue(val) {
    let current = this.head.next;
    let prev = this.head;

    while (current.data != val) {
      current = current.next;
      prev = prev.next;
    }
    prev.next = current.next;
  }

  deleteAtSpecificIndex(index) {
    let current = this.head.next;
    let prev = this.head;
    let n = 1;
    while (n != index - 1) {
      current = current.next;
      prev = prev.next;
      n++;
    }
    prev.next = current.next;
  }

  deleteBySpecificNode(node) {
    let current = this.head.next;
    let prev = this.head;
    while (current != node) {
      current = current.next;
      prev = prev.next;
    }

    prev.next = node.next;
  }
  findLength() {
    let current = this.head;
    let length = 0;
    while (current != null) {
      length++;
      current = current.next;
    }
    return length;
  }
  deleteNodeFromLastIndex(index) {
    let length = this.findLength();
    let indexToDelete = length - index + 1;
    this.deleteAtSpecificIndex(indexToDelete);
  }
}

let l = new List();
l.append(10);
l.append(20);
let node = l.append(30);
l.append(40);
l.append(50);
l.append(60);
l.append(70);

// l.deleteFirstNode();
// l.deleteLastNode();
// l.deleteNodeByValue(50);
// l.deleteAtSpecificIndex(3);
l.deleteNodeFromLastIndex(3);
// l.deleteBySpecificNode(node);

l.display();
