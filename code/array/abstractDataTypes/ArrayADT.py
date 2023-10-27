class ArrayADT:
    myArray = list()

    def __init__(self, totalSize: int, usedSize: int) -> None:
        self.totalSize = totalSize
        self.usedSize = usedSize
        self.myArray = usedSize*[None]

    def show(self):
        for i in range(self.usedSize):
            print(self.myArray[i])

    def insert(self):
        for i in range(self.usedSize):
            val = int(input(f"Enter value {i} "))
            self.myArray[i] = val


Ins = ArrayADT(10, 3)
Ins.insert()
Ins.show()
