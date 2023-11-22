// 4B&C
public class RepeatNums {
    public static void repeatNums(int[] array) {
        int n = array.length;
        for (int i = 0; i < n; i++) {
            int m = array[i] % n;
            array[m] += n;
        }
        for (int i = 0; i < n; i++) {
            if (array[i] >= 2*n) {
                System.out.println(i);
            }

        }
    }
    public static void main(String[] args) {
        int[] array ={1,3,4,2,4,1,1,5,7,2,9};
        repeatNums(array);
    }
}
