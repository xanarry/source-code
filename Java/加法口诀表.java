import java.util.*;

public class 加法口诀表 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("input max:");
		int n = in.nextInt();

		System.out.print(" + ");
		for (int i = 1; i <= n; i++) {
			System.out.printf("%2d ", i);
		}
		
		System.out.print("\n");
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < i+1; j++) {
				System.out.printf("%2d ", i + j);
			}
			System.out.print("\n");
		}
	}
}