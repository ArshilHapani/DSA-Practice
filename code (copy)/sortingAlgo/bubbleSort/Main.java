package code.sortingAlgo.bubbleSort;

class Main {
    static void display(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    static void bubbleSort(int arr[]) {
        int temp;
        boolean isSorted = false;
        for (int i = 0; i < arr.length - 1; i++) {
            isSorted = true;
            System.out.println("Working on pass " + (i + (int) 1));
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    isSorted = false;
                }
            }

            if (isSorted) {
                return;
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 5, 65, 77, 344 };
        // int arr[] = { 1, 34, 64, 56, 23, 56, 24 };
        bubbleSort(arr);
        display(arr);
    }
}