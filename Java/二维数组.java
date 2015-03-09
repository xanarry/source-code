import java.*;

public class ถþฮฌสýื้ {
	public static void main(String[] args) {
		System.out.println("initialize 2D array");
		int a[][] = {{1,2,3}, {4,5,6}, {7,8,9}};
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				System.out.print(a[i][j] + " ");
			}
			System.out.println();
		}
	}
}