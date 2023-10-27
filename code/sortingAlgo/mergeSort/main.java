
class MergeSort {

    public static void display(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void merge(int[] arr, int low, int mid, int high) {
        int i, j, k;
        i = low;
        j = mid + 1;
        k = low;
        int[] b = new int[50];

        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                b[k] = arr[i];
                i++;
                k++;
            } else {
                b[k] = arr[j];
                k++;
                j++;
            }
        }
        while (i <= mid) {
            b[k] = arr[i];
            i++;
            k++;
        }
        while (j <= high) {
            b[k] = arr[j];
            j++;
            k++;
        }

        for (int idx = low; idx <= high; idx++) {
            arr[idx] = b[idx - low];
        }
    }

    public static void mergeSort(int[] arr, int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    public static void main(String[] args) {
        int[] arr = { 23, 4, 5, 22, 76, 9, 3 };
        int length = arr.length;
        System.out.println("length is " + length);
        mergeSort(arr, 0, length - 1);
        display(arr);
    }
}
