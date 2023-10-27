class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self) -> None:
        self.head = None

    def appendAtBeginning(self, data):
        if self.head == None:
            self.head = Node(data)
        else:
            raise Exception("Head is already defined")

    def append(self, data):
        if self.head == None:
            self.appendAtBeginning(data)
        else:
            newNode = Node(data)
            current: Node = self.head
            while current.next != None:
                current = current.next

            current.next = newNode

    def display(self) -> None:
        current: Node = self.head

        while current:
            print(current.data, end="->")
            current = current.next
        print("null")

    def swapFirstAndLastNode(self):
        if not self.head or not self.head.next:
            raise Exception("Single head so can't swap nodes")

        current = self.head
        prev = None

        while current.next:
            prev = current
            current = current.next

        current.next = self.head.next
        prev.next = self.head
        self.head = current

    def insertInOrder(self, data):
        current = self.head
        if data < current.data:
            self.appendAtBeginning(data)
        else:
            newNode = Node(data)
            while current:
                if current.next == None and current.data < data:
                    self.append(data)
                    break

                if current.data < data and current.next.data > data:
                    newNode.next = current.next
                    current.next = newNode

                current = current.next


if __name__ == "__main__":
    l = LinkedList()
    l.append(10)
    l.append(20)
    l.append(30)
    l.insertInOrder(10)

    l.display()
