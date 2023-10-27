package code.sortingAlgo.quickSort;

class QuickSort {
    public static void display(int[] arr) {
        for (int value : arr) {
            System.out.print(value + "  ");
        }
        System.out.println();
    }

    public static int partition(int[] arr, int low, int high) {
        int pivot = arr[low];
        int i = low + 1, j = high; // tracking value of i and j
        int temp;
        while (i <= j) {
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            while (i <= j && arr[j] > pivot) {
                j--;
            }
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
    }

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int partitionIndex = partition(arr, low, high);
            quickSort(arr, low, partitionIndex - 1); // sorting left part of array
            quickSort(arr, partitionIndex + 1, high); // sorting right part of array
        }
    }

    public static void main(String[] args) {
        int[] arr = { 1, 56, 4, 5, 7, 4, 8, 10 };
        int length = arr.length;
        display(arr);
        quickSort(arr, 0, length - 1);
        display(arr);
    }
}
