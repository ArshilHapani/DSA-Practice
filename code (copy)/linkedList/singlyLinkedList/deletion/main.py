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

    def display(self):
        current = self.head

        while current != None:
            print(current.data, end="->")
            current = current.next
        print("None")

    def deleteFirstNode(self):
        temp = self.head.next
        self.head = temp
        del temp

    def deleteLastNode(self):
        current = self.head.next
        prev = self.head

        while current.next != None:
            current = current.next
            prev = prev.next

        prev.next = None
        del current

    def deleteNodeByValue(self, val: int):
        current = self.head.next
        prev = self.head

        while current.data != val:
            current = current.next
            prev = prev.next
            if current.next == None:
                print("No value found in list")
                return

        prev.next = current.next
        del current, val

    def deleteNodeByIndex(self, index: int):
        current = self.head.next
        prev = self.head
        n: int = 1
        while n != index-1:
            current = current.next
            prev = prev.next
            n += 1

        prev.next = current.next
        del current, index, n

    def deleteNodeByNode(self, node: Node):
        current = self.head.next
        prev = self.head

        while current != node:
            current = current.next
            prev = prev.next

        prev.next = node.next
        del node, current


l = List()

l.append(10)
l.append(20)
l.append(30)
l.append(40)
l.append(50)
n = l.append(60)
l.append(70)

l.deleteFirstNode()
l.deleteLastNode()
l.deleteNodeByValue(40)
l.deleteNodeByIndex(3)
l.deleteNodeByNode(n)

l.display()
