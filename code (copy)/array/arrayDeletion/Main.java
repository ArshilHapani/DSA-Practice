package arrayDeletion;

class Insertion {
    static void display(int arr[], int size) {
        // Traversal
        for (int i = 0; i < size; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static boolean deletionAtIndex(int arr[], int size, int index) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        return true;
    }

    public static void main(String[] args) {
        int arr[] = new int[10];
        arr[0] = 3;
        arr[1] = 4;
        arr[2] = 2;
        int size = 3;
        System.out.println("Before deletion");
        display(arr, size);
        deletionAtIndex(arr, size, 1);
        size -= 1;
        System.out.println("Deleting element from index 2");
        display(arr, size);
    }
}