def binarySearch(arr: list, element: int, size: int) -> int:
    low = 0
    high = size - 1

    while low <= high:
        temp = (low+high)/2
        mid = int(temp)
        if arr[mid] == element:
            return mid
        if arr[mid] < element:
            low = mid + 1
        else:
            high = mid - 1

    return -1


sortedList = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
element = 0
size = 10

index = binarySearch(sortedList, element, size)
print(sortedList)
print(f"{element} found at index {index}")
