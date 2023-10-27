class Node:
    def __init__(self, value: int) -> None:
        self.value = value
        self.next = None


class List:
    def __init__(self) -> None:
        self.head = None

    def append(self, value: int) -> None:
        newNode = Node(value)
        if not self.head:
            self.head = newNode
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = newNode

    def display(self) -> None:
        current = self.head

        while current:
            print(current.value, end="->")
            current = current.next
        print("null")


l1 = List()

l1.append(1)
l1.append(2)
l1.append(3)

l1.display()
