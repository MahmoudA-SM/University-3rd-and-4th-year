import java.util.Random;

class Solution {
    // public int fKL(int[] array, int k) {

    // if (array.length == 1) {
    // return array[0];
    // }
    // return sR(array, 0, array.length - 1, k);
    // }

    // private int sR(int[] array, int start, int end, int k) {

    // int ind = rP(array, start, end);
    // if (ind == (k - 1)) {
    // return array[ind];
    // } else if (ind >= k) {
    // return sR(array, start, ind - 1, k);
    // } else {

    // return sR(array, ind + 1, end, k);
    // }
    // }

    private int rP(int[] array, int start, int end) {
        int rI = gRI(start, end);
        exchange(array, rI, end);

        int piv = array[end];
        int pointer = start - 1;
        for (int i = start; i < end; i++) {
            if (array[i] >= piv) {
                pointer++;
                exchange(array, i, pointer);
            }
        }
        exchange(array, pointer + 1, end);
        return pointer + 1;
    }

    // private int gRI(int min, int max) {
    // Random r = new Random();
    // int lim = ((max - min) + 1);
    // return r.nextInt(lim) + min;
    // }

    // private void exchange(int[] array, int ind1, int ind2) {
    // int temp = array[ind1];
    // array[ind1] = array[ind2];
    // array[ind2] = temp;
    // }

}

public class five {

    // Driver method to test above
    public static void main(String args[]) {
        Solution ob = new Solution();
        int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
        int n = arr.length, k = 3;
        System.out.println("K'th largest element is " + ob.fKL(arr, k));
    }
}