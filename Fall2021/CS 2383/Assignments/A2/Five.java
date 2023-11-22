public class Five {
	public static int reverse(int n, int rev) {
		if (n == 0) {
			return rev;
		}
		rev = rev * 10 + (n % 10);
		rev = reverse(n / 10, rev);
		return rev;
	}

	public static String palindrome(int w) {
		int rw = 0;
		rw = reverse(w, rw);

		if (w == rw) {
			return "Palindrome";
		}
		return "Not Palindrome";

	}

	public static void main(String[] args) {
		int n = 2112;
		int rev = 0;
		System.out.println(reverse(n, rev));
		System.out.println(palindrome(n));
	}
}