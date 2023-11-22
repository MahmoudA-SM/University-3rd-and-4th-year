// public class 5bk {
// private static int numReverse = 0;
// private static int startPosition = 1;

// public static int reverse(int num) {
// if (num > 0) {
// reverse(num / 10);
// numReverse += (num % 10) * startPosition;
// startPosition *= 10;
// }
// return numReverse;

// }

// public static boolean palindrome(int w) {
// int rw = 0;
// rw = reverse(w);
// // if (w == rw) {
// // return true;
// // } else {
// // return false;
// // }
// return w == rw;
// }

// // Driver Code
// public static void main(String[] args) {
// int num = 2112;

// System.out.println(reverse(num));
// if (palindrome(num) == true) {
// System.out.println("Palindrome");
// } else {
// System.out.println("Not Palindrome");
// }
// System.out.println();
// }
// }
// _________________________________________________________________________________