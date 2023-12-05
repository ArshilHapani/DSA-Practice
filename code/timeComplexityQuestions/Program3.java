package timeComplexityQuestions;

public class Program3 {
    public static int myFunc(int n) {
        if (n <= 0) {
            return 0;
        } else {
            int i = (int) Math.random();
            System.out.println("this" + i);
            return myFunc(i) + myFunc(n - 1 - i);
        }
    }

    public static void main(String[] args) {
        System.out.println(myFunc(10));
    }
}
