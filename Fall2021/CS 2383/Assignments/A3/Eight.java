public class Eight {

	public void goThruHeap(int array[], int n, int ind) {
		int current = ind;
		int currentright = 2 * ind + 2;
		int currentleft = 2 * ind + 1;

		if (currentleft < n && array[currentleft] > array[current]) {
			current = currentleft;
		}

		if (currentright < n && array[currentright] > array[current]) {
			current = currentright;
		}

		if (current != ind) {
			int temp = array[ind];
			array[ind] = array[current];
			array[current] = temp;

			goThruHeap(array, n, current);
		}
	}

	public void hSort(int array[], int n) {
		for (int ind = (n / 2) - 1; ind >= 0; ind--) {
			goThruHeap(array, n, ind);
		}

		// Swap root and last node, remove the last node, then do Downheap to sort
		for (int ind = n - 1; ind >= 0; ind--) {
			int temp = array[0];
			array[0] = array[ind];
			array[ind] = temp;

			goThruHeap(array, ind, 0);
		}
	}

	public static void main(String[] args) {
		int atoSort[] = { 1, 18, 50, 100, 85, 17, 43, 82, -2, 502 };
		int length = atoSort.length;

		Eight h = new Eight();

		System.out.println("Before Sorting:");
		for (int i = 0; i < length; i++) {
			System.out.print(atoSort[i] + " ");
		}
		System.out.print("\n");

		h.hSort(atoSort, length);

		System.out.println("After Sorting:");
		for (int i = 0; i < length; i++) {
			System.out.print(atoSort[i] + " ");
		}
		System.out.print("\n");
	}
}