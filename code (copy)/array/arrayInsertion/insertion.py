def insertAtSpecificIndex(arr: list, size: int, element: int, index: int, totalSize: int) -> bool:
    if size >= totalSize:
        return False
    for i in range(size-1, index-1, -1):
        arr[i+1] = arr[i]
    arr[index] = element
    return True


def insertOnSortedArray(arr: list, size: int, element: int, totalSize: int) -> bool:
    if size >= totalSize:
        return False
    i: int = size - 1
    while i > 0 and arr[i] > element:
        arr[i+1] = arr[i]
        i -= 1
    arr[i+1] = element
    return True


myLs = [1, 3, 4, 5, None]

insertAtSpecificIndex(myLs, 4, 2, 1, 5)
print(myLs)

sortedLs = [2, 4, 8, None]

insertOnSortedArray(sortedLs, 3, 6, 4)
print(sortedLs)
