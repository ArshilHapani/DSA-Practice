package arrayInsertion;

class Insertion {
    static void display(int arr[], int size) {
        // Traversal
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static boolean insertionAtIndex(int arr[], int size, int element, int totalSize, int index) {
        if (size >= totalSize) {
            return false;
        }
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return true;
    }

    static boolean insertOnSortedArray(int arr[], int size, int element, int totalSize) {
        if (size >= totalSize) {
            return false;
        }
        int i = size - 1;
        while (i > 0 && arr[i] > element) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = element;
        return true;
    }

    public static void main(String[] args) {
        int arr[] = new int[10];
        arr[0] = 3;
        arr[1] = 4;
        arr[2] = 2;
        int size = 3;
        System.out.println("Before insertion");
        display(arr, size);
        insertionAtIndex(arr, size, 10, 10, 2);
        size += 1;
        System.out.println("Inserting element 10 at index 2");
        display(arr, size);

        int newArr[] = new int[10];
        newArr[0] = 3;
        newArr[1] = 5;
        newArr[2] = 7;
        insertOnSortedArray(newArr, 3, 4, 10);
        display(newArr, 4);
    }
}