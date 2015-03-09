import java.util.*;
//oj题
public class 多重集 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int n1 = in.nextInt();
		int[][] a = new int[n1][];

		for (int i = 0; i < n1; i++) {
			int len = in.nextInt();
			a[i] = new int[len];
			for (int j = 0; j < len; j++) {
				a[i][j] = in.nextInt();
			}
		}

		int n2 = in.nextInt();
		int[] input = new int[2];

		int count = 0;

		for (int i = 0; i < n2; i++) {
			for (int j = 0; j < 2; j++) {
				input[j] = in.nextInt();
			}

			if (input[1] == input[0]) {
				for (int k = 0; k < a.length; k++) {
					count = 0;
					for (int l = 0; l < a[k].length; l++) {
						if (input[0] == a[k][l]) {
							count++;
							if (count == 2) {
								System.out.println("Y");
								break;
							}
						}
					}
				}

				if (count < 2)
					System.out.println("N");
			}
			

			else {
				for (int h = 0; h < a.length; h++) {
					count = 0;
					for (int k = 0; k < 2; k++) {
						for (int l = 0; l < a[h].length; l++) {
							if (input[k] == a[h][l]) {
								count++;
								break;
							}
						}
					}
					if (count == 2) {
						System.out.println("Y");
						break;
					}
				}
				if (count < 2) {
					System.out.println("N");
				}
			}
		}
	}
}