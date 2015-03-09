import java.util.*;
public class Ñî»ÔÈı½Ç {
	public static void main(String[] args) {
		System.out.print("input how many lines:");
		Scanner in = new Scanner(System.in);
		int lines = in.nextInt();
		lines = lines + 2;
		int[][] tr = new int[lines][lines];

		for (int i = 0; i < lines; i++) {
			tr[i][i] = 1;
			tr[i][0] = 1;
		}

		for (int i = 2; i < lines; i++) {
			for (int j = 1; j < i - 1; j++) {
				tr[i][j] = tr[i - 1][j - 1] + tr[i - 1][j];
			}
		}

		for (int i = 0; i < lines; i++) {
			for (int j = 0; j < i - 1; j++) {
				System.out.printf("%4d ", tr[i][j]);
			}
			System.out.print("\n");
		}
	}
}