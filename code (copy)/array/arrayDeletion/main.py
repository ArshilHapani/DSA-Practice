def insertAtSpecificIndex(arr: list, size: int, index: int) -> None:
    for i in range(index, size):
        arr[i] = arr[i+1]


myLs = [1, 3, 4, 5, None]

insertAtSpecificIndex(myLs, 4, 2)
print(myLs)
