public class palindrome {
    public static String isPalindrome(String stringToCheck) {
        int length = stringToCheck.length();
        if (length == 0)
            return "Yes";

        return isPalindromeRecrusive(stringToCheck, 0, length - 1);
    }

    public static String isPalindromeRecrusive(String stringToCheck,
            int startingIndex, int endingIndex) {
        if (startingIndex == endingIndex) {
            return "Yes";
        }
        if ((stringToCheck.charAt(startingIndex)) != (stringToCheck.charAt(endingIndex))) {
            return "No";
        }
        if (startingIndex < endingIndex + 1) {
            return isPalindromeRecrusive(stringToCheck, startingIndex + 1, endingIndex - 1);
        }

        return "Yes";
    }

    public static void main(String args[]) {
        String check = "Egypt";

        System.out.println(isPalindrome(check));
    }

}
