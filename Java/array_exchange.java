import java.util.*;
public class array_exchange{
	public static void main(String[] args) {
		int[][] a = new int[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				a[i][j] = (i + 1) * (j + 1);
			}
		}

		String t = Arrays.deepToString(a);
		System.out.println(t);

		System.out.println("\noriginal array");
		for (int tmp[] : a) {
			for (int i : tmp) {
				System.out.print(i + " ");
			}
			System.out.println();
		}

		//exchange array
		int[] temp = new int[3];
		temp = a[0];
		a[0] = a[2];
		a[2] = temp;

		System.out.println("\nafter exchange:");
		for (int tmp[] : a) {
			for (int i : tmp) {
				System.out.print(i + " ");
			}
			System.out.println();
		}


		int[] x = {1, 2, 3, 4, 5};
		System.out.println(Arrays.toString(x));
		int[] y = x;
		System.out.println(Arrays.toString(y));
	}
}