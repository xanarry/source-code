import java.util.*;

public class 矩阵每行元素之和 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input horizontal:");
		int h = in.nextInt();
		System.out.print("input ordinate:");
		int v = in.nextInt();

		int[][] a = new int[h][v];
		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < v; j++) {
				a[i][j] = (int)(Math.random() * 10);
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}

		int sum = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < v; j++) {
				sum += a[i][j];
			}
			System.out.println("sum of " + (i + 1) + " is " + sum);
			sum = 0;
		}
	}
}