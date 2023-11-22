public class trials {
    public static void main(String[] args) {
        int s = 0;
        int[] a = {1,4,2,1,4,4,1,22,3,5,1,3,1};
        int p;
        for (int i = 0; i <= a.length-1; i++) {
            for (int j = i ; j < a.length-1; j++) {
                p = 1;
                for (int k = i; k < j; k++) {
                    p = p * a[k];
                }
                s = s+p;
            }
        }
        System.out.println(s);
    }
}
