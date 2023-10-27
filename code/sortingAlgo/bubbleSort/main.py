from pandas import read_csv


def bubbleSort(arr: list()) -> list:
    length = len(arr)
    for i in range(length-1):
        for j in range(length-i-1):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp

    return arr


unsortedList = [3, 2, 6, 4, 1]
sorted_array = bubbleSort(unsortedList)

for element in sorted_array:
    print(element, end=" , ")

print()


data = read_csv("./MetroPT3(AirCompressor).csv")
print(data)
