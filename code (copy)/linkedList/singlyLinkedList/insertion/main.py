class Node:
    def __init__(self, data: int) -> None:
        self.data = data
        self.next = None


class List:
    def __init__(self) -> None:
        self.head = None

    def append(self, value: int) -> Node:
        newNode = Node(value)

        if self.head == None:
            self.head = newNode
        else:
            current = self.head

            while current.next != None:
                current = current.next
            current.next = newNode

        return newNode

    def display(self) -> None:
        current = self.head

        while current != None:
            print(current.data, end="->")
            current = current.next
        print("None")

    def insertAtBeginning(self, data: int) -> None:
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    def insertAtEnd(self, data: int) -> None:
        newNode = Node(data)
        currentNode = self.head

        while currentNode.next != None:
            currentNode = currentNode.next  # at the end it reaches at last node
        currentNode.next = newNode
        newNode.next = None

    def insertAtSpecificIndex(self, data: int, index: int) -> None:
        newNode = Node(data)
        currentNode = self.head
        i: int = 0

        while i != index-1:
            currentNode = currentNode.next
            i += 1

        newNode.next = currentNode.next
        currentNode.next = newNode

    def insertAfterSpecificNode(self, data: int, node: Node) -> None:
        newNode = Node(data)
        newNode.next = node.next
        node.next = newNode


l = List()

n = l.append(10)
l.append(20)
l.append(30)
l.insertAtBeginning(5)
l.insertAtEnd(40)
l.insertAtSpecificIndex(25, 3)
l.insertAfterSpecificNode(15, n)

l.display()
