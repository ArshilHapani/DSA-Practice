class PQueue:
    def __init__(self) -> None:
        self.elements = []

    def enqueue(self, element, priority: int):
        self.elements.append((priority, element))
        # sort in descending order on the base of the priority
        self.elements.sort(reverse=True)

    def is_empty(self) -> bool:
        return len(self.elements) == 0

    def dequeue(self):
        if not self.is_empty():
            return self.elements.pop()[1]


pq = PQueue()

pq.enqueue(1, 10)
pq.enqueue(2, 5)
pq.enqueue(3, 2)

while not pq.is_empty():
    print(pq.dequeue())
