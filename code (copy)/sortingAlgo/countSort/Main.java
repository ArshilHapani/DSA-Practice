package code.sortingAlgo.countSort;

public class Main {

    public static void display(int[] arr) {
        for (int num : arr) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static int maximum(int[] arr) {
        int maxNum = Integer.MIN_VALUE;
        for (int num : arr) {
            if (maxNum < num) {
                maxNum = num;
            }
        }
        return maxNum;
    }

    public static void countSort(int[] arr) {
        int maxNum = maximum(arr) + 1;
        int[] count = new int[maxNum];

        for (int num : arr) {
            count[num]++;
        }

        int i = 0;
        int j = 0;

        while (i < maxNum) {
            if (count[i] > 0) {
                arr[j] = i;
                count[i]--;
                j++;
            } else {
                i++;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = { 23, 4, 5, 22, 76, 9, 3, 4 };
        countSort(arr);
        display(arr);
    }
}
