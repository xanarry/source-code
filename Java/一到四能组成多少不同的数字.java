public class 一到四能组成多少不同的数字 {
	public static void main(String[] args) {
		int count = 0;
		for (int a = 1; a <= 4; a++) {
			for (int b = 1; b <= 4; b++) {
				for (int c = 1; c <= 4; c++) {
					for (int d = 1; d <= 4; d++) {
						if ((a != b) && (b != c) && (c != d) && (a != d)) {
							count++;
							System.out.printf("%d%d%d%d\n", a, b, c, d);
						}
					}
				}
			}
		}
		System.out.println(count);
	}
}