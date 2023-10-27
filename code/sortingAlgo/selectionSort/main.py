

def selectionSort(arr: list()) -> list:
    length = len(arr)
    for i in range(length-1):
        min = arr[i]
        pos = i
        # for most programming language it start from i+1 but in range function it is 'i' as i starts from 1
        for j in range(i, length):
            if arr[j] < min:
                min = arr[j]
                pos = j

        temp = arr[i]
        arr[i] = arr[pos]
        arr[pos] = temp

    return arr


unsortedList = [3, 2, 6, 4, 1]
sorted_array = selectionSort(unsortedList)

for element in sorted_array:
    print(element, end=" , ")

print()
