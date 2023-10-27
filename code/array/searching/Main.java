package searching;

class Test {
    static int binarySearch(int arr[], int element, int size) {
        int low = 0;
        int high = size - 1;
        while (low <= high) {
            int mid = (int) (low + high) / 2;
            if (arr[mid] == element) {
                return mid;
            } else if (arr[mid] < element) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5 };
        int index = binarySearch(arr, 12, 5);
        System.out.println("Element found at position " + index);
    }
}
