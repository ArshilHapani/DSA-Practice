package timeComplexityQuestions;

public class Program1 {
    public static void func1(int arr[], int length) {
        // length = n;

        // Fragment 1

        // constant time "k1"
        int sum = 0;
        int product = 1;

        // Fragment 2
        // time = k2 * n
        for (int i = 0; i < length; i++) {
            sum += arr[i];
        }

        // Fragment 3
        // time = k3 * n
        for (int i = 0; i < length; i++) {
            product *= arr[i];
        }
        System.out.println("Sum = " + sum);
        System.out.println("Product = " + product);

        /*
         * Final time complexity
         * Tn = k1 + k2*n + k3*n (remove non dominant term K1)
         * k2*n + k3*n
         * n(k2+k3)
         * n(k4)
         * Big O(n)
         * Big O(length)
         */
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 4 };
        func1(arr, 3);
    }
}
