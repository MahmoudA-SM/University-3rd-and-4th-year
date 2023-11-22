import org.w3c.dom.Node;

public class two {
    int count = 0;

    public static void findAllInRange(Node n, int k1, int k2) {

        if (n == null) {
            return;
        }

        if (k1 < n.data) {
            findAllInRange(n.left, k1, k2);
        }
        if (k1 <= n.data && k2 >= n.data) {
            System.out.print(n.data + " ");
            count++;
        }

        if (k2 > n.data) {

            findAllInRange(n.right, k1, k2);

        }

    }

    public static void findAllInRange(int k1, int k2) {
        Node root;
        findAllInRange(root, k1, k2);

    }
}