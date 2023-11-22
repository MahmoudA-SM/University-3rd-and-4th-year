import java.util.Scanner;

public class six {

    static int par(int[] array, int b, int m) {

        int pivot = array[m];
        int i = (b - 1);

        for (int j = b; j <= m - 1; j++) {

            if (array[j] < pivot) {
                i++;
                swap(array, i, j);
            }
        }
        swap(array, i + 1, m);
        return (i + 1);
    }

    static void swap(int[] array, int i, int j) {
        int tint = array[i];
        array[i] = array[j];
        array[j] = tint;
    }

    static void qs(int[] array, int b, int m) {
        if (b < m) {

            int v = par(array, b, m);

            qs(array, b, v - 1);
            qs(array, v + 1, m);
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("How many integers do you want to put it?");
        int len = scan.nextInt();

        int[] array = new int[len];
        System.out.println("Begin entering numbers:");
        for (int i = 0; i < len; i++) {
            array[i] = scan.nextInt();
        }
        qs(array, 0, len - 1);
        System.out.println("Array after sorting: ");
        for (int i = 0; i < len; i++)
            System.out.print(array[i] + " ");
        scan.close();
    }
}
