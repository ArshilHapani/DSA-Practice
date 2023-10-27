def insertionSort(arr: list()) -> list:
    length = len(arr)
    for i in range(1, length):
        key = arr[i]
        j = i - 1

        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1

        arr[j + 1] = key

    return arr


unsortedList = [3, 2, 6, 4, 1]
sorted_array = insertionSort(unsortedList)

for element in sorted_array:
    print(element, end=" , ")
print()

if True:
    raise ModuleNotFoundError("Zoro is not found")
