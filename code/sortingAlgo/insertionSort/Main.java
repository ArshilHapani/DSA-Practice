package code.sortingAlgo.insertionSort;

class Main {
    static void display(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static void insertionSort(int arr[]) {
        int key, j;
        for (int i = 1; i <= arr.length - 1; i++) {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 5, 65, 77, 344 };
        insertionSort(arr);
        display(arr);
    }
}