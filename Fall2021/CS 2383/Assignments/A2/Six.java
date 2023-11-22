public class Six {
    static void iSRecursion(int A[], int n) {

        if (n < 2) {
            return;
        }

        iSRecursion(A, n - 1);

        int last = A[n - 1];
        int i = n - 2;

        for (i = n - 2; i >= 0 && A[i] > last; i--) {
            A[i + 1] = A[i];
        }

        A[i + 1] = last;
    }

    public static void main(String[] args) {
        int A[] = { 5, 4, 3 };
        iSRecursion(A, A.length);

        for (int i = 0; i < A.length; i++) {
            System.out.print(A[i] + " ");
        }

        System.out.println();
    }
}
