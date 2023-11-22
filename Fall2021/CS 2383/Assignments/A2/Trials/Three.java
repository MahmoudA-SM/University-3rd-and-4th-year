public class Three {
    static int fun3(int[] a, int l, int h) {
        if (l >= h) {
            return;
        }
        int minindex = l;
        int minivalue = a[l];
        for (int i = l + 1; i <= h; i++) {
            if (minivalue > a[i]) {
                minivalue = a[i];
                minindex = i;
            }
        }
        int temp = a[l];
        a[l] = a[minindex];
        a[minindex] = temp;
        return fun3(a, l + 1, h);
    }

    public static void main(String[] args) {
        int[] a = { 3, 8, 9, 6, 9, 32, 69, 42, 91 };
        int l = 1;
        int h = 4;
        System.out.println(fun3(a, l, h));
    }
}