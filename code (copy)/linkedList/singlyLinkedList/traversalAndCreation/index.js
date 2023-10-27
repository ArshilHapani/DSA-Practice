class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

class List {
  constructor() {
    this.head = null;
  }

  append(element) {
    let newNode = new Node(element);

    if (this.head === null) {
      this.head = newNode;
    } else {
      let current = this.head;
      while (current.next !== null) {
        current = current.next;
      }
      current.next = newNode;
    }
  }

  display() {
    let current = this.head;

    while (current != null) {
      console.log(current.value);
      current = current.next;
    }
  }
}

let l1 = new List();
l1.append("one");
l1.append("nami");
l1.append("arshil");

l1.display();
