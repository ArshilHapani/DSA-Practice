class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class List:
    def __init__(self) -> None:
        self.head = None

    def append(self, data):
        newNode = Node(data)

        if self.head == None:
            self.head = newNode
            self.head.next = self.head
        else:
            current = self.head

            while current.next != self.head:
                current = current.next

            current.next = newNode
            newNode.next = self.head

    def display(self):
        current = self.head
        while True:
            print(current.data, end="->")
            current = current.next
            if current == self.head:
                break
        print(f"HEAD({current.data})")

    def insertAtBegin(self, value):
        newNode = Node(value)
        current = self.head

        while current.next != self.head:
            current = current.next

        current.next = newNode
        newNode.next = self.head
        self.head = newNode

    def insertAtEnd(self, value):
        newNode = Node(value)
        current = self.head
        while current.next != self.head:
            current = current.next

        current.next = newNode
        newNode.next = self.head

    def insertAtSpecificIndex(self, value, index):
        newNode = Node(value)
        current = self.head
        n = 0
        while n != index-1:
            current = current.next
            n += 1

        newNode.next = current.next
        current.next = newNode

    def deleteFirstNode(self):
        current = self.head

        while current.next != self.head:
            current = current.next

        current.next = self.head.next
        self.head = self.head.next

    def deleteLastNode(self):
        current = self.head.next
        prev = self.head

        while current.next != self.head:
            current = current.next
            prev = prev.next

        prev.next = self.head

    def deleteNodeByIndex(self, index):
        current = self.head.next
        prev = self.head

        n = 0
        while n != index - 2:
            current = current.next
            prev = prev.next
            n += 1

        prev.next = current.next


L = List()
L.append(10)
L.append(20)
L.append(30)

L.insertAtBegin(5)
L.insertAtEnd(40)
L.insertAtSpecificIndex(25, 3)

L.deleteFirstNode()
L.deleteLastNode()
L.deleteNodeByIndex(3)

L.display()
