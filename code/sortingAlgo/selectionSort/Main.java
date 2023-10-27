package code.sortingAlgo.selectionSort;

class Main {
    static void display(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static void selectionSort(int arr[]) {
        int minIndex, temp;
        for (int i = 1; i <= arr.length - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 5, 65, 77, 344 };
        selectionSort(arr);
        display(arr);
    }
}