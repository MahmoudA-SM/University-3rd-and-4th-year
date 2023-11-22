import java.util.Stack;

public class Four {
    public static Stack sortStack(Stack<Integer> s) {
        if (!s.isEmpty()) {
            int temp = s.pop();
            sortStack(s);
            sortNInsert(s, temp);
        }
        return s;
    }

    public static void sortNInsert(Stack<Integer> s, int temp) {
        if (s.isEmpty() || temp < s.peek()) {
            s.push(temp);
        } else {
            int temp2 = s.pop();
            sortNInsert(s, temp);
            s.push(temp2);
        }
    }

    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(7);
        s.push(50);
        s.push(18);
        s.push(1);
        s.push(23);
        s.push(17);
        s.push(90);
        s.push(12);
        System.out.println("Stack before sorting: " + s);
        sortStack(s);
        System.out.println("Stack after sorting: (Top of the stack at the end): " + s);
        // System.out.println(s.peek());
    }
}