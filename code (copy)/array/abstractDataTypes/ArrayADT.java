package abstractDataTypes;

import java.util.Scanner;

class ArrayADT {
    public static void main(String[] args) {
        ArrayAbstraction abs = new ArrayAbstraction(10, 3);
        abs.setValue();
        System.out.println("Values");
        abs.showInfo();
    }
}

class ArrayAbstraction {
    int total_size;
    int used_size;
    int local_array[];

    ArrayAbstraction(int size, int usedSize) {
        this.total_size = size;
        this.used_size = usedSize;
        this.local_array = new int[this.total_size];
    }

    void showInfo() {
        for (int i = 0; i < used_size; i++) {
            System.out.println(local_array[i]);
        }
    }

    void setValue() {
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < used_size; i++) {
            System.out.print("Enter element " + i + ": ");
            local_array[i] = sc.nextInt();
        }
        sc.close();
    }
}