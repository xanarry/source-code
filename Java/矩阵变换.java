import java.*;

public class ¾ØÕó±ä»» {
	public static void main(String[] args) {
		int[][] a = new int[10][10];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = i*10 + j;
			}
		}

		System.out.println("original array");
		for (int t[] : a) {
			for (int temp : t) {
				System.out.printf("%2d ", temp);
			}
			System.out.println();
		}

		System.out.println("\nexchange array");
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < i; j++) {
				int tmp = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = tmp;
			}
		}

		for (int t[] : a) {
			for (int temp : t) {
				System.out.printf("%2d ", temp);
			}
			System.out.println();
		}
	}
}